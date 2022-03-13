//
// Created by onglu on 2022/3/9.
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
//const int N = 2e6 + 1009;
const int N =5e5 + 1009;
//const int N = 5009;
//const int N = 309
int n, m;
struct node {
    string first, second;
    int op;
} a[N];
int fa[N];
map<string, int> M;
vector<int> ver[N];
int dth[N];
void dfs(int x) {
    for(auto y : ver[x]) {
        dth[y] = dth[x] + 1;
        dfs(y);
    }
}
string substr(string &a, int b) {
    string s;
    for(int i = 0; i < b; i++) {
        s = s + a[i];
    }
    return s;
}
string getname(string &a) {
    char c = a[a.size() - 1];
    if(c == 'm' || c == 'f') return substr(a, a.size() - 1);
    if(c == 'n') {
        return substr(a, a.size() - 4);
    } else {
        return substr(a, a.size() - 7);
    }
}
void work() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        string f, s;
        int op;
        cin >> f >> s;
        M[f] = i;
        if(s[s.size() - 1] == 'm' || s[s.size() - 1] == 'n') op = 1;
        else op = 0;
        a[i] = {f, getname(s), op};
    }
    memset(fa, -1, sizeof fa);
    for(int i = 1; i <= n; i++) {
        string s = a[i].second;
        if(M.count(s)) {
            ver[M[s]].push_back(i);
            fa[i] = M[s];
        }
    }
    for(int i = 1; i <= n; i++) {
        if(fa[i] == -1) {
            dfs(i);
        }
    }
    int q;
    cin >> q;
//    for(int i = 1; i <= n; i++) {
//        cout << fa[i] << " " << dth[i] << endl;
//    }
//    cout << endl;
    while(q--) {
        string f, s;
        string ff, ss;
        cin >> f >> s;
        cin >> ff >> ss;
        if(!M.count(f)) {
            cout << "NA" << endl;
            continue;
        }
        if(!M.count(ff)) {
            cout << "NA" << endl;
            continue;
        }
        int x = M[f];
        int y = M[ff];
        if(a[x].second != s) {
            cout << "NA" << endl;
            continue;
        }
        if(a[y].second != ss) {
            cout << "NA" << endl;
            continue;
        }
        if(a[x].op == a[y].op) {
            cout << "Whatever" << endl;
            continue;
        }
        if(dth[x] < dth[y]) swap(x, y);
        for(int i = 1; i <= 3; i++) {
            if(fa[y] != -1) {
                y = fa[y];
            }
        }
        int ok = 0;
        while(x != -1) {
            if(y == x) {
                cout << "No" << endl;
                ok = 1;
                break;
            }
            x = fa[x];
        }
        if(!ok) cout << "Yes" << endl;
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