cmd_/lkm/msg/list_test.o := ld -m elf_x86_64   -r -o /lkm/msg/list_test.o /lkm/msg/list.o ; scripts/mod/modpost /lkm/msg/list_test.o
