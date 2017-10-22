/*
 * Radicale for Synology DSM
 *
 * Copyright (C) 2017 Thomas Himmelstoss
 *
 * This software may be freely distributed under the MIT license. You should
 * have received a copy of the MIT License along with this program.
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <security/pam_appl.h>

int simple_conv(int num_msg,
                const struct pam_message **msg,
                struct pam_response **response,
                void *data) {

    if (num_msg <= 0 || num_msg > PAM_MAX_NUM_MSG) {
        return PAM_CONV_ERR;
    }

    typedef struct pam_response* response_ptr;
    response_ptr aresp = calloc(num_msg, sizeof(response_ptr));
    if (aresp == NULL) {
        return PAM_BUF_ERR;
    }

    const char* password = (const char*) data;
    for (int i = 0; i < num_msg; i++) {
        aresp[i].resp_retcode = 0;
        aresp[i].resp = NULL;
        if (msg[i]->msg_style == PAM_PROMPT_ECHO_OFF) {
            aresp[i].resp = strdup(password);
            if (aresp[i].resp == NULL) {
                goto fail;
            }
        }
    }

    *response = aresp;
    return PAM_SUCCESS;

fail:
    for (int i = 0; i < num_msg; i++) {
        if (aresp[i].resp != NULL) {
            memset(aresp[i].resp, 0, strlen(aresp[i].resp));
            free(aresp[i].resp);
        }
    }

    memset(aresp, 0, num_msg*sizeof(*aresp));
    *response = NULL;
    return PAM_CONV_ERR;
}

int main(int argc, const char* argv[]) {
    if (argc < 2) {
        printf("Error: The user name must be given as first argument\n");
        return 1;
    }

    char password[PAM_MAX_RESP_SIZE];
    if (fgets(password, sizeof(password), stdin) == NULL) {
        printf("Error: Could not read password from stdin");
        return 1;
    }

    const struct pam_conv pam_conversation = {&simple_conv, (void*)password};

    pam_handle_t* handle = NULL;
    int status = pam_start("login", argv[1], &pam_conversation, &handle);

    if (status != PAM_SUCCESS) {
        printf("Error: Could not start transaction\n");
        pam_end(handle, status);
        return 1;
    }

    status = pam_authenticate(handle, 0);

    if (status == PAM_SUCCESS) {
        printf("Authentication successful\n");
    } else {
        printf("Error: Authentication failed\n");
    }

    if (pam_end(handle, status) != PAM_SUCCESS) {
        printf("Error: Could not close transaction\n");
	return 1;
    }

    return (status == PAM_SUCCESS ? 0 : 1);
}

