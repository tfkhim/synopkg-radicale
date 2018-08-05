synopkg-radicale
================

Packaging of Radicale for Synology DSM

Setup
-----

Perform the steps described by the [Syonolgy Developer Documentation.](https://originhelp.synology.com/developer-guide/create_package/prepare.html)

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

