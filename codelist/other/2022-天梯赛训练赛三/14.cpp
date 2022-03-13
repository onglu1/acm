//
// Created by onglu on 2022/3/12.
//

#include <bits/stdc++.h>
#define ull unsigned long long
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
ull pw[N], h[N];
string s;
map<ull, int> M;
ull query(int l, int r) {
    if(r <= l) return 0;
    return h[l] - h[r] * pw[r - l];
}
void work() {
    pw[0] = 1;
    for(int i = 1; i < N; i++) {
        pw[i] = pw[i - 1] * 135;
    }
    cin >> s;
    n = s.size();
    h[n] = 0;
    for(int i = n - 1; i >= 0; i--) {
        h[i] = h[i + 1] * 135ull + s[i];
    }
    int ans = 1;
    M.clear();
    for(int i = 0; i < n; i++) {
        ull hs = query(0, i) + query(i + 1, n) * pw[i];
        if(M.count(hs) == 0) {
            ans++;
            M[hs] = 1;
        }
    }
    M.clear();
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            ull hs = query(0, i) + query(i + 1, j) * pw[i] + query(j + 1, n) * pw[j - 1];
            if(M.count(hs) == 0) {
                ans++;
                M[hs] = 1;
            }
        }
    }
    M.clear();
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            for(int k = j + 1; k < n; k++) {
                ull hs = query(0, i) + query(i + 1, j) * pw[i] + query(j + 1, k) * pw[j - 1] + query(k + 1, n) * pw[k - 2];
                if(M.count(hs) == 0) {
                    ans++;
                    M[hs] = 1;
                }
            }
        }
    }
    cout << ans << endl;
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    work();
    return 0;
}