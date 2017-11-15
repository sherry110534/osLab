obj-m += Module_A.o
obj-m += Module_B.o
obj-m += Module_C.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
