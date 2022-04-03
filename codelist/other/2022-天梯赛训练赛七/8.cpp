//
// Created by onglu on 2022/3/26.
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
int n, m, a[5][5];
int f[5][5];
map<int, int> M;
int get(int  t) {
    int s = 0;
    if (t <= 3) {
        for (int j = 1; j <= 3; j++) {
            s += a[t][j];
        }
    } else if (t <= 6) {
        t -= 3;
        for (int i = 1; i <= 3; i++) {
            s += a[i][t];
        }
    } else if (t == 7) {
        for (int i = 1; i <= 3; i++) {
            s += a[i][i];
        }
    } else {
        for (int i = 1; i <= 3; i++) {
            s += a[i][3 - i + 1];
        }
    }
    if(M.count(s)) return M[s];
    else return 0;
}
void work() {
    M[6	] =10000;M[	16	]=   72;
    M[7	] =36	 ;M[      17]=	180;
    M[8	] =720	 ;M[      18]=	119;
    M[9	] =360	 ;M[      19]=	36;
    M[10] =	80	 ;M[      20]=	306;
    M[11] =	252	 ;M[      21]=	1080;
    M[12] =	108	 ;M[      22]=	144;
    M[13] =	72	 ;M[      23]=	1800;
    M[14] =	54	 ;M[      24]=	3600;
    M[15] =	180;
    int sum = (1 + 9) * 9 / 2;
    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++) {
            cin >> a[i][j];
            sum -= a[i][j];
        }
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            if (a[i][j] == 0) {
                a[i][j] = sum;
                f[i][j] = 1;
            }
        }
    }

    for (int i = 1; i <= 3; i++) {
        int x, y;
        cin >> x >> y;
        f[x][y] = 1;
        cout << a[x][y] << endl;
    }
    int t;
    while(cin >> t) {
        cout << get(t) << endl;
    }
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