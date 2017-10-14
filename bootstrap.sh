#!/bin/sh

git clone https://github.com/SynologyOpenSource/pkgscripts-ng.git pkgscripts-ng

${PWD}/pkgscripts/EnvDeploy -v 6.0 -p armadaxp

MODULE_TARGET="${PWD}/source/radicale/modules"

pip install "--target=${MODULE_TARGET}" radicale

echo "INSTALL A VALID GPG KEY"
