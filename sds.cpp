//
// Created by onglu on 2022/3/7.
//

#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()

#define endl '\n'
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
//#define int long long
using namespace std;
const int N = 2e6 + 1009;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309
int n, m, a[N];

int maxlen(string s) {
    int f[N][N];
    int n = s.size();
    for(int i = 1; i <= n; i++) {
        //单个字符是回文串，为了方便，空字符串也定义成回文串
        f[i][i] = f[i][i - 1] = 1;
    }
    int ans = 0;
    //单个字符就是长度为1，已经算过了，从2开始
    for(int len = 2; len <= n; len++) {
        //右端点是i + len - 1，要小于长度
        for(int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            //数组保存的时候向右位移了一格，所以要-1
            if(s[i - 1] == s[j - 1]) {
                f[i][j] = f[i + 1][j - 1];
            } else f[i][j] = 0;
            //如果是回文串，当前一定就是最长的那个（因为长度递增
            if(f[i][j]) ans = len;
        }
    }
    return ans;

}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif

    return 0;
}