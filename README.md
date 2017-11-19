synopkg-radicale
================

Packaging of Radicale for Synology DSM

Setup
-----

Perform the steps described by the [Syonolgy Developer Documentation.](https://developer.synology.com/developer-guide/create_package/prepare.html)

The basic steps are:

1. Create a build directory.
2. Change to the new directory.
3. Clone the Synology packaging scripts:

   `git clone https://github.com/SynologyOpenSource/pkgscripts-ng.git pkgscripts-ng`

4. Create your build environment, e. g.:

   `./pkgscripts/EnvDeploy -v 6.0 -p armadaxp`

5. Clone this project:

   `git clone https://github.com/tfkhim/synopkg-radicale.git source/radicale`

Build the package
-----------------

Execute the following command

```
./pkgscripts/PkgCreate -c radicale
```

