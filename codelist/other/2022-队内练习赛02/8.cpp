//
// Created by onglu on 2022/4/2.
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
int n, m;
int gcd = 0;
vector<int> a, b, ans, t, tt;
void work() {
    gcd = 0;
    b.clear();
    b.clear();
    a.clear();
    t.clear(); tt.clear();
    for(int i = 0; i < n * (n + 1) / 2; i++) {
        int x;
        cin >> x;
        b.push_back(x);
        if(b[i] % 2 == 0) {
            if(gcd == 0) {
                gcd = b[i];
            } else {
                gcd = __gcd(b[i], gcd);
            }
        }
    }
    std::sort(b.begin(), b.end());
    for(auto x : b) {
        if(x % 2 == 0) {
            a.push_back(x / gcd);
        }
    }
    std::sort(a.begin(), a.end());
    for(int i = 0; i < a.size(); i++) {
        for(int j = i + 1; j < a.size(); j++) {
            t.push_back(a[i] * a[j]);
        }
    }
    for(auto x : b) {
        if(x & 1) {
            tt.push_back(x);
        }
    }
    std::sort(tt.begin(), tt.end());
    std::sort(t.begin(), t.end());
    assert(t[0] != 0);
    int p = sqrt(tt[0] / t[0]);
    cout << gcd / p << endl;
    for(auto x : a) {
        cout << x * p << " ";
    }
    cout << endl;


}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> n) {
        if(n == 0) break;
        work();
    }
    return 0;
}