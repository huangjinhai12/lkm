cmd_/lkm/hello/hello.ko := ld -r -m elf_x86_64 -T ./scripts/module-common.lds --build-id  -o /lkm/hello/hello.ko /lkm/hello/hello.o /lkm/hello/hello.mod.o
