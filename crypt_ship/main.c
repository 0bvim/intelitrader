#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void convert_and_swap_bits(char *octet);

int main(void) {
  char to_decrypt[] =
      "10010110 11110111 01010110 00000001 00010111 00100110 01010111 00000001 "
      "00010111 01110110 01010111 00110110 11110111 11010111 01010111 00000011";

  char *token, *saveptr;
  char delim[] = " ";

  token = strtok_r(to_decrypt, " ", &saveptr);
  while (token != NULL) {
    convert_and_swap_bits(token);
    token = strtok_r(NULL, " ", &saveptr);
  }
  putchar('\n');

  return (EXIT_SUCCESS);
}

static void convert_and_swap_bits(char *octet) {
  char character;

  character = strtol(octet, NULL, 2);
  character ^= 0b11;
  character = ((character & 0xF0) >> 4) | ((character & 0x0F) << 4);
  if (isprint((int)character))
    putchar(character);
}
