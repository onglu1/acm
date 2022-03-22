//
// Created by onglu on 2022/3/20.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public :
    int minInsertNum(vector<int> &arr) {
        int cnt[4] = {0};
        int ans = 0;
        for(auto x : arr) {
            if(x == 1) cnt[1]++;
            if(x == 2) {
                if(cnt[1] > 0) cnt[1]--;
                else ans++;
                cnt[2]++;
            }
            if(x == 3) {
                if(cnt[2] > 0) cnt[2]--;
                else if(cnt[1] > 0) {
                    ans += 1;
                    cnt[1]--;
                } else ans += 2;
            }
        }
        return ans + cnt[1] * 2 + cnt[2];
    }
};

signed main() {
    Solution s;
    vector<int> list = {1, 2, 1, 3};
    cout << s.minInsertNum(list) << endl;
    return 0;
}