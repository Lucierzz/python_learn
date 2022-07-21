#include <stdio.h>
//  ayush soni 202051043
int main()
{
      int memory[10][4], process[10][5];
      int a, j, omk = 0, qt = 0;
      printf("\nNumber of Processes:\t");
      scanf("%d", &omk);
      printf("\nSize of Process\n");
      for(int a = 0; a < omk; a++)
      {
            printf("\nEnter Size of Process %d:\t", a + 1);
            scanf("%d", &process[a][0]);
            process[a][1] = 0;
            process[a][2] = a;
      }
      printf("\nTotal Memory Blocks:\t");
      scanf("%d", &qt);
      printf("\nthe Size of Each Block:\n");
      for(a = 0; a <omk; a++)
      {
            printf("\nSize of Block %d:\t", a + 1);
            scanf("%d", &memory[a][0]);
            memory[a][1] = 0;
      }
      for(a = 0; a < omk; a++)
      {
            while(j < qt)
            {
                  if(memory[j][1] == 0 && process[a][0] <= memory[j][0])
                  {
                        process[a][1] = 1;
                        memory[j][1] = 1;
                        printf("\nProcess [%d] Allocated to Memory Block:\t%d", a + 1, j + 1);
                        break;
                  }
                  j++;
            }
      }
      for(a = 0; a < qt; a++)
      {
            if(process[a][1] == 0)
            {
                  printf("\nProcess [%d] not allocated\n", a + 1);
            }
      }
      printf("\n");
      return 0;
}