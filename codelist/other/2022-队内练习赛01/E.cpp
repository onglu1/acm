//
// Created by onglu on 2022/3/2.
//

#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define int long long
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
int n, m, k, l;
struct node {
    string name;
    int v;
};
bool cmp(const node &a, const node &b) {
    if(a.v != b.v) return a.v > b.v;
    else return a.name < b.name;
}
vector<node> v, t;
map<string, int> M;
int check(int x) {
    int p = k - x;
    if(t.size() <= p) return true;
    int cnt = 0;
    for(int i = 0; i < x; i++) {
        if(v[i].v > t[p].v) continue;
        else if(v[i].name < t[p].name){
            cnt += t[p].v - v[i].v;
        } else {
            cnt += t[p].v - v[i].v + 1;
        }
    }
    return cnt <= l;
}
void work() {
    M.clear();
    v.clear();
    t.clear();
    for(int i = 1; i <= n; i++) {
        string s;
        int v;
        cin >> s >> v;
        M[s] = v;
    }
    for(int i = 1; i <= m; i++) {
        string s;
        cin >> s;
        v.push_back({s, M[s]});
        M.erase(M.find(s));
    }
    for(auto x : M) {
        t.push_back({x.first, x.second});
    }
    sort(all(t), cmp);
    sort(all(v), cmp);
    int l = 0, r = min(k, (int)v.size());
    while(l <= r) {
        if(check(Mid)) l = Mid + 1;
        else r = Mid - 1;
    }
    cout << r << endl;
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n >> m >> k >> l) {
        if(n + m + k + l == 0) break;
        work();
    }
    return 0;
}