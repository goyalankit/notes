Setting an IP Address
======================

in `/var/lib/lxc/myfc/config` file. This is what it contains.

```
lxc.network.type=veth
lxc.network.link=lxcbr0
lxc.network.flags=up
lxc.network.hwaddr = 00:16:3e:f7:fe:c1
lxc.utsname = myfc

...... more stuff

```

**Adapter Name**, Make ot more descriptive by adding this:

`lxc.network.veth.pair = vethmyfc`

**IP address**

`lxc.network.ipv4 = 10.0.3.42` #you could add a subnet too.

To make the changes restart: `lxc-stop -n myfc` and `lxc-start -n myfc -d`

Running `ifconfig` on host pc will show you the corresponding adapter(`vethmyfc` in this case).


