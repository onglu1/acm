#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
void dfs(int now) {
    static int cnt = 0;
    cout << now << ".mp4" << endl;
    cnt++;
    if(cnt >= 50) exit(0);
    for(int i = 0; i < 10; i++) {
        int tn = now * 10 + i;
        if(tn <= n) {
            dfs(tn);
        }
    }

}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i < 10; i++) {
        dfs(i);
    }
    return 0;
}