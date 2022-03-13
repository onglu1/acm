//
// Created by onglu on 2022/3/12.
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
vector<int> v[N];
void work() {
    int total = 0;
    cin >> n;
//    cout << n << endl;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] *= 10;
        total += a[i];
    }
    int pre = 0, now = 0;
    while(total > 0) {
        for(int i = 1; i <= n; i++) {
            if(a[i] > 0) {
                if(pre == i) {
                    v[i].push_back(now + 2);
                    now += 2;
                } else {
                    v[i].push_back(now + 1);
                    now += 1;
                }
                total -= 1;
                pre = i;
                a[i] -= 1;
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << "#" << i << endl;
        for(int j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " \n"[j % 10 == 9];
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