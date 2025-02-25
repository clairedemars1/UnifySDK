# Unify Build Guide

This document is intended for systems integrators who are trying to cross-compile the Unify components. This guide explains how to build Debian packages for the Raspberry Pi.

For a list of build dependencies please refer to the [Dockerfile](../docker/Dockerfile)

## Build Instructions

The Unify Host SDK uses a docker container to provide an appropriate build environment.
As a prerequisite docker must be installed on the build host. See
[readme.md](../docker/readme_developer.md) for information about how to install
docker and build the Unify Host SDK environment.

During the build, the CMake build system will fetch additional required dependencies
online.

### Getting the source

There are two ways to obtain the Unify source code, the simplest way is
to download it from the [GitHub release assets](https://github.com/SiliconLabs/UnifySDK/releases).
Alternatively, the source code repository can be cloned using git. Note that
git clients need to have _git-lfs_ support.

```bash
git@github.com:SiliconLabs/UnifySDK.git
```

### Cross Compiling for Raspberry Pi Using Docker

> The Raspberry Pi build is supported by Raspberry Pi OS Buster.

To start a Docker container with a pre-configured build system, run the
following command from the root of the Unify source directory

```bash
docker run -it --rm \
  -v`pwd`:`pwd` \
  -w `pwd` \
  uic_armhf
```

Once the Docker container is started, a new prompt will be shown. Building
binaries and Debian packages is done as follows:

```bash
mkdir build
cd build
cmake -GNinja -DCMAKE_TOOLCHAIN_FILE=../cmake/armhf_debian.cmake ..
ninja               # Build binaries
ninja deb           # Build Debian Installers (optional)
```

After running this, the `zpc` binary is located in `./applications/zpc/zpc`. The
Debian installer path are directly in the build folder
`./uic-<component>_<version>_armhf.deb` and `./libuic_<version>_armhf.deb`

### Disabling the build of a Unify Application

To disable build for various applications in Unify build, CMake environment can be
set to OFF for that application while running CMAKE in
cmake/include/build_permutations.cmake file

This can also be achieved by passing those variables on the command line with CMAKE

For e.g. to disable build for ZigPC following command can be used.

```bash
 cmake -GNinja -DBUILD_ZIGPC=OFF ..
```

### Advanced Feature - Run Raspberry Pi Unit Tests in Docker on the Host

When cross compiling the Unify, the unit tests are build for the target platform ie
`armhf`. Using QEMU it is possible to run those binaries directly within Docker on the
Host machine.

To enable running the unit tests inside Docker on the Host machine, run the
following command in the Host (not within the docker container).

``` bash
docker run --user 0 --privileged --rm -it uic_armhf update-binfmts --enable
```

> NB: This command needs to be run once after each restart of the Host machine.

After enabling this, unit tests can be run by issuing the following command in
the `uic_armhf` docker image in the build directory:

```bash
ninja test
ninja cargo_test
```

## Porting the Unify Host SDK

Porting the Unify SDK to a new platform using Debian Linux should be straightforward.
However, if components are ported to other Linux distributions it may
be necessary to update the startup scripts of the components. The Debian
packages provided with the Unify Host SDK all use the system service `systemd` which
takes care of startup and shutdown of the components. For example, the file
[uic-zpc.service](../applications/zpc/scripts/systemd/uic-zpc.service) is as
systemd config script. When porting to a new Linux system the systemd config
files should be used for reference. It is very important that all the Unify
components runs as a dedicated system user to prevent attackers from
compromising the entire system. Note that most components need write access
to parts of the filesystem. The default path for writing files is
`/var/lib/uic`.

## Miscellaneous

- _The "CRLF" issue_

  After running `ninja` inside the Docker container you may explore a lot of
  `expected primary expression before 'case:'` errors. This is because of Windows
  line endings (CRLF vs Linux's CR-only).
  
  Workaround: run in your repository folder
  
  ``` sh
  git config --global core.autocrlf input
  git rm --cached -r .
  git reset --hard
  ```
  
  Explanations:
  [Stackoverflow solution](https://stackoverflow.com/questions/1967370/git-replacing-lf-with-crlf).

- _The "Docker directory path" issue_

  ``` sh
  user@winmachine MINGW64 ~/path/to/UnifySDK (main)
  $ winpty docker run -it --rm  -v`pwd`:`pwd` -w `pwd` uic_armhf
  docker: Error response from daemon: the working directory 'C:/path/to/UnifySDK' is invalid, it needs to be an absolute path.
  See 'docker run --help'.
  ```
  
  Workaround: add the `/` symbol before `pwd`:
  
  ``` sh
  user@winmachine MINGW64 ~/path/to/UnifySDK (main)
  $ winpty docker run -it --rm  -v/`pwd`:/`pwd` -w /`pwd` uic_armhf
  user@dockercontainer:/c/path/to/UnifySDK$
  ```
  
  Explanation:
  [Stackoverflow solution](https://stackoverflow.com/questions/40213524/using-absolute-path-with-docker-run-command-not-working#comment109755641_40214650).
  
- _"winpty" issue_

  ``` sh
  user@winmachine MINGW64 ~/path/to/UnifySDK (main)
  $ docker run -it --rm  -v`pwd`:`pwd` -w `pwd` uic_armhf
  the input device is not a TTY.  If you are using mintty, try prefixing the command with 'winpty'
  ```
  
  Workaround: add a `winpty` prefix to the command:
  
  ``` sh
  winpty docker run -it --rm  -v`pwd`:`pwd` -w `pwd` uic_armhf
  ```
