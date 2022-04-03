#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
int n, m, num[100];
void Insert(int a) {
    for (int i = 63; i >= 0; i--)
        if (a & (1ll << i)) {
            if (num[i])a ^= num[i];
            else {
                num[i] = a;
                return;
            }
        }
}
int getmax() {
    int now = 0;
    for (int i = 63; i >= 0; i--)
        if ((now ^ num[i]) > now)
            now ^= num[i];
    return now;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        Insert(x);
    }
    cout << getmax() << endl;
    return 0;
}