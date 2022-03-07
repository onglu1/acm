//
// Created by onglu on 2022/2/27.
//

#include <bits/stdc++.h>
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
int base = 0;
int n, m, a[N];
vector<pair<int, int> > v;
vector<int> d;
void reverse(int p) {
    for(int i = 1; i <= p; i++) {
        v.push_back({base + p + i - 1, a[i]});
    }
    d.push_back(p * 2);
    base += p * 2;
    reverse(a + 1, a + 1 + p);
}
void work() {
    cin >> n;
    base = 0;`
    v.clear();
    d.clear();
    for(int i = 1; i <= n; i++) cin >> a[i];
    map<int, int> M;
    for(int i = 1; i <= n; i++) {
        M[a[i]]++;
    }
    for(auto x : M) {
//        cout << x.first << " " << x.second << endl;
        if(x.second % 2 != 0) {
            cout << "-1" << endl;
            return ;
        }
    }
    for(int i = 1; i <= n; i++) {
        int pos = 1;
        for(int j = 2; j <= n - i + 1; j++) {
            if(a[j] > a[pos]) {
                pos = j;
            }
        }
        reverse(pos);
        reverse(n - i + 1);
    }
    for(int i = 1; i <= n / 2; i++) {
        d.push_back(2);
    }
    cout << v.size() << endl;
    for(auto x : v) {
        cout << x.first << " " << x.second << endl;
    }
    cout << d.size() << endl;
    for(auto x : d) {
        cout << x << " ";
    }
    cout << endl;
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Case = 0;
    cin >> Case;
    while (Case--) work();
    return 0;
}