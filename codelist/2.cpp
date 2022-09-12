#include <bits/stdc++.h>
class Solution {
public:
    int calc_cost(std::vector<int> &rec) {
        std::priority_queue<int> q;
        for(auto x : rec) q.push(-x);
        int ans = 0;
        while(q.size() > 1) {
            int x = -q.top(); q.pop();
            int y = -q.top(); q.pop();
            ans += x + y;
            q.push(-(x + y));
        }
        return ans;
    }
};
int main() {
    std::vector<int> v = {3, 6, 2, 1, 1};
    Solution s;
    std::cout << s.calc_cost(v);
}