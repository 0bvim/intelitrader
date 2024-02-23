#include <stdio.h>
#include <stdlib.h>

static void	convert_and_swap_bits(char *octet);

int main(int ac, char **av) {
	
	if(2 > ac) {
		dprintf(2, "You need at least 1 argument.\n");
		return (EXIT_FAILURE);
	}
	for (int i = 1; i <= ac; i++) {
		if (!av[i])
			break ;
		convert_and_swap_bits(av[i]);
	}
	putchar('\n');
	return (EXIT_SUCCESS);
}

static void	convert_and_swap_bits(char *octet)
{
	char	character;

	character = strtol(octet, NULL, 2);
	character ^= 0b11;
	character = ((character & 0xF0) >> 4) | ((character & 0x0F) << 4);

	putchar(character);
}
