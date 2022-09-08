//
// Created by onglu on 2022/4/30.
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
int n, m, a[N];
vector<int> g[26][26];
vector<int> pure[26];
string s[109];
void deal(string s, int id) {
    int j = 0;
    vector<int> v;
    for(int i = 0; i < s.size(); i = j) {
        while(j < s.size() && s[j] == s[i]) {
            j++;
        }
        if(i == 0 && j == s.size()) {
            pure[s[0] - 'A'].push_back(id);
            return ;
        }
        v.push_back(s[i] - 'A');
    }
    if(v.size() == 2) g[v[0]][v[1]].push_back(id);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {

        }
    }
}
void work() {
    cin >> n;
    for(int i = 0; i < 26; i++) for(int j = 0; j < 26; j++) g[i][j].clear();
    for(int i = 0; i < 26; i++) pure[i].clear();
    for(int i = 1; i <= n; i++) {
        cin >> s[i];
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
    cin >> Case;
    while (Case--) work();
    return 0;
}