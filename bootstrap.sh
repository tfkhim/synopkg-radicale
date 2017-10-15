#!/bin/sh

# Radicale for Synology DSM
#
# Copyright (C) 2017 Thomas Himmelstoss
#
# This software may be freely distributed under the MIT license. You should
# have received a copy of the MIT License along with this program.

git clone https://github.com/SynologyOpenSource/pkgscripts-ng.git pkgscripts-ng

${PWD}/pkgscripts/EnvDeploy -v 6.0 -p armadaxp

${PWD}/source/radicale/download_modules.sh

echo "INSTALL A VALID GPG KEY"

