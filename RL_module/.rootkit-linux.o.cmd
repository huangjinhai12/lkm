cmd_/lkm/RL_module/rootkit-linux.o := ld -m elf_x86_64   -r -o /lkm/RL_module/rootkit-linux.o /lkm/RL_module/rl_module.o ; scripts/mod/modpost /lkm/RL_module/rootkit-linux.o
