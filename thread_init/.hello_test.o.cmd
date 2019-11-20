cmd_/lkm/thread_init/hello_test.o := ld -m elf_x86_64   -r -o /lkm/thread_init/hello_test.o /lkm/thread_init/hello.o ; scripts/mod/modpost /lkm/thread_init/hello_test.o
