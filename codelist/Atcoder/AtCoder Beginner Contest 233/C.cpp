#include <bits/stdc++.h>
#define int long long
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
 
using namespace std;
int n, x, cnt;
char c[100009];
vector<int> v[100009];
void dfs(int d, int prod) {
    if(x % prod != 0) return ;
    if(d == n + 1) {
        if(prod == x) {
            cnt++;
        }
        return ;
    }
    for(int i = 0; i < v[d].size(); i++) {
        if(log(prod) + log(v[d][i]) > log(x) + log(10)) {
            continue;
        }
        dfs(d + 1, prod * v[d][i]);
    }
}
void work() {
    cin >> n >> x;
    for(int i = 1; i <= n; i++) {
        int l;
        cin >> l;
        v[i].clear();
        for(int j = 1; j <= l; j++) {
            int p;
            cin >> p;
            v[i].push_back(p);
        }
    }
    dfs(1, 1);
    cout << cnt << endl;
}
 
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int Case = 1;
    while (Case--) work();
    return 0;
}