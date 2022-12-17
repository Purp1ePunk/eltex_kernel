obj-m += netlink_main.o

PWD := $(CURDIR)

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
	gcc netlink_client.c -o netlink_client 
	
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
	rm netlink_client
