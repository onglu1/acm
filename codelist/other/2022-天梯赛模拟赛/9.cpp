//
// Created by onglu on 2022/4/18.
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
const int N = 2e5 + 1009;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309;
int n, m, a[N];

string name[N];
map<string, int> M;
void work() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> name[i];
    for(int i = 0; i < n; i += m) {
        for(int j = i + m; j > i; j--) {
            cin >> M[name[j]];
        }
    }
    int q;
    cin >> q;
    while(q--) {
        string s;
        cin >> s;
        if(M.count(s)) cout << M[s] << endl;
        else cout << "Wrong Number" << endl;
    }
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