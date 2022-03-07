#include <bits/stdc++.h>

#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int N = 2e6 + 1009;
int n, a[N];
signed main() {
#ifdef LOCALCOMPILE
    auto startTime = clock();
    freopen("C:\\Users\\onglu\\CLionProjects\\ACM\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\ACM\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[x]++;
    }
    int l = 1, r = 2, cnt = 0;
    for(int i = 1; i <= 100000; i++) {
        if(a[i] >= 3) {
            if(a[i] % 2 == 0) {
                cnt += (a[i] - 2) / 2;
                a[i] = 2;
            } else {
                cnt += (a[i] - 1) / 2;
                a[i] = 1;
            }
        }
    }
    while(1) {
        while(a[l] <= 1 && l <= 100001) l++;
        if(r <= l) r = l + 1;
        while(a[r] <= 1 && r <= 100001) r++;
        if(l > 100000 && r > 100000) break;
        cnt++;
        a[l] = 0; a[r] = 0;

    }
    cout << n - cnt * 2 << endl;
#ifdef LOCALCOMPILE
    cout << "The run time is: " <<(double)(clock() - startTime) * 1000 / CLOCKS_PER_SEC << "ms" << endl;
#endif
    return 0;
}