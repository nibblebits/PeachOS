FILES=./build/blank.o
INCLUDES= -I../stdlib/src
all: ${FILES}
	i686-elf-gcc -g -T ./linker.ld -o ./blank.elf -ffreestanding -O0 -nostdlib -fpic -g ${FILES} ../stdlib/stdlib.elf

./build/blank.o: ./blank.c
	i686-elf-gcc ${INCLUDES}  -I./$(FLAGS) -std=gnu99 -c ./blank.c -o ./build/blank.o

clean:
	rm -rf ${FILES}
	rm ./blank.elf