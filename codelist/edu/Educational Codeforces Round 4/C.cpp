//
// Created by onglu on 2022/4/27.
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
string s;
void No() {
    cout << "Impossible" << endl;
    exit(0);
}
map<char, char> match;
void work() {
    match['('] = ')';
    match['['] = ']';
    match['<'] = '>';
    match['{'] = '}';
    cin >> s;
    int cnt = 0;
    for(auto x : s) {
        if(x == '(' || x == '[' || x == '<' || x == '{') cnt += 1;
        else cnt -= 1;
        if(cnt < 0) No();
    }
    if(cnt != 0) No();
    stack<char> sta;
    int ans = 0;
    for(auto x : s) {
        if(x == '(' || x == '[' || x == '<' || x == '{') sta.push(x);
        else {
            if(x != match[sta.top()]) {
                ans += 1;
            }
            sta.pop();
        }
    }
    cout << ans << endl;

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