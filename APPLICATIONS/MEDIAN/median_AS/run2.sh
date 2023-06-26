#!/bin/bash

make build_opt

/usr/lib/llvm-10/bin/llc  -O2  -march=riscv32 -filetype=asm app.opt.bc -o /home/dennard/accept/APPS_Loop/median_1/median_AS/median_AS2.s

riscv32-unknown-elf-gcc /home/dennard/accept/APPS_Loop/median_1/median_AS/median_AS2.s -O1 -march=rv32im -o /home/dennard/accept/APPS_Loop/median_1/median_AS/median_AS2 -lm 

spike --isa=RV32I /opt/riscv/riscv32-unknown-elf/bin/pk /home/dennard/accept/APPS_Loop/median_1/median_AS/median_AS2 