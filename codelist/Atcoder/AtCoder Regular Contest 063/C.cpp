#include <bits/stdc++.h>

#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int N = 2e5 + 1009;
struct node {
    int x, v;
};
bool operator<(const node &a, const node &b) {
    return a.v > b.v;
}
int n, k, val[N];
vector<int> ver[N];
priority_queue<node> q;
signed main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        ver[x].push_back(y);
        ver[y].push_back(x);
    }
    cin >> k;
    memset(val, 0x3f, sizeof(val));
    for(int i = 1; i <= k; i++) {
        int x, v;
        cin >> x >> v;
        val[x] = v;
        q.push({x, v});
    }
    while(q.size()) {
        int x = q.top().x, v = q.top().v;
        q.pop();
        for(auto y : ver[x]) {
            if(val[y] != 0x3f3f3f3f) {
                if(abs(val[y] - val[x]) != 1) {
                    cout << "no" << endl;
                    return 0;
                }
            } else {
                val[y] = val[x] + 1;
                q.push({y, val[y]});
            }
        }
    }
    cout << "yes" << endl;
    for(int i = 1; i <= n; i++) {
        cout << val[i] << " ";
    }
    cout << endl;
    return 0;
}