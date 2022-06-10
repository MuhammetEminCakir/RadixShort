#include <stdio.h>
#include <stdlib.h>


int getMax(int array[], int n) {
  int max = array[0];
  for (int i = 1; i < n; i++)
    if (array[i] > max)
      max = array[i];
  return max;
}


void countingSort(int array[], int size, int place) {
  int output[size + 1];
  int max = (array[0] / place) % 10;

  for (int i = 1; i < size; i++) {
    if (((array[i] / place) % 10) > max)
      max = array[i];
  }
  int count[max + 1];

  for (int i = 0; i < max; ++i)
    count[i] = 0;


  for (int i = 0; i < size; i++)
    count[(array[i] / place) % 10]++;


  for (int i = 1; i < 10; i++)
    count[i] += count[i - 1];


  for (int i = size - 1; i >= 0; i--) {
    output[count[(array[i] / place) % 10] - 1] = array[i];
    count[(array[i] / place) % 10]--;
  }

  for (int i = 0; i < size; i++)
    array[i] = output[i];
}


void radixsort(int array[], int size) {
  int max = getMax(array, size);


  for (int place = 1; max / place > 0; place *= 10)
    countingSort(array, size, place);
}


void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}


int main() {
  FILE *fp1, *fp2, fp3;

  if ((fp1 = fopen ("10lukliste", "r+")) == NULL)
    {
      printf("Dosya acma hatasi!");
      exit(1);
    }
  if ((fp2 = fopen ("100lükliste", "r+")) == NULL)
    {
      printf("Dosya acma hatasi!");
      exit(1);
    }
  if ((fp3 = fopen ("1000likliste", "r+")) == NULL)
    {
      printf("Dosya acma hatasi!");
      exit(1);
    }

  int array[1000];
  int n = sizeof(array) / sizeof(array[0]);
  radixsort(array, n);
  printArray(array, n);

  fclose (fp1);
  fclose (fp2);
  fclose (fp3);
}
