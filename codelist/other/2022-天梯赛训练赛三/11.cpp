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
//const int N = 2e6 + 1009;
//const int N = 2e5 + 1009;
const int N = 10009;
//const int N = 309
//const int N = 15;
int n, m, k;
struct node {
    string s;
    int x;
} a[N];
void work() {
    int sum = 0;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].s >> a[i].x;
        if(a[i].x >= m) sum += 50;
        else if(a[i].x >= 60) sum += 20;
    }
    sort(a + 1, a + 1 + n, [](const node &a, const node &b) {
        if(a.x != b.x) return a.x > b.x;
        else return a.s < b.s;
    });
    int sc = a[k].x, cnt = 0;
    cout << sum << endl;
    for(int i = 1; i <= n; i++){
        if(a[i].x != a[i - 1].x) cnt = i;
        if(a[i].x >= sc) {
            cout << cnt << " " << a[i].s << " " << a[i].x << endl;
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