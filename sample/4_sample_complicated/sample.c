#include "sample.h"

void _exit(int status) {
    while(1) {
        ;
    }
}

void sample_function() {
    #if PARENT_CONFIG_MUST_BE_ONE == true
        #if TEST_NESTED_DEFINE == 1
        do_overflow();
        #elif TEST_NESTED_DEFINE == 2 && SIBLING_CONFIG == 1
        do_overflow_ifndef();
        #endif
    #else
        allocate_little_bytes();
    #endif
    return;
}

void allocate_little_bytes() {
    int little_bytes[100];
    for (int i = 0; i < 100; i++) {
        little_bytes[i] = i;
    }
    return;
}

int do_overflow() {
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

int do_overflow_ifndef() {
    int lotsOfMemory[200000];
    int sum = 0;
    for (int i = 0; i < 200000; i++) {
        lotsOfMemory[i] = i;
    }
    for (int i = 0; i < 200000; i++) {
        sum += lotsOfMemory[i];
    }
    return sum;
}


int main(void) {
    sample_function();
    return 0;
}