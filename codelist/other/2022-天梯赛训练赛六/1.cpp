//
// Created by onglu on 2022/3/23.
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
//const int N = 309
int n, m, a[N];

void work() {
    int cnt = 0;
    cin >> n >> m;
    while(1) {
        int tn = n;
        vector<int> v;
        v.push_back(tn % 10); tn /= 10;
        v.push_back(tn % 10); tn /= 10;
        v.push_back(tn % 10); tn /= 10;
        v.push_back(tn % 10); tn /= 10;
        std::sort(v.begin(), v.end());
        v.resize(std::unique(v.begin(), v.end()) - v.begin());
        if(v.size() == m) {
            printf("%d %04d\n", cnt, n);
            break;
        }
        cnt++;
        n++;
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
//  cin >> Case;
    while (Case--) work();
    return 0;
}