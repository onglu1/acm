#include <bits/stdc++.h>

#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int N = 2e6 + 1009;
int n, m, a[N];
void work() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        if(a[i] != i) {
            for(int j = i + 1; j <= n; j++) {
                if(a[j] == i) {
                    reverse(a + i, a + 1 + j);
                    for(int k = 1; k <= n; k++) {
                        cout << a[k] << " ";
                    }
                    cout << endl;
                    return ;
                }
            }
        }
    }
    for(int k = 1; k <= n; k++) {
        cout << a[k] << " ";
    }
    cout << endl;
}

signed main() {
#ifdef LOCALCOMPILE
    auto startTime = clock();
    freopen("C:\\Users\\onglu\\CLionProjects\\ACM\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\ACM\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int Case = 0;
    cin >> Case;
    while (Case--) work();
#ifdef LOCALCOMPILE
    cout << "The run time is: " <<(double)(clock() - startTime) * 1000 / CLOCKS_PER_SEC << "ms" << endl;
#endif
    return 0;
}