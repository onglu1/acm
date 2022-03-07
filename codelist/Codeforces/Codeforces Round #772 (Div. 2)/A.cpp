#include <bits/stdc++.h>
#define Mid (l + r >> 1)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
int read() {
    char c; int num, f = 1;
    while(c = getchar(),!isdigit(c)) if(c == '-') f = -1; num = c - '0';
    while(c = getchar(), isdigit(c)) num = num * 10 + c - '0';
    return f * num;
}
int n;
void work() {
    cin >> n;
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        for(int j = 0; j < 30; j++) {
            if(x & (1 << j)) {
                if(!(ans >> j & 1)) {
                    ans |= (1 << j);
                }
            }
        }
    }
    cout << ans << endl;
}
signed main()
{
    ios :: sync_with_stdio(0);
    cin.tie(0);
    int Case;
    cin >> Case;
    while(Case--) work();
    return 0;
}
