cmd_/lkm/completion/hello_test.o := ld -m elf_x86_64   -r -o /lkm/completion/hello_test.o /lkm/completion/hello.o ; scripts/mod/modpost /lkm/completion/hello_test.o
