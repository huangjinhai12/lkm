cmd_/lkm/lkm_test/lkm.ko := ld -r -m elf_x86_64 -T ./scripts/module-common.lds --build-id  -o /lkm/lkm_test/lkm.ko /lkm/lkm_test/lkm.o /lkm/lkm_test/lkm.mod.o
