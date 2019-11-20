cmd_/lkm/completion1/hello_test.o := ld -m elf_x86_64   -r -o /lkm/completion1/hello_test.o /lkm/completion1/hello.o ; scripts/mod/modpost /lkm/completion1/hello_test.o
