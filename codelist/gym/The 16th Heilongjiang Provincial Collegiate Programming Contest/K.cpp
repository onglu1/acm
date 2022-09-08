#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, k;
signed main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    int s = 0;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        s += x;
    }
    if(s < k) cout << 0 << endl;
    else {
        cout << s - k + (k / 2) << endl;
    }
    return 0;
}