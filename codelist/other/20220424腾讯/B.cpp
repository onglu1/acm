#include <bits/stdc++.h>
#define int long long
using namespace std;
class Solution {
public:
    int getNumber(vector<int>& a) {
        int n = a.size();
        vector<int> f(n + 1), pri;
        f[1] = 1;
        for(int i = 2; i <= n; i++) {
            if(!f[i]) {
                pri.push_back(i);
            }
            for(int j = 0; j < pri.size() && i * pri[j] <= n; j++) {
                f[i * pri[j]] = 1;
                if(i % pri[j] == 0) break;
            }
        }
        while(a.size() > 1) {
            vector<int> b;
            for(int i = 1; i <= a.size(); i++) {
                if(!f[i]) {
                    b.push_back(a[i - 1]);
                }
            }
            a = b;
        }
        return a[0];
    }

};
