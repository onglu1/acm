//
// Created by onglu on 2022/3/16.
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
const int N = 109;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309
int n, m;
struct node {
    string name;
    int cnt;
    int tot;
} a[N];
vector<int> v;
void work() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].name;
        cin >> a[i].cnt;
        v.clear();
        for(int j = 1; j <= a[i].cnt; j++) {
            int x;
            cin >> x;
            v.push_back(x);
        }
        sort(all(v));
        v.resize(unique(all(v)) - v.begin());
        a[i].tot = v.size();
    }
    sort(a + 1, a + 1 + n, [](const node &a, const node &b) {
        if(a.tot != b.tot) return a.tot > b.tot;
        else return 1.0 * a.cnt / a.tot < 1.0 * b.cnt / b.tot;
    });
    cout << a[1].name << " ";
    if(2 <= n) cout << a[2].name;
    else cout << "-";
    cout << " ";
    if(3 <= n) cout << a[3].name;
    else cout << "-";
    cout << endl;
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