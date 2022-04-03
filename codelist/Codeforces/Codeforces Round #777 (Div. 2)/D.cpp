//
// Created by onglu on 2022/3/25.
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
int n, d, a[N];
int isprime(int x) {
    for(int i = 2; i * i <= x; i++) {
        if(x % i == 0) {
            return false;
        }
    }
    return true;
}
vector<int> pri, num;
void divide(int td, vector<int> &pri, vector<int> &num) {
    pri.resize(0);
    num.resize(0);
    for(int i = 2; i * i <= td; i++) {
        if(td % i == 0) {
            pri.push_back(i);
            num.push_back(0);
            while(td % i == 0) {
                (*num.rbegin())++;
                td /= i;
            }
        }
    }
    if(td > 1) {
        pri.push_back(td);
        num.push_back(1);
    }
}
map<pair<int, int> , int> M;
int work() {
    int cnt = 0;
    cin >> n >> d;
    while(n % d == 0) n /= d, cnt++;
    if(cnt <= 1) return false;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            return true;
        }
    }
    if(cnt <= 2) return false;
    int t = 0;
    divide(d, pri, num);
    if(pri.size() >= 2) return cnt >= 3;
    int k = num[0], pp = 0;
    while(n % pri[0] == 0) pp++, n /= pri[0];
//    cout << cnt << " " << n << " " << num[0] << " " << pp << endl;

    return (cnt - 1) * (2 * k - 1) >= cnt * k + pp;
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
    while (Case--) cout << (work() ? "YES" : "NO") << endl;
    return 0;
}