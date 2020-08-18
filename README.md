synopkg-radicale
================

Packaging of Radicale for Synology DSM.

General Information
-------------------

The build process downloads Radicale and all its dependencies
as a set of Wheel packages. The DSM installation scripts then
create a virtualenv into which these packages will be installed.

This package also adds an authentication plugin to Radicale which
uses PAM as its backend. Therefore all users added by the Synology
web interface are also able to log into the Radicale server. The
plugin source is located in the ./src directory. It consists of
two parts: a Python authentication plugin and a small C program
which performs the actual PAM authentication using libpam. PAM
requires the process to run as root or a member of the shadow
group. The helper program is installed as root with the SUID
flag and therefore fulfills this requirement. Due to this
setup it is possible to run the Radicale server as a regular
user and still use PAM for authentication.

Setup
-----

Perform the steps described by the [Syonolgy Developer Documentation.](https://help.synology.com/developer-guide/create_package/prepare.html)

The basic steps are:

1. Create a build directory.
2. Change to the new directory.
3. Clone the Synology packaging scripts:

   ```
   git clone https://github.com/SynologyOpenSource/pkgscripts-ng.git pkgscripts-ng
   ```

4. Create your build environment, e. g.:

   ```
   ./pkgscripts/EnvDeploy -v 6.2 -p armadaxp
   ```

5. Import your private key into the build environment

   ```
   cd build_env/ds.armadaxp-6.2/
   chroot .
   gpg --import /tmp/your_signing_key.asc
   ```

6. Clone this project:

   ```
   git clone https://github.com/tfkhim/synopkg-radicale.git source/radicale
   ```

Build the package
-----------------

Execute the following command

```
./pkgscripts-ng/PkgCreate.py -c radicale
```

The created .spk file is located in the result_spk directory contained in the
build directory.

