#!python3

# Radicale for Synology DSM
#
# Copyright (C) 2017 Thomas Himmelstoss
#
# This software may be freely distributed under the MIT license. You should
# have received a copy of the MIT License along with this program.

import radicale.auth as auth
import subprocess

class Auth(auth.BaseAuth):
    def is_authenticated(self, user, password):
        if not self.configuration.has_option("auth", "cmd"):
            self.logger.error("Configuration option auth.cmd not set")
            return False

        cmd = self.configuration.get("auth", "cmd")

        with subprocess.Popen([cmd, user], stdin=subprocess.PIPE) as proc:
            proc.communicate(password.encode("utf-8"));

        return proc.returncode == 0

