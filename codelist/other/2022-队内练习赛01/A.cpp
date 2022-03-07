//
// Created by onglu on 2022/3/2.
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
const int N = 39;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309
int n, m, a[N];
struct node {
    string name;
    int v;
} t[N];
vector<int> v[N];
map<int, int> M;
void work() {
    M.clear();
    for(int i = 1; i <= n; i++) {
        cin >> t[i].name;
        cin >> m;
        v[i].clear();
        for(int j = 1; j <= m; j++) {
            int x;
            cin >> x;
            v[i].push_back(x);
            M[x]++;
        }
    }
    for(int i = 1; i <= n; i++) {
        int p = 0;
        for(auto x : v[i]) {
            if(M[x] == n) p += 1;
            else p += n - M[x] + 1;
        }
        t[i].v = p;
    }
    sort(t + 1, t + 1 + n, [](const node &a, const node &b) {
        if(a.v != b.v) return a.v < b.v;
        else return a.name < b.name;
    });
    cout << t[1].v << " " << t[1].name << endl;
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(1) {
        cin >> n;
        if(n == 0) break;
        work();
    }
    return 0;
}