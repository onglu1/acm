#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 1009;
int n = 6;
int a[] = {0, 30, 35, 15, 5, 10, 20, 25};
int f[109][109], sp[109][109];
void print(int l, int r) {
    if(r - l == 1) {

    }
}
void work() {
    printf("Matrix : \n");
    for(int i = 1; i <= n; i++) f[i][i] = 0;
    for(int len = 2; len <= n; len++) {
        for(int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            f[i][j] = 0x3f3f3f3f;
            for(int k = i; k < j; k++) {
                if(f[i][k] + f[k + 1][j] + a[i] * a[j + 1] * a[k + 1] < f[i][j]) {
                    f[i][j] = f[i][k] + f[k + 1][j] + a[i] * a[j + 1] * a[k + 1];
                    sp[i][j] = k;
                }
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            printf("% 10d ", f[i][j]);
        }
        printf("\n");
    }
    print(1, n);
}

signed main() {
    work();
    return 0;
}