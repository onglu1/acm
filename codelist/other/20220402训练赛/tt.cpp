#include <bits/stdc++.h>
using namespace std;
int n, k;
int g[109][109];
signed main()
{
    cin >> n >> k;
    if(k == 0) {
        cout << "YES" << endl;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                cout << ".";
            }
            cout << endl;
        }
        return 0;
    }
    if(n == 2) {
        if(k == 1) {
            cout << "YES" << endl;
            cout << "#.\n.." << endl;
        } else {
            cout << "NO" << endl;
        }
        return 0;
    }
    if(k > n * n - n) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    g[1][n] = 1; g[n][1] = 1;
    for(int i = 2; i < n; i++) g[i][i] = 1;
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(!g[i][j] && cnt < k) {
                cout << "#";
                cnt++;
            } else {
                cout << ".";
            }
        }
        cout << endl;
    }
    return 0;
}