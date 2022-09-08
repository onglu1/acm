//
// Created by onglu on 2022/5/13.
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
int n, m, a[N];
int s0[N], s[N];
char c[N];
int sum(int l, int r) {
    return s0[r] - s0[l - 1];
}
int check(int mid) {
    int cnt = 0, j;
    for(j = n; j >= 0; j--) {
        cnt += c[j] == '1';
        if(cnt > mid) {
            j += 1;
            cnt -= 1;
            break;
        }
    }
    if(sum(1, j - 1) <= mid) return true;
    for(int i = 1; i <= n; i++) {
        if(c[i] == '1') cnt += 1;
        while(j <= n && cnt > mid) {
            cnt -= c[j] == '1';
            j += 1;
        }
        if(cnt > mid) return false;
        if(sum(i + 1, j - 1) <= mid) return true;
    }
    return false;
}
void work() {
    cin >> (c + 1);
    n = strlen(c + 1);
    for(int i = 1; i <= n; i++) {
        s0[i] = s0[i - 1] + (c[i] == '0');
        s[i] = s[i - 1] + (c[i] == '1');
    }
    int l = 0, r = n;
    while(l <= r) {
        if(check(Mid)) r = Mid - 1;
        else l = Mid + 1;
    }
    cout << l << endl;
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Case = 1;
    cin >> Case;
    while (Case--) work();
    return 0;
}