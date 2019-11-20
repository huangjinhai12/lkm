cmd_/lkm/hello/hello.o := ld -m elf_x86_64   -r -o /lkm/hello/hello.o /lkm/hello/hello_world.o ; scripts/mod/modpost /lkm/hello/hello.o
