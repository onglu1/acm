//
// Created by onglu on 2022/3/22.
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
int n, m, a[N];

void work() {
    cin >> n;
    string s;
    cin >> s;
    int i = 0, cnt = 0;
    while(i + 1 < s.size()) {
        if(s[i] == '(') {
            i += 2;
            cnt++;
        } else {
            if(s[i + 1] == ')') {
                i += 2;
                cnt++;
            } else {
                int j = i + 1;
                while(j < s.size() && s[j] != ')') j++;
                if(j == s.size()) {
                    cout << cnt << " " << s.size() - i << endl;
                    return ;
                }
                cnt++;
                i = j + 1;
            }
        }
    }
    cout << cnt << " " << s.size() - i << endl;
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