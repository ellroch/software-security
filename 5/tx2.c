#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
  if (argc != 2)
  {
    printf("Need a seed\n");
    exit(1);
  }
  srand(atoll(argv[1]));
  printf("Random seeded - providing 5 random values!\n");
  for (int i=0; i < 5; i++)
    printf("%d ", rand() % 1000);
  printf("\n");
  return 0;
}
