#include <bits/stdc++.h>

using namespace std;
// 计算第n项结果对1e9+7取模后的值
const long long Mod = 1000000007;
struct mat {
    long long g[2][2];
    int x;
    int y;
} stdx, stdy;
long long n;
long long gg;

mat multi(mat a, mat b);

mat Pow(mat A, long long p);

void init();

int main() {
    cin >> n;
    mat A;
    A.x = 2; A.y = 2;
    A.g[0][0] = 1; A.g[0][1] = 1;
    A.g[1][0] = 1; A.g[1][1] = 0;
    A = Pow(A, n - 1);
    mat ans;
    ans.x = 2; ans.y = 1;
    ans.g[0][0] = ans.g[1][0] = 1;
    ans = multi(A, ans);
    cout << ans.g[0][0] << endl;
    return 0;
}

mat Pow(mat A, long long p) {
    mat ans = A;
    for (int i = 0; i < A.x; i++)
        for (int j = 0; j < A.y; j++)
            ans.g[i][j] = 0;
    for (int i = 0; i < A.x; i++)
        ans.g[i][i] = 1;
    while (p) {
        if (p & 1) ans = multi(A, ans);
        A = multi(A, A);
        p >>= 1;
    }
    return ans;
}

mat multi(mat a, mat b) {
    mat c;
    c.x = a.x;
    c.y = b.y;
    for (int i = 0; i < c.x; i++)
        for (int j = 0; j < c.y; j++)
            c.g[i][j] = 0;
    for (int i = 0; i < c.x; i++)
        for (int j = 0; j < c.y; j++)
            for (int k = 0; k < a.y; k++)
                c.g[i][j] = (c.g[i][j] + a.g[i][k] * b.g[k][j]) % Mod;
    return c;
}
