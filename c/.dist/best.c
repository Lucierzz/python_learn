
#include <stdio.h>

#define max 20
// ayush soni 202051043
int main()
{
    int fit [max], q[max], t[max], i, j, nq, nt, omk, low = 10000;
    static int qt[max], l[max];
  
    printf("\nnumber of blocks:");
    scanf("%d", &nq);
    printf("number of files:");
    scanf("%d", &nt);
    printf("\nsize of the blocks:-\n");
    for (i = 1; i <= nq; i++)
    {
        printf("Block %d:", i);
        scanf("%d", &q[i]);
    }
    printf("size of the files :-\n");
    for (i = 1; i <= nt; i++)
    {
        printf("File %d:", i);
        scanf("%d", &t[i]);
    }
    for (i = 1; i <= nt; i++)
    {
        for (j = 1; j <= nq; j++)
        {
            if (qt[j] != 1)
            {
                omk = q[j] - t[i];
                if (omk >= 0)
                    if (low > omk)
                    {
                        l[i] = j;

                        low = omk;
                    }
            }
        }

        fit [i] = low;
        qt[l[i]] = 1;
        low = 10000;
    }
    printf("File No\tFile Size \tBlock No\tBlock Size\tFragment");
    for (i = 1; i <= nt && l[i] != 0; i++)
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d", i, t[i], l[i], q[l[i]], fit[i]);
    
    return 0;
    
}