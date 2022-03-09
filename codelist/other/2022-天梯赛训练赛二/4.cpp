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
const int N = 2e6 + 1009;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309
int n, m, a[N];

void work() {
    string s;
    getline(cin, s);
    if(s.find("ong,") == std::string::npos || s.find("ong.") == std::string::npos) {
        cout << "Skipped" << endl;
        return ;
    }
    int j = s.size() - 1;
    int cnt = 3;
    while(cnt) {
        if(s[j] == ' ') cnt--;
        j--;
        if(s[j] == ',') {
            break;
        }
    }

    for(int i = 0; i <= j; i++) {
        cout << s[i];
    }
    cout << " qiao ben zhong." << endl;

}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Case = 0;
    cin >> Case;
    cin.ignore();
    while (Case--) work();
    return 0;
}