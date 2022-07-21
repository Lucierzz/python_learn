#include "stdio.h"
#include "pthread.h"
#include "unistd.h"
#include "string.h"
//to handle memory barrier
#define varMemory __sync_synchronize()
#define thrCount 10
//declaring a variable using volatile
volatile int token[thrCount];
volatile int entering[thrCount];
volatile int bakery;
void lock(int thread){
    //before entering, var value is setting as true.
    entering[thrCount] = 1;
    varMemory;
    int max_tno = 0;
    //finding MAX token number from available threads.
    for (int i = 0; i < thrCount; ++i) {
  
        int num = token[i];
        max_tno = num > max_tno ? num : max_tno;
    }
    //increment o by +1.
    token[thread] = max_tno +1;
    varMemory;
    entering[thread] = 0;
    varMemory;
    //Entering in the store
    for (int j =0; j<thrCount; ++j) {
        while (entering[j]) {
        }
        varMemory;
  
        while (token[j] != 0 && (token[j]< token[thread]|| (token[j]== token[thread]&& j < thread))) {
        }
    }
}

void unlock(int thread){
    varMemory;
    token[thread] = 0;
}
//Critical section
void accbakery(int thread){
    if (bakery != 0) {
        printf("Customer with token no. %d was in the bakery and %d is using bakery.\n",p_id,bakery);
    }
  
    bakery=thread;
    printf("Customer %d is in the bakery\n", thread);
  varMemory;
    sleep(3);
    bakery = 0;
}
 
void* thread_block(void* arg)
{
    long thread = (long)arg;
    lock(thread);
    accbakery(p_id);
    unlock(p_id);
    return NULL;
}
  
int main(int argc, char** argv)
{
    for (int i = 0; i < thrCount; ++i){
		token[i] = 0;
		entering[i] = 0;
	}
    bakery = 0;
    pthread_t threads[thrCount];
  
    for (int i = 0; i < thrCount; ++i) {
        pthread_create(&threads[i], NULL, &thread_block, (void*)((long)i));
    }
  
    for (int i = 0; i < thrCount; ++i) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}