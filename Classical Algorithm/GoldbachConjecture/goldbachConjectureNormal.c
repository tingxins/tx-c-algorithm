#include<stdio.h>

int isPrime(int i) {
    int j;
    if (i <= 1) return 0;
    if (i == 2) return 1;
    for (j = 2; j < i; j ++) {
        if (i % j == 0) {
            return 0;
        }else if(i != j + 1) {
            continue;
        }else {
            return 1;
        }
        
    }
}


int main() {
    do {
        printf("please enter a number:");
        int number = 0;
        scanf("%d", &number);
        int i, j, k;
        for (int i = 4; i <= number; i += 2) {
            for (k = 2; k<= i/2; k ++) {
                j = i - k;
                if (isPrime(k)) {
                    if (isPrime(j)) {
                        printf("%d=%d+%d\n",i, k, j);
                }
            }
        }
    }while (1);
    return 0;
}
