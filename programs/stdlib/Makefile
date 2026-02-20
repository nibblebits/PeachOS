# PeachOS 32-Bit Kernel project
# Copyright (C) 2026 Daniel McCarthy <daniel@dragonzap.com>
# This file is part of th PeachOS Kernel.
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# version 2 as published by the Free Software Foundation.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# See the GNU General Public License version 2 for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, see <https://www.gnu.org/licenses/>.
#
# For full source code, documentation, and structured learning,
# see the official kernel development video course:
# https://dragonzap.com/course/developing-a-multithreaded-kernel-from-scratch
#
# The new part two course is now here
# Learn to extend your kernel into 64-bit long mode with GUI
# Get all modules today here: https://dragonzap.com/offer/developing-a-multithreaded-kernel-from-scratch-part-two-full-series
#
# Or get them individually here: 
# MODULE 1 https://dragonzap.com/course/developing-a-multithreaded-kernel-from-scratch-part-two-module-one
# MODULE 2 https://dragonzap.com/course/developing-a-multithreaded-kernel-from-scratch-part-two-module-two
#
FILES=./build/start.asm.o ./build/start.o ./build/peachos.asm.o ./build/peachos.o ./build/stdlib.o ./build/stdio.o ./build/string.o ./build/memory.o
INCLUDES=-I./src
FLAGS= -g -ffreestanding -falign-jumps -falign-functions -falign-labels -falign-loops -fstrength-reduce -fomit-frame-pointer -finline-functions -Wno-unused-function -fno-builtin -Werror -Wno-unused-label -Wno-cpp -Wno-unused-parameter -nostdlib -nostartfiles -nodefaultlibs -Wall -O0 -Iinc

all: ${FILES}
	i686-elf-ld -m elf_i386 -relocatable ${FILES} -o ./stdlib.elf

./build/start.asm.o: ./src/start.asm
	nasm -f elf ./src/start.asm -o ./build/start.asm.o

./build/peachos.asm.o: ./src/peachos.asm
	nasm -f elf ./src/peachos.asm -o ./build/peachos.asm.o

./build/peachos.o: ./src/peachos.c
	i686-elf-gcc ${INCLUDES} $(FLAGS) -std=gnu99 -c ./src/peachos.c -o ./build/peachos.o

./build/stdlib.o: ./src/stdlib.c
	i686-elf-gcc ${INCLUDES} $(FLAGS) -std=gnu99 -c ./src/stdlib.c -o ./build/stdlib.o

./build/stdio.o: ./src/stdio.c
	i686-elf-gcc ${INCLUDES} $(FLAGS) -std=gnu99 -c ./src/stdio.c -o ./build/stdio.o


./build/string.o: ./src/string.c
	i686-elf-gcc ${INCLUDES} $(FLAGS) -std=gnu99 -c ./src/string.c -o ./build/string.o

./build/memory.o: ./src/memory.c
	i686-elf-gcc ${INCLUDES} $(FLAGS) -std=gnu99 -c ./src/memory.c -o ./build/memory.o

./build/start.o: ./src/start.c
	i686-elf-gcc ${INCLUDES} $(FLAGS) -std=gnu99 -c ./src/start.c -o ./build/start.o


clean:
	rm -rf ${FILES}
	rm ./stdlib.elf
