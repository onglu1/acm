 //
// Created by onglu on 2022/4/1.
//

#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()

#define endl '\n'
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
#define int long long
using namespace std;
const int N = 2e6 + 1009;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309;
int n, m, a[N];
vector<int> pri, cnt;
void work() {
    cin >> n;
    int tn = n;
    for(int i = 2; i * i <= tn; i++) if(tn % i == 0) {
        pri.push_back(i);
        int t = 0;
        while(tn % i == 0) {
            tn /= i;
            t++;
        }
        cnt.push_back(t);
    }
    if(tn > 1) {
        pri.push_back(tn);
        cnt.push_back(1);
    }
    int F = -1;
    for(int i = 0; i < pri.size(); i++) {
        int pk = 1, pnk = 1;
        int Fi = 0;
        for(int j = 0; j < cnt[i]; j++) {
            pnk *= pri[i];
        }
        for(int j = 0; j <= cnt[i]; j++) {
            if(pnk != 1) Fi += pk * (pnk - pnk / pri[i]);
            else Fi += pk;
            pk *= pri[i];
            pnk /= pri[i];
        }
        if(F == -1) F = Fi;
        else F = F * Fi;
    }
    cout << F << endl;
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