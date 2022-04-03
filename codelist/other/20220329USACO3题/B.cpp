#include <bits/stdc++.h>
#define endl '\n'
//#define int long long
using namespace std;
const int N = 2e6 + 1009;
int n, m;
//M[0][x]表示每一个位置向左的回答个数
//M[1][x]表示每一个位置向右的回答个数
map<int, int> M[2];
vector<int> pos;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        char c;
        int x;
        cin >> c >> x;
        //记录奶牛回答的位置
        pos.push_back(x);
        if(c == 'G') M[1][x] += 1;
        else M[0][x] += 1;
    }
    //下面两句是排序+去重，目的是为了找出所有的奶牛回答的位置
    std::sort(pos.begin(), pos.end());
    pos.resize(std::unique(pos.begin(), pos.end()) - pos.begin());
    //在第一个点的说对了的奶牛数量为M[1][pos1] + \sum M[0][pos >= pos1]
    int cnt = M[1][pos[0]], ans = 0;
    for(auto x : pos) {
        //一开始
        cnt += M[0][x];
    }
    for(int i = 0; i < pos.size(); i++) {
        ans = max(ans, cnt);
        //计算下一个位置的cnt
        if(i + 1 < pos.size()) {
            //首先减掉这个位置向左的回答个数，然后还需要加上下一个位置向右的回答个数
            cnt = cnt - M[0][pos[i]] + M[1][pos[i + 1]];
        }
    }
    cout << n - ans << endl;
    return 0;
}
/*
 * 一个比较显然的做法是，枚举bessie可能在哪个位置，然后选一个真话最多的位置就是答案
 * 但是这个位置最多有10^9种，没办法全部枚举
 * 我们按照奶牛说的位置从小到大排序
 * 我们很容易发现，一个点在两个位置的中间一段的时候，答案是不会变化的
 * 所以我们对于中间一整段，只计算一遍
 * 同时我们发现，在两个点中间的情况永远不如在两个端点上的情况，所以我们可以简单的只考虑在端点上的情况就行了
 * 我们可以用map存储所有情况
 */