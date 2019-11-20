cmd_/lkm/list/list_test.ko := ld -r -m elf_x86_64 -T ./scripts/module-common.lds --build-id  -o /lkm/list/list_test.ko /lkm/list/list_test.o /lkm/list/list_test.mod.o
