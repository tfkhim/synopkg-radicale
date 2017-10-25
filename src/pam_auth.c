/*
 * Radicale for Synology DSM
 *
 * Copyright (C) 2017 Thomas Himmelstoss
 *
 * This software may be freely distributed under the MIT license. You should
 * have received a copy of the MIT License along with this program.
 *
 */

#include <security/pam_appl.h>
#include <security/pam_misc.h>

int main(int argc, const char* argv[]) {
    if (argc < 2) {
        printf("Error: The user name must be given as first argument\n");
        return 1;
    }

    const struct pam_conv pam_conversation = {misc_conv, NULL};

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

