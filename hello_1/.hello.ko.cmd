cmd_/lkm/hello_1/hello.ko := ld -r -m elf_x86_64 -T ./scripts/module-common.lds --build-id  -o /lkm/hello_1/hello.ko /lkm/hello_1/hello.o /lkm/hello_1/hello.mod.o
