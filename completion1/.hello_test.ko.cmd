cmd_/lkm/completion1/hello_test.ko := ld -r -m elf_x86_64 -T ./scripts/module-common.lds --build-id  -o /lkm/completion1/hello_test.ko /lkm/completion1/hello_test.o /lkm/completion1/hello_test.mod.o
