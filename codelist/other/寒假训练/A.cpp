#include <bits/stdc++.h>
#define int long long
#define x first
#define y second
#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int N = 2e5 + 1009;
int n, m, pre[N], siz[N];
int fid(int x) {
    return pre[x] == x ? x : (pre[x] = fid(pre[x]));
}
struct node {
    int y, id;
};
vector<pair<int, int> > a;
bool operator<(const node &x, const node &y) {
    if(x.y == y.y) return x.id < y.id;
    return x.y < y.y;
}
multiset<node> S;
signed main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) pre[i] = i;
    for(int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        a.push_back({x + y, x - y});
    }
    sort(a.begin(), a.end());
//    for(auto x : a) {
//        cout << x.first << " " << x.second << endl;
//    }
    int l = 0;
    for(int i = 0; i < a.size(); i++) {
        while(l < i && a[l].x < a[i].x - m) {
            S.erase({a[l].y, l});
            l++;
        }
        multiset<node> :: iterator it = S.lower_bound({a[i].y, i});
//        if(i == 2) cout << (*it).id << endl;
//        cout << i << " " << l << " " << S.size() << endl;
        if(it != S.end()) {
//            cout << i << " 1 " << (*it).id << endl;
            if(abs((*it).y - a[i].y) <= m)
                pre[fid((*it).id)] = fid(i);
        }
        if(it != S.begin()) {
            it--;
//            cout << i << " 2 " << (*it).id << endl;
            if(abs((*it).y - a[i].y) <= m)
                pre[fid((*it).id)] = fid(i);
        }
        S.insert({a[i].y, i});
    }
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(fid(i) == i) {
            cnt++;
        }
        siz[fid(i)]++;
    }
    int maxsize = 0;
    for(int i = 0; i < n; i++) {
        maxsize = max(maxsize, siz[i]);
    }
    cout << cnt << " " << maxsize << endl;
    return 0;
}