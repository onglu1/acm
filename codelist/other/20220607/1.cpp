#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    vector<int> v;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    int ans = 0;
    for(int i = 0; i < v.size(); i++) {
        int x = v[i];
        if(x <= m) {
            m -= x;
            ans += 1;
        }
    }
    cout << ans << endl;
    return 0;
}