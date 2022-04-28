//
// Created by onglu on 2022/4/26.
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
string s;
void work() {
    cin >> s;
    n = s.size();
    for(int i = 0; i < 26; i++) a[i] = 0;
    for(int i = 0; i < n; i++) a[s[i] - 'a']++;
    int l = 0, r = 26;
    while(l <= r) {
        while(l <= r && a[l] % 2 == 0) l++;
        while(r >= l && a[r] % 2 == 0) r--;
        if(a[l] % 2 == 0 || a[r] % 2 == 0) continue;
        a[l] += 1;
        a[r] -= 1;
        l += 1;
        r -= 1;
    }
    string t = "";
    for(int i = 0; i < 26; i++) {
        for(int j = 1; j * 2 <= a[i]; j++) {
            t += (i) + 'a';
        }
    }
    cout << t;
    for(int i = 0; i < 26; i++) if(a[i] % 2 == 1) cout << (char) ((i) + 'a');
    std::reverse(t.begin(), t.end());
    cout << t << endl;
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Case = 1;
//    cin >> Case;
    while (Case--) work();
    return 0;
}