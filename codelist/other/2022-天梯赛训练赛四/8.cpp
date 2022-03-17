//
// Created by onglu on 2022/3/16.
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
int ra, rb, ca, cb;
int a[109][109], b[109][109];
int c[109][109];
void work() {
    cin >> ra >> ca;
    for(int i = 1; i <= ra; i++) {
        for(int j = 1; j <= ca; j++) {
            cin >> a[i][j];
        }
    }
    cin >> rb >> cb;
    for(int i = 1; i <= rb; i++) {
        for(int j = 1; j <= cb; j++) {
            cin >> b[i][j];
        }
    }
    if(ca != rb) {
        cout << "Error: " << ca << " != " << rb << endl;
        return ;
    }
    for(int i = 1; i <= ra; i++) {
        for(int j = 1; j <= cb; j++) {
            c[i][j] = 0;
            for(int k = 1; k <= ca; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    cout << ra << " " << cb << endl;
    for(int i = 1; i <= ra; i++) {
        for(int j = 1; j <= cb; j++) {
            cout << c[i][j] << " \n"[j == cb];
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