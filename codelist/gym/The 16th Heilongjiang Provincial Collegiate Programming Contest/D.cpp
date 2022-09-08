#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1000003;
const int N = 309;
int n, a[N], prod[N][N], f[N][N];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) {
        prod[i][i] = a[i] % mod;
        for(int j = i + 1; j <= n; j++) {
            prod[i][j] = prod[i][j - 1] * a[j] % mod;
        }
    }
    memset(f, 0, sizeof(f));
//    cout << prod[2][2] << " " << prod[3][3] << endl;
//    for(int i = 1; i <= n; i++) {
//        f[i][i] = 0;
//    }
    for(int len = 2; len <= n; len++) {
        for(int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            for(int k = i; k < j; k++) {
//                if(i == 2 && j == 3) cout << k << " " << (prod[i][k] - prod[k][j]) * (prod[i][k] - prod[k][j]) << endl;
                f[i][j] = max(f[i][j], f[i][k] + f[k + 1][j] + (prod[i][k] - prod[k + 1][j]) * (prod[i][k] - prod[k + 1][j]));
            }
        }
    }
//    cout << f[2][3] << endl;
    cout << f[1][n] << endl;
    return 0;
}
