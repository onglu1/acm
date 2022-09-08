#include <bits/stdc++.h>
using namespace std;
int n;
signed main()
{
    int Case;
    cin >> Case;
    while(Case--) {
        int limit;
        cin >> n >> limit;
        limit *= 3;
        for(int i = 2; i <= n; i++) {
            int x; cin >> x;
            limit = max(limit, x + 1);
        }
        if(limit & 1) limit += 1;
        cout << limit << endl;
    }
    return 0;
}