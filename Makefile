main: main.c xoshiro256starstar.c
	cc $< -o $(<:.c=)
