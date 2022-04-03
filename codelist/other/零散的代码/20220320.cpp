//
// Created by onglu on 2022/3/20.
//

#include <bits/stdc++.h>

using namespace std;

class Solution {
public :
    int minInsertNum(vector<int> &arr) {
        /*
         * 我们能用数列内部的元素匹配就尽量用内部元素匹配
         * 如果匹配完后还有剩余的没匹配完，就要添加额外的来匹配
         */
        //cnt[i]表示i剩余几个结尾为i的匹配
        int cnt[4] = {0};
        //需要添加几对来匹配
        int ans = 0;
        for(auto x : arr) {
            //如果进入的是一个1，没法匹配
            if(x == 1) cnt[1]++;
            if(x == 2) {
                //如果是2，那么要么跟前面一个1匹配，要么花费一个代价插入一个1，多出来一个结尾为2的匹配
                if(cnt[1] > 0) cnt[1]--;
                else ans++;
                cnt[2]++;
            }
            if(x == 3) {
                //如果有结尾为2的匹配，直接消耗
                if(cnt[2] > 0) cnt[2]--;
                else if(cnt[1] > 0) {
                    //如果只有结尾为1的匹配，那么花费代价插入一个2
                    ans += 1;
                    cnt[1]--;
                    //如果都没有，需要插入一个1,2才能完成匹配
                } else ans += 2;
            }
        }
        //剩下的没匹配完的1和2，需要补全
        return ans + cnt[1] * 2 + cnt[2];
    }
};

signed main() {
    Solution s;
    vector<int> list = {1, 2, 1, 3};
    cout << s.minInsertNum(list) << endl;
    return 0;
}