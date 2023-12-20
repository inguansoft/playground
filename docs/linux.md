useradd -m <user_name>
passwd <user_name>
userdel <user_name>

usermod -aG sudo username

samba v1
sudo apt install samba
sudo emacs /etc/samba/smb.conf
client min protocol = NT1

lsb_release -a
lscpu

arch[-vendor][-os]-abi
arch identifies the architecture; that is, arm, mips, x86, i686, and so on.
vendor is the toolchain supplier (company); that is, Bootlin, Linaro, none (if there is no provider) or simply omitting the field, and so on.
os is for the target operating system; that is, linux or none (bare metal). If omitted, bare metal is assumed.
abi stands for application binary interface. It refers to what the underlying binary is going to look like, the function call convention, how parameters are passed, and more. Possible conventions include eabi, gnueabi, and gnueabihf. Let's look at these in more detail:
 eabi means that the code that will be compiled will run on a bare metal ARM core.
