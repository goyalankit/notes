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

5. **drivers**: Contains drivers for different hardware devices. Keyboard, mouse drivers are present in input folder inside drivers. The **Xen** folder contains code for Xen hypervisor.

6. **firmware**: Firmware contains code required to read and understand signals from a device. For example, webcam manages it's hardware and sends signals to the computer. Linux system will use vicam firmware to understand the signals. Firmware also helps to send messages to the device. Linux system can tell webcam to focus, turn off.

7. **fs**: All the code needed to understand and use filesystem is here. NTFS (if enabled) can automatically compresses the files without user noticing. This functionality can be provided in other file systems by changing corresponding code in this folder.

8. **include**: miscellaneous header files that the kernel uses.

9. **init**: Contains the code that deals with the startup of the kernel. It also contains **`main.c`** file, which is the core of the kernel and connects all other files.

10. **ipc**: Inter-Process Communication. Handles the communication layer between kernel and processes. Suppose a process needs to open a DVD trey. Process sends the signal to kernel and then kernel open the trey.

11. **kernel**: Code in this folder controls the kernel itself. If a debugger is attached, kernel will use code in this file to inform debugger about all the actions that it performed.

12. **lib**: Contains kernel libraries that the kernel will need to reference.

13. **mm**: Memory Management. Memory is not randomly placed on RAM. Kernel doesn't overwrite any data in RAM and carefully places the data.

14. **net**: Contains the code for network protocols. IPv6, Appletalk, handling network bridges, DNS name resolution etc.

15. **samples**: This folder contains programming examples and modules that are being started.

16. **scripts**: Contains the scipts needed to compile the kernel.

17. **security**: This folder has the code for the security of kernel to prevent it from viruses and hackers.

18. **sound**: Sound driver code for sound/audio cards.

19. **tools**: Contains tools that interact with kernel. e.g., cgroup

20. **usr**: Code in this folder creates the bootables after the kernel is compiled.

21. **virt**: Contains code for virtualization that allows users to run multiple OS at once.This is different from Xen. With virtualization, guest operating system acts as any other application. With hypervisor like Xen, the two operating systems are managing hardware together at the same time. In virtualization, guest OS runs on top of Linux kernel. However in a hypervisor there is no guest OS and all the OS don't depend on each other.

Tip: Don't move files around in the kernel. Compilation will fail due to missing file.

21. 
















