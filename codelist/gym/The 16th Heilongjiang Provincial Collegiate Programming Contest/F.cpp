#include <bits/stdc++.h>
//#define int long long
using namespace std;
const int N = 1e7 + 1009;
int n, f[N], pri[N], tot, p[N];
long long g[N];
signed main()
{
//    printf("%.2f\n", (sizeof(n) + sizeof(f) + sizeof(pri) + sizeof(p) + sizeof(g)) / 1024.0);
    cin >> n;
    for(int i = 2; i <= n; i++) {
        if(!f[i]) pri[++tot] = i, p[i] = i;
        for(int j = 1; j <= tot && pri[j] * i <= n; j++) {
            p[i * pri[j]] = pri[j];
            f[i * pri[j]] = 1;
            if(i % pri[j] == 0) break;
        }
    }
    long long s = 1;
    g[1] = 1;
    for(int i = 2; i <= n; i++) {
        if(!f[i]) {
            g[i] = 1;
        } else {
            int t = i, tt = 1;
            while(t % p[i] == 0) {
                tt *= p[i];
                t /= p[i];
            }
//            cout << i << " " << t << " " << tt << endl;
            if(t == 1) {
                g[i] = p[i] * g[i / p[i] / p[i]];
            } else {
                g[i] = t * g[tt];
            }
        }
        s += g[i];
    }
//    for(int i = 1; i <= n; i++) cout << g[i] << " " ;
//    cout << endl;
    cout << s << endl;
    return 0;
}