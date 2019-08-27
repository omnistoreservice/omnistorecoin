UNIX BUILD NOTES
====================
Some notes on how to build Dash Core in Unix.

(for OpenBSD specific instructions, see [build-openbsd.md](build-openbsd.md))

Base build dependencies
-----------------------
Building the dependencies and Dash Core requires some essential build tools and libraries to be installed before.

Run the following commands to install required packages:

##### Debian/Ubuntu:
```bash
$ sudo apt-get install curl build-essential libtool autotools-dev automake pkg-config python3 bsdmainutils cmake
```

##### Fedora:
```bash
$ sudo dnf install gcc-c++ libtool make autoconf automake python3 cmake libstdc++-static patch
```

##### Arch Linux:
```bash
$ pacman -S base-devel python3 cmake
```

Building
--------

Follow the instructions in [build-generic](build-generic.md)