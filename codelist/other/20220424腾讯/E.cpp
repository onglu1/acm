#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2009;
int n, m, a[N];
int f[N][N];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    // 因为可能有负值，所以初始化为最小值, 0xcfcfcfcfcfcfcfcf是一个很大的负数
    memset(f, 0xcf, sizeof(f));
    // f[i][j]表示到第i天，购买了j个股票的最大余额
    // 0天买0个股票，剩余m块钱
    f[0][0] = m;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < i; j++) {
            // 考虑卖出股票，前提是要j>0，也就是股票有剩余
            // 转移：当前天股票-1, 剩余的钱+a[i]
            if(j > 0)
                f[i][j - 1] = max(f[i][j - 1], f[i - 1][j] + a[i]);
            // 买入股票，前提是买完股票后剩余钱>=0
            // 转移：股票数+1，剩余的钱-a[i]
            if(f[i - 1][j] - a[i] >= 0)
                f[i][j + 1] = max(f[i][j + 1], f[i - 1][j] - a[i]);
            // 啥也不操作，直接复制
            f[i][j] = max(f[i][j], f[i - 1][j]);
        }
    }
    int ans = 0;
    // 剩余i个股票，在最后一天全部卖完，记录最大答案
    for(int i = 0; i <= n; i++)
        ans = max(ans, f[n][i] + i * a[n]);
    cout << ans << endl;
    return 0;
}

