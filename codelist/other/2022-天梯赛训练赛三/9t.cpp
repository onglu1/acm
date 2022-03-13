//
// Created by onglu on 2022/3/12.
//

#include <bits/stdc++.h>
#define int long long
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
int n, a[N];
int m, clost = 1ll << 60;
map<int, string> M;
void work() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        string s;
        int p;
        cin >> s >> p;
        M[p * n * 2] = s;
        m += p * n * 2;
    }
    string name = "";
    m /= n;
    m /= 2;
    for(auto x : M) {
//        cout << x.first << " " << x.second << " " << m << endl;
//        cout << clost << endl;
        if(abs(x.first - m) < clost) {
            clost = abs(x.first - m);
            name = x.second;
        }
    }
    cout << m / n / 2 << " " << name;
//    printf("%d %s", m / n / 2, name.c_str());
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