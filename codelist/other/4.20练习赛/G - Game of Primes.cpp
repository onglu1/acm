//
// Created by onglu on 2022/4/20.
//

#include <bits/stdc++.h>
#define BOB true
#define ALICE false
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
int x, y, fi, k;
int f[N];
vector<int> pri;
int isPrime(int x) {
    return !f[x];
}
int Bobfirst(int x, int y, int k) {
//    if(x <= k || y <= k) return true;
    if(x < *upper_bound(all(pri), k) || y < *upper_bound(all(pri), k)) return BOB;
    for(auto i = upper_bound(all(pri), k); *i <= x; i++) {
        int dis = x - (*i);
        if(y - dis > k && !f[y - dis]) {
            return ALICE;
        }
    }
    return BOB;
}
int Alicefirst(int x, int y, int k) {
    if(x < *upper_bound(all(pri), k) || y < *upper_bound(all(pri), k)) return BOB;
    if(!f[x] && !f[y]) return ALICE;
    if(Bobfirst(x - 1, y, k) == ALICE || Bobfirst(x, y - 1, k) == ALICE) return ALICE;
    return BOB;
}
void work() {
    static int cnt = 0;
    cnt++;
    cout << "Case " << cnt << ": ";
    cin >> x >> y >> k >> fi;
    if(fi == 0) cout << ((Alicefirst(x, y, k) == ALICE) ? "Alice" : "Bob") << endl;
    else cout << ((Bobfirst(x, y, k) == ALICE) ? "Alice" : "Bob") << endl;
}
signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    f[1] = 1;
    for(int i = 2; i < N; i++)  {
        if(f[i] == 0) {
            pri.push_back(i);
        }
        for(int j = 0; j < pri.size() && i * pri[j] < N; j++) {
            f[pri[j] * i] = 1;
            if(i % pri[j] == 0) break;
        }
    }
//    cout << isPrime(3) << " " << isPrime(15) << endl;
    int Case = 1;
    cin >> Case;
    while (Case--) work();
    return 0;
}