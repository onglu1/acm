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
int n, a[1000009];
void work() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    a[n + 1] = 1000000000;
    int cnt = 0;
    for(int i = 2; i < n; i++) {
        if(a[i - 1] < a[i] && a[i + 1] < a[i]) {
            a[i + 1] = max(a[i], a[i + 2]);
            cnt++;
        }

    }
    cout << cnt << endl;
    for(int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
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
