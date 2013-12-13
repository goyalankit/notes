
Creating and Running the container
==================================

Create the container with default Ubuntu template using:

`lxc-create -n myfc -t ubuntu`

This downloads the ISO and creates the container. To start the
container:

Default Username And Password is "ubuntu" and "ubuntu"

`lxc-start -n myfc`

---

You can also deamonize the container by using `-d` flag while starting.

`lxc-start -n myfc -d`

Now you can enter the container using `lxc-console -n myfc`
To exit the container, simply use `ctrl+a q`
