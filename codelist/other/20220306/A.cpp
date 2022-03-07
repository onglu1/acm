//
// Created by onglu on 2022/3/6.
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


signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    int preid = 0, d;
    char c;
    vector<int> v[2];
    while(~scanf("%d/%c", &d, &c)) {
        static int cnt = 0;
        cnt++;
        if(cnt == 1) {
            v[0].push_back(d);
        } else {
            if(c == 'N')
                preid = 1 - preid;
            v[preid].push_back(d);
        }
    }
    sort(v[0].begin(), v[0].end());
    sort(v[1].begin(), v[1].end());
    v[0].resize(unique(v[0].begin(), v[0].end()) - v[0].begin());
    v[1].resize(unique(v[1].begin(), v[1].end()) - v[1].begin());
    if(v[0].empty()) {
        swap(v[0], v[1]);
    }
    if(!v[0].empty() && ! v[1].empty()) {
        if(v[0][0] > v[1][0]) {
            swap(v[0], v[1]);
        }
    }
    for(auto x : v[0]) printf("%d ", x);
    printf("\n");
    if(v[1].size()) {
        for(auto x : v[1]) printf("%d ", x);
        printf("\n");
    }
    return 0;
}