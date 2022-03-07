#include <bits/stdc++.h>

#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int N = 2e6 + 1009;
int n, m;
vector<int> a, b;
void work() {
    cin >> n;
    a.clear();
    b.clear();
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if(x & 1) a.push_back(x);
        else b.push_back(x);
    }
    for(int i = 1; i < a.size(); i++) {
        if(a[i] < a[i - 1]) {
            cout << "No" << endl;
            return ;
        }
    }
    for(int i = 1; i < b.size(); i++) {
        if(b[i] < b[i - 1]) {
            cout << "No" << endl;
            return ;
        }
    }
    cout << "Yes" << endl;
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