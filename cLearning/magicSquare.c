#include <stdio.h>
#define maxn 105
int matx[maxn][maxn];
int judge[maxn];
int count = 0;

void typeMagSqu(int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &matx[i][j]);
        }
    }
}

int judgeMagSqu(int N) {
    int mSum = 0, sSum = 0;
    for (int i = 0; i < N; i++) {
        int rowSum = 0, lineSum = 0;
        mSum += matx[i][i];
        sSum += matx[i][N - i - 1];
        for (int j = 0; j < N; j++) {
            rowSum += matx[i][j];
            lineSum += matx[j][i];
        }
        judge[count++] = rowSum;
        judge[count++] = lineSum;
    }
    judge[count++] = mSum;
    judge[count++] = sSum;
    for (int i = 0; i < 2 * N + 2 - 1; i++) {
        if (judge[i] != judge[i + 1]) {
            return 0;
        }
    }
    return 1;
}

void printMatx(int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%-4d", matx[i][j]);
        }
        putchar('\n');
    }
}

int main() {
    int N = 0;
    scanf("%d", &N);
    typeMagSqu(N);
    int result = judgeMagSqu(N);
    if (result) {
        printf("Yes!\n");
    } else {
        printf("No!\n");
    }
    printMatx(N);
    return 0;
}