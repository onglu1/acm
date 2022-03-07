#include <bits/stdc++.h>
//#define int long long
#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
#define gc()(is==it?it=(is=in)+fread(in,1,Q,stdin),(is==it?EOF:*is++):*is++)
const int Q=(1<<24)+1;
char in[Q],*is=in,*it=in,c;
void read(int &n){
    int f = 1;
    for(n=0;(c=gc())<'0'||c>'9';)if(c == '-') f = -1;
    for(;c<='9'&&c>='0';c=gc())n=n*10+c-48;
    n *= f;
}
int n, k;
vector<pair<int, int> > ans, a;
vector<int> b;
vector<int> v[2000009];
signed main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
//    ios::sync_with_stdio(0);
//    cin.tie(0);
    read(n); read(k);
    for(int i = 1; i <= n; i++) {
        int l, r;
        read(l); read(r);
//        cout << l << r << endl;
        b.push_back(l);
        b.push_back(r);
        ans.push_back({l, r});
    }
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());
    int bef = 0x3f3f3f3f, t = 0;
    for(int i = 0; i < n; i++) {
        int l = lower_bound(b.begin(), b.end(), ans[i].first) - b.begin();
        int r = lower_bound(b.begin(), b.end(), ans[i].second) - b.begin();
        v[l].push_back(1);
        v[r].push_back(-1);
    }
    ans.clear();
    for(int i = 0; i <= 2000000; i++) {
        int f1 = 0, f2 = 0;
        for(auto x : v[i]) {
            if(x > 0) f1++;
            else f2++;
        }
        if(t >= k && t + f1 >= k) {
            ans.push_back({bef, i});
        } else if(t < k && t + f1 >= k) {
            ans.push_back({i, i});
        }
        bef = i;
        t = t + f1 - f2;
    }
    if(ans.size() == 0) {
        cout << 0 << endl;
        return 0;
    }
    int l = ans[0].first, r = ans[0].second;
    for(int i = 1; i < ans.size(); i++) {
        if(ans[i].first == r) {
            r = ans[i].second;
        } else {
            a.push_back({l, r});
            l = ans[i].first;
            r = ans[i].second;
        }
    }
    a.push_back({l, r});
    printf("%d\n", a.size());
    for(auto t : a) {
        printf("%d %d\n", b[t.first], b[t.second]);
//        cout << b[t.first] << " " << b[t.second] << endl;
    }

    return 0;
}