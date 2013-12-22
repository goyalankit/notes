Security in Kernel
==================

Linux kernel is core of all Linux systems. Malicious code can severly damage the system.

####Linux Securtiy Modules####

* **AppArmor**(Application Armor): AppArmor restricts the ability of programs. AppArmor uses file paths to keep track of program restrictions. Easiest to configure, provides worst security compared to alternatives.

* **Security-Enhanced Linux**(SELinux): Made by NSA. SELinux makes modifications to the kernel and user-space tools. SELinux gives the executables minimum privilages required to complete the task. It can also be used to control user privileges. SELinux uses file system to mark executables when keeping track of permissions instead of file path(in AppArmor). SELinux cannot provide protection on filesystems since it uses filesystem itself whereas AppArmor can.

* **Smack** is another security module.
* **TOMOYO** mainly used for analyzing security flaws.

AppArmor, SELinux, Smack, TOMOYO all work by using mandatotry access control(MAC) that restrics a program or user from executing some task.

**grsecurity** is a collection of security patches for enhancing Linux kernel's security. Majority of patches apply to remote network connections and buffer overflows. 

PaX is a component of grsecurity that allows code on memory to use the least amount of priveleges. For example, memory containing programs is non-writable. It also prevents buffer overflows because the program will not have permissions to write on memory pages of other programs.

**Systrace** Systrace is a utility that reduces and controls application's access to system files and use of system calls. 


