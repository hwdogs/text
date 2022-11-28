#include <stdio.h>
#define maxn 105
int table[maxn];

void typeTable() {
    int score = 0;
    for (int i = 0; i < 40; i++) {
        scanf("%d", &score);
        table[score]++;
    }
}

void printTable() {
    printf("Grade Count  Histogram\n");
    for (int i = 1; i < 11; i++) {
        printf("%d\t%d\t", i, table[i]);
        for (int j = 0; j < table[i]; j++) {
            printf("*");
        }
        putchar('\n');
    }
}

int main() {
    typeTable();
    printTable();
    return 0;
}