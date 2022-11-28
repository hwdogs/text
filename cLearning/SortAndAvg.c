#include <stdio.h>
#define maxn 105
int ans[maxn];

float typeArray(int n) {
    float sum;
    for (int i = 0; i < n; i++) {
        scanf("%d", &ans[i]);
        sum += ans[i];
        for (int j = i; j > 0; j--) {
            if (ans[j] > ans[j - 1]) {
                int temp = ans[j];
                ans[j] = ans[j - 1];
                ans[j - 1] = temp;
            }
        }
    }
    return sum / n;
}

int main() {
    int n;
    scanf("%d", &n);
    float avg = typeArray(n);
    printf("%d %d %.2f", ans[0], ans[n - 1], avg);
    return 0;
}