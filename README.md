# synopkg-radicale
Packaging of Radicale for Synology DSM

Setup
-----

Create a build directory. Change to the new directory.

Clone the Synology packaging scripts:

git clone https://github.com/SynologyOpenSource/pkgscripts-ng.git pkgscripts-ng

Create your build environment, e. g.:

./pkgscripts/EnvDeploy -v 6.0 -p armadaxp

Follow the further documentation on the Syonolgy website.

Clone this project:

git clone https://github.com/tfkhim/synopkg-radicale.git source/radicale

Build the package

./pkgscripts/PkgCreate radicale
