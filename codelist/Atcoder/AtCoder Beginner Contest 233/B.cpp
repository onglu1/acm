#include <bits/stdc++.h>
 
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
 
using namespace std;
int l, r;
char c[100009];
void work() {
    cin >> l >> r;
    cin >> c + 1;
    reverse(c + l, c + r + 1);
    cout << c + 1;
}
 
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int Case = 1;
    while (Case--) work();
    return 0;
}