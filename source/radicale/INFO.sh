#!/bin/bash

# Radicale for Synology DSM
#
# Copyright (C) 2017 Thomas Himmelstoss
#
# This software may be freely distributed under the MIT license. You should
# have received a copy of the MIT License along with this program.

source /pkgscripts/include/pkg_util.sh

package="radicale"
version="1.0.0"
displayname="Radicale"
maintainer="Thomas Himmelstoss"
arch="$(pkg_get_unified_platform)"
description="CardDAV and CalDAV server implemented in Python"

[ "$(caller)" != "0 NULL" ] && return 0
pkg_dump_info

