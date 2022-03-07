#include <bits/stdc++.h>

#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int N = 2e6 + 1009;
int n, m;
map<string, int> M;
vector<string> v;
signed main() {
#ifdef LOCALCOMPILE
    auto startTime = clock();
    freopen("C:\\Users\\onglu\\CLionProjects\\ACM\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\ACM\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        v.push_back(s);
    }
    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        M[s] = 1;
    }
    for(auto s : v) {
        cout << (M.count(s) ? "Yes" : "No") << endl;
    }

#ifdef LOCALCOMPILE
    cout << "The run time is: " <<(double)(clock() - startTime) * 1000 / CLOCKS_PER_SEC << "ms" << endl;
#endif
    return 0;
}