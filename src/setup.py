#!python3

# Radicale for Synology DSM
#
# Copyright (C) 2017 Thomas Himmelstoss
#
# This software may be freely distributed under the MIT license. You should
# have received a copy of the MIT License along with this program.

import os
from setuptools import setup, find_packages

radicalePamAuthVersion = os.environ["RADICALE_PAM_AUTH_VERSION"]
radicaleVersion = os.environ["RADICALE_VERSION"]

setup(
    name="radicale_pam_auth",
    version=radicalePamAuthVersion,
    description="A Radical authentication plugin using the linux PAM library",
    py_modules=["radicale_pam_auth"],
    packages=find_packages(),
    install_requires=["radicale=={}".format(radicaleVersion)],
)

