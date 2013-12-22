Configuring the Kernel
======================

There are serveral different ways to configure the kernel. Widely used ones are:

`make config`:  Plain text interface.

`make menuconfig`: Text based with colored menues and radiolists. This option allows to save progress. ncurses must be installed (`sudo apt-get install libncurses5-dev`).

**libncurses5-dev**: (*lib*)library *ncurses*(Terminal based GUI) *5*(version) *dev*(for developers)

---

##**`make menuconfig`**##

![make menuconfig](https://gist.github.com/goyalankit/8074196/raw/869d7bd6c1ff56f58a368565ab4b2761d225759d/kernel_config_screen_1.png)


**`Q1. 64-bit kernel`**: Yes if the kernel to be built is 64 bit.


![General Setup](https://gist.github.com/goyalankit/8074196/raw/2940916265e3cfada1238fd8ba2b52c55f3fa0e0/kernel_config_screen_2.png)

* **Cross-compiler tool prefix**: If you are not cross-compiling leave it unchecked. Else type the corresponding command for the architecture you are compiling for. Example: "arm-unknown-linux-gnu-" for ARM systems or "x86_64-pc-linux-gnu-" for 64-bit PC systems.
* **compile also drivers which will not load (NEW)**: Some drivers can be compiled on a different platform than they are intended to be run on. Answer NO if you are a user. This option is for developers to test that the code compiles.
* **Local version - append to kernel release**:  

