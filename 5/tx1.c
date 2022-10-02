#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(int milliseconds)
{
    long pause;
    clock_t now,then;

    pause = milliseconds*(CLOCKS_PER_SEC/1000);
    now = then = clock();
    while( (now-then) < pause )
        now = clock();
}

void getSequence(int numbers[]){
  printf("give me 6 numbers boiiiii\n # : ");
  scanf("%d %d %d %d %d %d", &numbers[0], &numbers[1], &numbers[2], &numbers[3], &numbers[4], &numbers[5]);
  return;
}


int main()
{
  /*
  if (argc != 7)
  {
    printf("Need 6 numbers\n");
    exit(1);
  }
  */
  //int nums[6];
  int i;
  // my vars
  FILE *fifoPipe = 0;
  int player = 0;
  int computer = 0;
  //char t = 't';
  //char h = 'h';
  //char l = 'l';
  int numbers[6] = {0};
  // open the fifo file
  fifoPipe = fopen("/home/chrisg/Desktop/war/in", "w");
//printf("\ntest after fopen\n");
  // load up numbers (target)
  getSequence(numbers);
//printf("\ntest after request\n");
  /*
  for (i=0; i<6; i++){
    printf("number %d: %d\n", i+1, numbers[i]);
  }
  */
  /*
  for (i=1; i < 6; i++)
    nums[i-1] = atoi(argv[i]);
  */
  // check entire (approx) entire seed space
  int done = 0;
  unsigned int seed;
  unsigned int update = 0;
  // for (seed=0; seed < RAND_MAX && !done; seed++)
//printf("\ntest before seed search loop\n");
  for (seed=(time(0)-1000); seed < RAND_MAX && !done; seed++)
  {
    srand(seed);
    done = 1;
    if (update == 5000)
    {
      printf("Testing: %u\n", seed);
      update = 0;
    }
    for (i=0; i < 6 && done; i++)
    {
      //if (rand() % 13 == nums[i])
      if (rand() % 13 == numbers[i])
        done = 1;
      else
         done = 0;
    }
    update++;
  }

//printf("\ntest after seed search loop\n");
  ////--seed;
  //printf("-----------------------------------\n");
  printf("Seed %u produces:\n", --seed); // subtract 1 from seed++ above
  for (i=0; i < 1000; i++){
    //printf("%d ", nums[i]);
    //printf("\n");
    computer=rand()%13;
    player=rand()%13;
    if(player==computer){
      //fwrite(&t, 1, 1, fifoPipe);
      fprintf(fifoPipe, "t\n");
    }
    else if(player>computer){
      //fwrite(&h, 1, 1, fifoPipe);
      fprintf(fifoPipe, "h\n");
    }
    else if(player<computer){
      //fwrite(&l, 1, 1, fifoPipe); 
      fprintf(fifoPipe, "l\n");
    }
    delay(1);
  }    
fclose(fifoPipe);
return 0;
}
