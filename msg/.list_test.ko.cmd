cmd_/lkm/msg/list_test.ko := ld -r -m elf_x86_64 -T ./scripts/module-common.lds --build-id  -o /lkm/msg/list_test.ko /lkm/msg/list_test.o /lkm/msg/list_test.mod.o
