//
<<<<<<<< HEAD:codelist/gym/The 16th Heilongjiang Provincial Collegiate Programming Contest/H.cpp
// Created by onglu on 2022/5/11.
========
// Created by onglu on 2022/9/6.
>>>>>>>> origin/master:codelist/Codeforces/Codeforces Round #814 (Div. 1)/B.cpp
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
int n, m, a[N];
long long f[N];
void work() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
<<<<<<<< HEAD:codelist/gym/The 16th Heilongjiang Provincial Collegiate Programming Contest/H.cpp
    int t;
    cin >> n >> t;
//    cout << n << endl;
    for(int i = 1; i < n; i++) {
        cout << n - i + 1 << " " << n - i << endl;
    }
    cout << 1 << " " << n << endl;
========
    int Case = 1;
    for(int i = 1; i <= )
    // cin >> Case;
    while(Case--) work();
>>>>>>>> origin/master:codelist/Codeforces/Codeforces Round #814 (Div. 1)/B.cpp
    return 0;
}