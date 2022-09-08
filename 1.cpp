#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1009;
long long f[N], n, m;
signed main()
{
    cin >> n >> m;
    int sum = 1;
    f[0] = 1;
    for(int i = 1; i <= n; i++) {
        f[i] = sum;
        sum += f[i];
        if(i >= m) sum -= f[i - m];
    }
    cout << f[n] << endl;
    return 0;
}

