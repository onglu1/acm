
//
// Created by onglu on 2022/3/4.
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
struct node {
    int x, y, t;
};
int n, m, a[N], col[N], pos[N];
vector<node> v[N];
int pre[N];
int fid(int x) {
    return pre[x] == x ? x : (pre[x] = fid(pre[x]));
}
int head[N], nxt[N], ver[N], in[N], tot = 1;
void add(int x, int y) {
    nxt[++tot] = head[x]; head[x] = tot; ver[tot] = y; in[y]++;
}
void work() {
    cin >> n >> m;
    for(int i = 1; i <= 2 * n; i++) pre[i] = i;
    for(int i = 1; i <= m; i++) {
        int t, x, y;
        cin >> t >> x >> y;
        v[x].push_back({x, y, t});
        if(fid(x) == fid(y) || fid(x + n) == fid(y + n)) {
            cout << "NO" << endl;
            return ;
        }
        pre[fid(x + n)] = fid(y);
        pre[fid(y + n)] = fid(x);
    }
    memset(col, -1, sizeof(col));
    //1代表向右
    for(int i = 1; i <= n; i++) {
        if(col[fid(i)] != -1) col[i] = col[fid(i)];
        else {
            col[fid(i)] = col[i] = 1;
            col[fid(i + n)] = 2;
        }
    }
    for(int i = 1; i <= n; i++) {
        for(auto e : v[i]) {
            if(e.t == 1) {
                if(col[e.x] == 1) add(e.y, e.x);
                else add(e.x, e.y);
            } else {
                if(col[e.x] == 1) add(e.x, e.y);
                else add(e.y, e.x);
            }
        }
    }
    queue<int> q;
    int cnt = 0, tim = 0;
    for(int i = 1; i <= n; i++) {
        if(in[i] == 0) {
            q.push(i);
        }
    }
    while(q.size()) {
        int x = q.front(); q.pop();
        pos[x] = ++tim;
        cnt++;
        for(int i = head[x]; i; i = nxt[i]) {
            in[ver[i]]--;
            if(in[ver[i]] == 0) {
                q.push(ver[i]);
            }
        }
    }
    if(cnt != n) cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        for(int i = 1; i <= n; i++) {
            if(col[i] == 1) cout << 'R' << " ";
            else cout << 'L' << " ";
            cout << pos[i] << endl;
        }
    }
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
/*
 * 向左集合和向右集合，有连边的一定在不同集合中
 * 合并两个序列，每个条件相当于a>b或者a<b的条件
 *
 *
 */