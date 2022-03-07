//
// Created by onglu on 2022/2/25.
//

#include <bits/stdc++.h>

#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
//#define int long long
using namespace std;
//const int N = 2e6 + 1009;
//const int N = 2e5 + 1009;
const int N = 5009;
//const int N = 309
int n, m, a[N];

void work() {

}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s1 = "abaaa";
    string s2 = "aba";
    cout << (s1.find(s2) == s1.npos) << endl;
    return 0;
}
/*
 * n=100的图，m次加边
 * 对于每个点x，输出第几次加边后存在一条1->x，长度为L的路径。
 * 直接暴力算？
 * n^2 * n^3logL
 *
 */