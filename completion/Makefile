MODULE_NAME = hello_test
ifneq ($(KERNELRELEASE),)
obj-m := $(MODULE_NAME).o
$(MODULE_NAME)-objs := hello.o
else
KERNELDIR ?= /lib/modules/$(shell uname -r)/build
#KERNELDIR ?= /usr/src/linux
  PWD := $(shell pwd)
default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
endif
clean:
	rm *.o *.ko *.symvers *.order .*.cmd *.markers $(MODULE_NAME).mod.c .tmp_versions -rf
