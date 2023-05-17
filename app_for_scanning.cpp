#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_VALUE 0xAAU
#define HEADER_SIZE sizeof(int)

char *allocate_buffer(int size) {
  char *buffer = (char *)malloc(size + HEADER_SIZE);
  char i;
  int *buffer_size = (int *)buffer;
  *buffer_size = size;
  for (i = HEADER_SIZE; i < size + HEADER_SIZE; i++) {
    buffer[i] = DEFAULT_VALUE;
  }
  return buffer;
}
void deallocate_buffer(char *buffer) {
  free(buffer);
  int buffer_size = *((int *)buffer);
  char i;
  for (i = 0; i < buffer_size; i++) {
    buffer[i] = DEFAULT_VALUE;
  }
}