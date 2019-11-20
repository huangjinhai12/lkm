cmd_/lkm/thread_init/hello_test.ko := ld -r -m elf_x86_64 -T ./scripts/module-common.lds --build-id  -o /lkm/thread_init/hello_test.ko /lkm/thread_init/hello_test.o /lkm/thread_init/hello_test.mod.o
