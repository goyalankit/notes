Getting Started with Linux Containers
=====================================

Most of the [l|u]nix kernels have support for lxc by default.

lxc-create
----------

```
lxc-create -h
usage: lxc-create -n <name> [-f configuration] [-t template] [-h] -- [template_options]
usage: lxc-create -n <name> [-f configuration] [-t template] [-h] [fsopts] -- [template_options]
   fsopts: -B none
   fsopts: -B lvm [--lvname lvname] [--vgname vgname] [--fstype fstype] [--fssize fssize]
   fsopts: -B btrfs
           flag is not necessary, if possible btrfs support will be used

creates a lxc system object.

Options:
name         : name of the container
configuration: lxc configuration
template     : lxc-template is an accessible template script

The container *backing store* can be altered using '-B'.  By default it
is 'none', which is a simple directory tree under /var/lib/lxc/<name>/rootfs
Otherwise, the following option values may be relevant:
lvname       : [for -lvm] name of lv in which to create lv,
                container-name by default
vgname       : [for -lvm] name of vg in which to create lv, 'lxc' by default
fstype       : name of filesystem to create, ext4 by default
fssize       : size of filesystem to create, 1G by default
for template-specific help, specify a template, for instance:
lxc-create -t ubuntu -h
```

Backing store **(-B)** option is telling LXC what filesystem to create the container with. 
Two options:
* lvm
* btrfs

**btrfs** is not stable yet. So go with lvm or leave it blank. It will check
what thr filesystem of `/var/lib/lxc` is and make it the filesystem of
container.

**Templates:** Shell scripts that get run when lxc-create is called. Check `/usr/lib/lxc/templates` on ubuntu for examples. An ISO of the system is downloaded when used for the first time.
