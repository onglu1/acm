#include <bits/stdc++.h>
using namespace std;
struct node {
    int cnt, price;
};
bool operator<(const node &a, const node &b) {
    return a.price < b.price;
}
class Solution {
public:
    /*
     * 假设是前i天可以任意买，问最少可以花费多少钱买够
     * 很好计算，每次挑最便宜的买就行了
     * 要问能否达成预算，其实就是最少的钱是不是比预算少
     * 那么问最少第几天可以买够，有两个方法计算：
     * 一个是二分天数，然后按照上面的方法
     * 另一个可以维护一个大根堆，维护num件物品
     * 每到新一天，就有若干件比较便宜的物品选择，我们只要去替换最贵的原来买到的物品就行了
     */
    priority_queue<node> q;
    int PurchaseItems(int num, int price, vector<vector<int> > discount, int budget) {
        int totcost = num * price;
        if(totcost <= budget) return 1;
        q.push({num, price});
        for(int i = 0; i < discount.size(); i++) {
            // putin是今天的特价买几件
            int putin = 0;
            // 没买完，有多的物品可以替换，替换之后可以省钱，缺一不可
            while(discount[i][2] > 0 && q.size() && q.top().price > discount[i][1]) {
                // 考虑替换
                node t = q.top(); q.pop();
                // 如果不能把最贵的那个物品替换空
                if(t.cnt > discount[i][2]) {
                    t.cnt -= discount[i][2];
                    // 维护总价值
                    totcost -= discount[i][2] * t.price;
                    putin += discount[i][2];
                    // 当前物品全部替换
                    discount[i][2] = 0;
                    q.push(t);
                } else {
                    // 替换完所有最贵的物品
                    discount[i][2] -= t.cnt;
                    totcost -= t.cnt * t.price;
                    putin += t.cnt;
                }
            }
            // 把替换的物品加进去
            if(putin > 0) {
                q.push({putin, discount[i][1]});
                // 维护总价值
                totcost += putin * discount[i][1];
            }
            // 如果这一天买得完，num件物品，直接返回天数
            if(totcost <= budget) return discount[i][0];
        }
        return -1;

    }
};
int a[][3] = {
        {2, 5, 3},
        {3, 6, 2},
        {4, 2, 1},
        {6, 1, 4},
        {100, 3, 1}
};
int main()
{
    Solution s;
    vector<vector<int> > t;
    for(int i = 0; i < 5; i++) {
        t.push_back(vector<int> ());
        for(int j = 0; j < 3; j++) {
            t[i].push_back(a[i][j]);
        }
    }
    cout << s.PurchaseItems(4, 10, t, 18) << endl;
}