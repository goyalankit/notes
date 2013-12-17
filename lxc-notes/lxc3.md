Tools of the trade
==================

**lxc-backup and lxc-restore**

```
lxc-backup CONTAINER [BACKUP_NUMBER]
```

CONTAINER: container name
BACKUP_NUMBER: optional backup number for the container. Can be left blank, highest number will be incremented from the container directory.

Backups are stored in `/var/lib/lxc/myfc/rootfs.backup1/`

In a similar way `lxc-restore` can be used.

---

Useful while creating a base template container. 
```
lxc-clone -o <original container name> -n <new container name>
```


`lxc-destroy` destroys the conatainer. You can pass `-w` flag to wait until the container is actually shutdown.



`lxc-list` list the containers. Will group based on RUNNING, FROZEN, STOPPED


`lxc-ls` will list all the containers. Not showing the states. Less
verbose than lxc-list


`lxc-info -n <container name>` state of the container including pid of the container.


`lxc-freeze` and `lxc-unfreeze` pause and unpause the container for debugging.


`lxc-ps` just like normal ps command. You can pass arguments also:
```
root@precise64:/home/vagrant# lxc-ps -n myfc -- aux

CONTAINER  USER       PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
myfc       root      1678  0.1  0.1  24080   676 ?        Ss   04:02   0:00 /sbin/init
myfc       root      1811  0.0  0.0  15192   188 ?        S    04:02   0:00 upstart-socket-bridge --daemon
myfc       root      1841  0.0  0.0  17236   164 ?        S    04:02   0:00 upstart-udev-bridge --daemon
myfc       root      1852  0.0  0.0  21340   284 ?        Ss   04:02   0:00 /sbin/udevd --daemon
myfc       syslog    1859  0.0  0.1 249468   396 ?        Sl   04:02   0:00 rsyslogd -c5
myfc       root      1894  0.0  0.1   7268   492 ?        Ss   04:02   0:00 dhclient3 -e IF_METRIC=100 -pf /var/run/dhclient.eth0.pid -lf /var/lib/dhcp/dhclient.eth0.leases -1 eth0
myfc       root      1916  0.0  0.1  50036   608 ?        Ss   04:02   0:00 /usr/sbin/sshd -D
myfc       root      1944  0.0  0.0  12756   144 pts/4    Ss+  04:02   0:00 /sbin/getty -8 38400 tty4
myfc       root      1949  0.0  0.0  12756   160 pts/2    Ss+  04:02   0:00 /sbin/getty -8 38400 tty2
myfc       root      1950  0.0  0.0  12756   148 pts/3    Ss+  04:02   0:00 /sbin/getty -8 38400 tty3
myfc       root      1956  0.0  0.0  19116   196 ?        Ss   04:02   0:00 cron
myfc       root      1978  0.0  0.0  12756   152 pts/5    Ss+  04:02   0:00 /sbin/getty -8 38400 console
myfc       root      1980  0.0  0.0  12756   156 pts/1    Ss+  04:02   0:00 /sbin/getty -8 38400 tty1

```

---

`lxc-netstat` like normal netstat command. To pass arguments use it in a following way.

```
root@precise64:/home/vagrant# lxc-netstat -n myfc -ntlup
Active Internet connections (only servers)
Proto Recv-Q Send-Q Local Address           Foreign Address         State       PID/Program name
tcp        0      0 0.0.0.0:22              0.0.0.0:\*               LISTEN      1916/sshd
tcp6       0      0 :::22                   :::\*                    LISTEN      1916/sshd
udp        0      0 0.0.0.0:68              0.0.0.0:\*                           1894/dhclient3
```
**Not the argument passing syntax is not same as**`lxc-ps`

---

`lxc-cgroup` allows you to tweak lxc's inner workings. These can also be set in containers config file.

`lxc-cgroup -n myfc memory.usage_in_bytes` to know the amount of memory
being used.


`lxc-cgroup -n myfc memory.limit_in_bytes 300000000` allows you set
the memory limit on a container.


**Containers share memory whenever possible.(system libraries, etc.)
this is the reason for low footprint.**
