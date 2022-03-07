#include <bits/stdc++.h>
#define int long long
#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int N = 2e6 + 1009;
int n, m, g[19][19];

void work() {

}

signed main() {
#ifdef LOCALCOMPILE
    auto startTime = clock();
    freopen("C:\\Users\\onglu\\CLionProjects\\ACM\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\ACM\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x;
    cin >> x;
    if(x % 11 == 0) cout << (x / 11) * 2 << endl;
    else if(x % 11 <= 6) cout << (x / 11) * 2 + 1 << endl;
    else cout << (x / 11) * 2 + 2 << endl;
//    cout << ((x - 1) / 11) * 2 + 1 << endl;
#ifdef LOCALCOMPILE
    cout << "The run time is: " <<(double)(clock() - startTime) * 1000 / CLOCKS_PER_SEC << "ms" << endl;
#endif
    return 0;
}