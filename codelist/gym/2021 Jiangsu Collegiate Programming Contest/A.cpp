//
// Created by onglu on 2022/5/27.
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
//const int N = 309;
int n, m, a[N], b[N], f[5];
int read() {
    int f = 1, num; char c;
    while(c = getchar(),!isdigit(c)) if(c == '-') f = -1; num = c - '0';
    while(c = getchar(), isdigit(c)) num = num * 10 + c - '0';
    return f * num;
}

int work() {
    n = read();
    for(int i = 1; i <= n; i++) a[i] = read();
    for(int i = 1; i <= n; i++) b[i] = read();
    for(int i = 1; i <= n; i++) {
        if(!(f[a[i]] ^ f[b[i]])) {
            return false;
        }
    }
    if(f[a[n]] != 0) return false;
    return true;
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    f[1] = f[2] = 1;
    f[3] = f[4] = 0;
    int Case = read();
    while(Case--) printf("%s\n", work() ? "YES" : "NO");
    return 0;
}