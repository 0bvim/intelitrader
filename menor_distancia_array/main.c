#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static void fill_array(int *array, int size);
static void print_array(int *array, int size);
static void find_distance(int *array1, int size1, int *array2, int size2);

int main(void) {
  int size1 = 10, size2 = 5;
  int array1[size1];
  int array2[size2];

  srand(time(NULL));

  fill_array(array1, size1);
  fill_array(array2, size2);

  // remova o bloco de comantario abaixo para ver os valores de cada array
  // puts("Valores do Array1:");
  // print_array(array1, size1);
  //
  // puts("\nValores do Array2:");
  // print_array(array2, size2);
  //
  // putchar('\n');

  find_distance(array1, size1, array2, size2);

  return EXIT_SUCCESS;
}

static void find_distance(int *array1, int size1, int *array2, int size2) {
  int smallest = INT_MAX;

  for (int i = 0; i < size1; ++i) {
    for (int j = 0; j < size2; ++j) {
      int distance = abs(array1[i] - array2[j]);
      if (distance < smallest) {
        smallest = distance;
      }
    }
  }
  printf("Menor distancia entre os arrays: %i\n", smallest);
}

static void print_array(int *array, int size) {
  for (int i = 0; i < size; ++i) {
    printf("array in position %d, value: %d\n", i, array[i]);
  }
}

static void fill_array(int *array, int size) {
  for (int i = 0; i < size; ++i) {
    array[i] = rand() % 100;
    if (i % 2)
      array[i] *= -1;
  }
}
