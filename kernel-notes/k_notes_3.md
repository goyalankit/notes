Linux Drivers
=============

Drivers are small programs that enable the kernel to communicate and handle hardware or protocols (rules and standards).



* **accessibility**: These drivers provide support for accessiblity devices. There is only one driver in this file: **braille** device driver.

* **acpi**: The Advanced Configuration and Power Interface driver manage power usage.

* **amba**: Advanced Microcontoller Bus Architecture(AMBA) is a protocol for the management and interconnection in a System-on-Chip(SoC). A SoC is a single chip that contains many or all essential components of a computer on a chip. The AMBA drivers in this folder allow kernel to run on these chips.

* **ata**: Contains drivers for SATA and PATA devices. ATA: At Attachment. Serial ATA (SATA) is a computer bus interface that connects host bus adapters to storage devices like hard-drives. SATA is energy efficient and faster than PATA.

* **atm**: Asynchronous Transfer Mode is a standard for telecommunications. variety of drivers from [PCI](#pci)(Peripheral Component Interconnect) bridges to Ethernet controllers. 

* **auxdisplay**: This folder contains drivers to manage LCD monitors. 

* **base**: An important directory. Contains essential base drivers for firmware, the system bus, hypervisor abilities, etc.

* **bcma**: These are the drivers for buses that use protocols based on AMBA protocol. These new buses are made by Broadcom.

* **block**: These drivers provide support for block devices like floppy disk readers, SCSI tapes, block devices over TCP, etc.

* **bluetooth**: Drivers for bluetooth devices. 

* **bus**: This directory contains three drivers. One converts OCP(open core protocol) to SCP protocol.The other driver is for interconnection between devices and the third driver is for error handling for interconnection.

* **cdrom**: Two drivers. one is for cd-roms: reading, writing DVDs and CDs. Other is for gd-rom(Gigabyte Disk read only memory). A GD is an optical disk with 1.2GB storage capacity. This is like large CD or small DVD, commonly used in Dreamcast game consoles.

* **char**: Character device drivers. Character devices transfer data one character at a time. Some of the drivers are printer, Toshiba SMM drivers, random number generator driver.

* **clk**: System clock driver.

* **clocksource**: These drivers use clock as a timer.

* **connector**:  These drivers supply the kernel with the ability to know when processes fork and execute as well as changing the UID (User ID), GID (Group ID), and SID (session ID) using what is called a [proc connector](#pro_connect). The kernel needs to know when process fork (run multiple tasks in the CPU) and execute. Otherwise, the kernel may have inefficiencies in managing resources.

* **cpufreq**: These drivers controls the CPU by changing power.

* **cpuidle**: These drivers manage the idleness of CPU/s. If the system has multiple CPUs, one of the drivers will try to keep the idleness same.

* **crypto**: These drivers provide cryptographic features.

Go to http://www.linux.org/threads/the-linux-kernel-drivers.4205/ for more drivers.


---

####Terminology####

<a name="pci"></a>
**Peripheral Component Interconnect (PCI)**:  One very common bus is known as the PCI bus. These slower buses connect to the system bus through a bridge, which is a part of the computer's chipset and acts as a traffic cop, integrating the data from the other buses to the system bus. Read more at http://computer.howstuffworks.com/pci1.htm ![PCI](https://gist.github.com/goyalankit/8074196/raw/a369d62d453cc4c0b6134c127e9efe603c445e53/pci-diagram.gif)

<a name="pro_connect"></a>
**Proc Connector**: The proc connector allows you to receive notification of process events such fork and exec calls, as well as changes to a process's uid, gid or sid (session id). These are provided through a socket-based interface by reading instances of struct proc_event defined in the kernel header.
