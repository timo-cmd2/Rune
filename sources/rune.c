#include <stdio.h>
#include <stdlib.h>

unsigned char convert(unsigned char c) {
	return (c & 0x40) << 1
	     | (c & 0x07) << 4
	     | (c & 0x80) >> 4
	     | (c & 0x38) >> 3;
}

void execute(unsigned char *tape, size_t datapointer) {
	unsigned char insn, arg;
	size_t instructionpointer = 0;

	while (++instructionpointer) {
		insn = tape[instructionpointer] & 0xf0;
		arg  = tape[instructionpointer] & 0x0f;

		switch (insn) {
			case 0x00: exit(arg); break;
			case 0x10: *tape += tape[datapointer + arg]; break;
			case 0x20: *tape -= tape[datapointer + arg]; break;
			case 0x30: tape[datapointer + arg] = *tape; break;
			case 0x40: *tape = tape[datapointer] + arg; break;
			case 0x50: datapointer += 1 << arg; break;
			case 0x60: datapointer -= 1 << arg; break;
			case 0x70: instructionpointer += arg + 1; break;
			case 0x80: instructionpointer -= arg + 2; break;
			case 0x90: if (!*tape) instructionpointer += arg + 1; break;
			case 0xa0: if (!*tape) instructionpointer -= arg + 2; break;
			case 0xb0: if (*tape) instructionpointer += arg + 1; break;
			case 0xc0: if (*tape) instructionpointer -= arg + 2; break;
			case 0xd0: tape[datapointer + arg] = getchar(); break;
			case 0xe0: putchar(tape[datapointer + arg]); break;
			case 0xf0: tape[datapointer + arg] = rand() % 0xff; break;
		}
	}
}

int main(int argc, char **argv) {
	int c;
	FILE *src;
	size_t cap = 1, len = 1;
	unsigned char *tape = calloc(1, 1);

	if (argc != 2) {
		return fprintf(stderr, "The Rune programming-language Copyright 2021 Timo Sarkar\n\nUsage: %s < foo.rune >\n\n", *argv);
	}

	if (!(src = fopen(argv[1], "r"))) {
		return fprintf(stderr, "Unable to open file '%s'\n", argv[1]);
	}

	while ((c = fgetc(src)) != EOF) {
		if (c == 0xe2) { 
			c = convert((fgetc(src) - 0xa0) * 0x40 + (fgetc(src) - 0x80));
			
			if (cap == len) {
				tape = realloc(tape, cap <<= 1);
			}
			
			tape[len++] = c;
		}
	}

	srand((unsigned int) &c);
	execute(tape, len);

	fclose(src);
	free(tape);
	return 0;
}
