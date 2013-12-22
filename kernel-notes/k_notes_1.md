Linux Kernel
============

####Monolithic kernel####

* Whole operating system is on the RAM reserved as kernel space.
* In constrast to kernel space, there is user space. No user program can use the kernel space.

---

####Preemptive multitasking kernel####

* Kernel will pause some tasks so that every application gets a chance to use CPU.
* Kernel will force applications to stop/pause using the CPU. Applications cannot do anything about it.

---

####Everything is a file####

* Devices appear as files in `/dev`
* For instance, USB ports are located in `/dev/bus/usb`
* Hard drive partitions are seen in `/dev/disk/by-label`

---

####Linux kernel is portable####

* Linux kernel can work on variety of different processors and systems.
* Some of the processor types that the kernel supports include Alpha, AMD, ARM, C6X, Intel, x86, Microblaze, MIPS, PowerPC, SPARC, UltraSPARC, etc.

---

####The `/boot` Folder####

* `vmlinux` or `vmlinuz` are compiled linux kernels present in `/boot`.
* `z` stands for compressed. `vm` is virtual memory.
* `zImage`, `bzImage` may also be seen on some processors.
* All above mentioned files are bootables.
