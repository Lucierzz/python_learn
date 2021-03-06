#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

#define N     10
#define TRUE    1
#define FALSE   0

int s = 10;
int input[N];
int number[N];

int max(int number[N]) {
    int i = 0;
    int maximum = number[0];
    for (i = 0; i < N; i++) {
        if (maximum < number[i])
            maximum = number[i];
        }
    return maximum;
    }

void lock(int i) {
    int j = 0;
    input[i] = TRUE;
    number[i] = 1 + max(number);
    input[i] = FALSE;
    for (j = 0; j < N; j++) {
        while (input[j]);
        while (number[j] != 0 && (number[j] < number[i] || (number[i] == number[j]) && j < i)) {}
    }
}

void op(int i) {
    number[i] = 0;
}

void *fn(void *integer) 
{
    int i = (int) integer;
    lock(i);
    s++;
    printf("%d is global  \n",s);
    
    op(i);
}    


int main()
{
    int th[N];
    void *fn(void *);
    pthread_t thread[N];
    int i = 0; 
    for (i = 0; i < N; i++) {
        th[i] = pthread_create(&thread[i], NULL, fn, (void *)i); 
        pthread_join(thread[i], NULL);
    }
    return EXIT_SUCCESS;
}