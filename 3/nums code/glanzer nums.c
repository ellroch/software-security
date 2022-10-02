#include <stdio.h>
#include <string.h>

void count()
{
  // store up to 5 numbers
  int numbers[5];
  int i = 0, number, done=0, total=0, j;

  // wait for -1 to quit
  while (done != 1) {
    if (number == -1 || i==5)
      done = 1;
    else
    {
      printf("Enter a number to add to the list (-1 to quit): ");
      scanf("%d", &number);
      numbers[i] = number;
      i++;
    }
  }

  // add up the numbers ()
  for (j=i-1; j >= 0; j--)
    total += numbers[j];
  printf("Sum is: %d\n", total);
}
//-----------------------------------------------------------------
void hello()
{
  char name[15];
  // read in a name
  printf("Enter your name: ");
  scanf("%14s", name);
  //cleanup anything left in the buffer
  char *nl= strchr(name, '\n');
  if (!nl){
    scanf("%*[^\n]%*c");
  }
  printf("\n");

  // print hello
  printf("Hi there, %s\n", name);
}
//-----------------------------------------------------------------
int main()
{
  int selection;
  do {
    printf(" 1) count\n");
    printf(" 2) hello\n");
    printf(" 0) quit\n");
    printf("Select a routine to run: ");
    scanf("%d", &selection);
    getchar(); // reads in the bonus \n from previous line
    if (selection == 1)
      count();
    else if (selection == 2)
      hello();
  } while (selection != 0); 
  return 0;
}
