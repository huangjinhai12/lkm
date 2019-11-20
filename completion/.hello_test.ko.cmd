cmd_/lkm/completion/hello_test.ko := ld -r -m elf_x86_64 -T ./scripts/module-common.lds --build-id  -o /lkm/completion/hello_test.ko /lkm/completion/hello_test.o /lkm/completion/hello_test.mod.o
