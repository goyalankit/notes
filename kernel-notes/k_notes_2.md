Kernel Source Code
==================

The root of the kernel contains following folders.

```
arch
block
crypto
Documentation
drivers
firmware
fs
include
init
ipc
kernel
lib
mm
net
samples
scripts
security
sound
tools
usr
virt
```

####Files####

Files that are also located in the root of the kernel folder:

1. `COPYING`: Information on licensing. GPLv2 license.
2. `CREDITS`: List of contributors.
3. `Kbuild`: Sets up some settings for making the kernel. For examples, sets up ARCH variable where ARCH is the processor type that a developer wants kernel to support.
4. `Kconfig`: This script is used to configure the kernel.
5. `MAINTAINERS`: Current maintainers for a specific module.
6. `Makefile`: Main file that is used to compile the kernel. Passes parameters to compiler and list of files.
7. `README`: Info on how to compiler the kernel.
8. `REPORTING-BUGS`: Info on how to report bugs.

####Folders####

1. **arch**: This folders contains Kconfig file which sets up settings for compiling the source code contained in this folder. Each supported architecture is in the corressponding folder. Examples: `x86`, `arm`, `alpha`, etc.
 
2. **block**: This holds code for block-device drivers. Block devices send and accept data in blocks instead of a continual stream. e.g., hard disk

3. **crypto**: Source code for many encryption algorithms. e.g., *sha1_generic.c* contains code for sha1 encryption algorithm.

4. **Documentation**: Plain text information on kernel and many of the files.

5. **drivers**: 










