#include <stdio.h>
int main()
{
    int a, b, *ptr1 = &a, *ptr2 = &b;

    printf("first no. here\n");
    scanf("%d", ptr1);
    printf("second no. here\n");
    scanf("%d", ptr2);

    if (*ptr1 > *ptr2)
    {
        printf("first no. is greater");
    }
    else if (*ptr1 == *ptr2)
        
    {
        printf("both no. are equal");
    }
    else
    {
        printf("second no. is greater");
    }
}