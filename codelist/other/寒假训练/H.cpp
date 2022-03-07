#include <bits/stdc++.h>
#define int long long
#define Mid (l + (r - l) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int N = 2e6 + 1009;
const int R = 1e9 + 1;
int n, a, b, c[N];
vector<int> v[2];
int read() {
    char c; int num;
    while(c = getchar(),!isdigit(c)) ; num = c - '0';
    while(c = getchar(), isdigit(c)) num = num * 10 + c - '0';
    return num;
}
signed main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
//    scanf("%lld%lld%lld", &n, &a, &b);
    n = read(); a = read(); b = read();
    for(int i = 1; i <= n; i++) c[i] = read();
    for(int i = 1; i <= n; i++) {
        int f ;
        f = read();
        if(f == 0)
            v[f].push_back(c[i]);
        else v[f].push_back(R - c[i]);
    }
    sort(v[0].begin(), v[0].end());
    sort(v[1].begin(), v[1].end());
    if(b < a) {
        swap(a, b);
        swap(v[0], v[1]);
    }
    int ans = 0;
    b -= a / n * n;
    ans += a / n * 2 * R;
    a %= n;
    deque<int> q[2];
    for(auto x : v[0]) q[0].push_back(x);
    for(auto x : v[1]) q[1].push_back(x);
    int t = 0;
    while(!q[0].empty() || !q[1].empty()) {
        if(q[1].size() == 0 || (q[0].size() && q[0].front() < q[1].front())) {
            if(a == 0) t = q[0].front(), q[0].pop_front();
            else {
                q[1].push_back(q[0].front() + R);
                q[0].pop_front();
                a--;
            }
        } else {
            if(b == 0) t = q[1].front(), q[1].pop_front();
            else {
                q[0].push_back(q[1].front() + R);
                q[1].pop_front();
                b--;
            }
        }
    }
//    cout << t << endl;
    cout << ans + t << endl;
    return 0;
}
/*
 * 2000000002500000000
 */