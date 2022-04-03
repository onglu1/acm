//
// Created by onglu on 2022/3/26.
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
struct node {
    string name;
    string id;
    int st;
    int tim, ord;
};
int n, m, a[N];
int d, p;
map<string, int> M, f;
vector<node> ttt;
int idcheck(string s) {
    if(s.size() != 18) return false;
    for(auto x : s) if(!isdigit(x)) return false;
    return true;
}
int check(const node &a, int i) {
    if(!idcheck(a.id)) return 0;
    if(M.count(a.id) && M[a.id] >= i - p) return 0;
    return 1;
}
void work() {
    cin >> d >> p;
    for(int i = 1; i <= d; i++) {
        int t, s;
        cin >> t >> s;
        vector<node> v;
        v.clear();
        while(t--) {
            string a, b, d;
            int c;
            cin >> a >> b >> c >> d;
            int hh = (d[0] - '0') * 10 + d[1] - '0';
            int mm = (d[3] - '0') * 10 + d[4] - '0';
            if(hh < 0 || hh > 23) continue;
            if(mm < 0 || mm >= 60) continue;
            int tim = hh * 60 + mm ;
//            cout << tim / 60 << " " << tim % 60 << endl;
            v.push_back({a, b, c, tim, t});
        }
        for(auto x : v) {
            if(idcheck(x.id)) {
                if(x.st == 1) {
                    if(!f.count(x.id)) {
                        f[x.id] = 1;
                        ttt.push_back(x);
                    }
                }
            }
        }
        std::sort(v.begin(), v.end(), [](const node &a, const node &b) {
            if(a.tim == b.tim) return a.ord > b.ord;
            return a.tim < b.tim;
        });
        for(auto x : v) {
            if(check(x, i) && s > 0) {
                cout << x.name << " " << x.id << endl;
                M[x.id] = i;
                s--;

            }
        }
    }
    for(auto x : ttt) {
        cout << x.name << " " << x.id << endl;
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
//    cin >> Case;
    while (Case--) work();
    return 0;
}