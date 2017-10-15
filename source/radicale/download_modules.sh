#!/bin/sh

# Radicale for Synology DSM
#
# Copyright (C) 2017 Thomas Himmelstoss
#
# This software may be freely distributed under the MIT license. You should
# have received a copy of the MIT License along with this program.

MODULE_TARGET="$(dirname $0)/modules"

mkdir -p "${MODULE_TARGET}"

pip install "--target=${MODULE_TARGET}" "radicale==2.1.8"

