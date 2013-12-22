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



---

####Terminology####

<a name="pci"></a>
**Peripheral Component Interconnect (PCI)**:  One very common bus is known as the PCI bus. These slower buses connect to the system bus through a bridge, which is a part of the computer's chipset and acts as a traffic cop, integrating the data from the other buses to the system bus. Read more at http://computer.howstuffworks.com/pci1.htm ![PCI](https://gist.github.com/goyalankit/8074196/raw/a369d62d453cc4c0b6134c127e9efe603c445e53/pci-diagram.gif)
