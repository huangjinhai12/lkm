cmd_/lkm/list/list_test.o := ld -m elf_x86_64   -r -o /lkm/list/list_test.o /lkm/list/list.o ; scripts/mod/modpost /lkm/list/list_test.o
