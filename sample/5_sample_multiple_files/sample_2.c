#include "sample.h"

void _exit(int status) {
    while(1) {
        ;
    }
}


void external_function1() {
    int lotsOfMemory[100000];
    int sum = 0;
    for (int i = 0; i < 100000; i++) {
        lotsOfMemory[i] = i;
    }
    for (int i = 0; i < 100000; i++) {
        sum += lotsOfMemory[i];
    }
    return sum;
}


void external_function2() {
    int little_memory[100];
    int sum = 0;
    for (int i = 0; i < 100; i++) {
        little_memory[i] = i;
    }
    for (int i = 0; i < 100; i++) {
        sum += little_memory[i];
    }
    return sum;
}