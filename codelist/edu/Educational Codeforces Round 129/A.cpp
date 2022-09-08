//
// Created by onglu on 2022/5/23.
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
int n, m;
vector<int> a, b;
void work() {
    cin >> n;
    a = vector<int>(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    cin >> m;
    b = vector<int>(m);
    for(int i = 0; i < m; i++) cin >> b[i];
    std::sort(a.begin(), a.end());
    std::reverse(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    std::reverse(b.begin(), b.end());
    if(a[0] > b[0]) cout << "Alice\nAlice" << endl;
    else if(a[0] < b[0]) cout << "Bob\nBob" << endl;
    else cout << "Alice\nBob" << endl;
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
    while(Case--) work();
    return 0;
}