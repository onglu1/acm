#include <bits/stdc++.h>
using namespace std;
int n;
map<int, int> M;
signed main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
        M[l] += 1;
        M[r] -= 1;
    }
    int maxn = 0;
    for(auto it = M.begin(); it != M.end(); ) {
        maxn = max(maxn, it -> second);
        auto itt = it;
        it++;
        if(it != M.end()) {
            it -> second += itt -> second;
        }
    }
    int f = 0;
    for(auto it = M.begin(); it != M.end(); it++) {
        if(f == 0 && it -> second == maxn) {
            f = 1;
            cout << (it -> first) << " ";
        }
        if(f == 1 && it ->second != maxn) {
            cout << (it -> first) << endl;
            break;
        }
    }
    return 0;
}