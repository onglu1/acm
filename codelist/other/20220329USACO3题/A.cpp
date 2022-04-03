#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 2e5 + 1009;
int n, m, has[N], req[N];
vector<int> v[N];
//判断mid作为答案是否可行
int check(int mid) {
    memset(req, 0, sizeof(int) * (n + 10));
// 第n个金属需要mid个
    req[n] = mid;
    for(int i = n; i >= 1; i--) {
        // need是除去本来就有的金属，还需要仍然需要的金属数量
        int need = req[i] - has[i];
        // 如果没办法合成这个金属，但是这个金属不足，那么说明答案不能为mid
        if(v[i].size() == 0 && need > 0) {
            return false;
        }
        if(need <= 0) continue;
        // 如果原来拥有的金属数量不足以提供给需求，需要合成这个金属
        // 那么就按合成配方和成，把需求传给他下面的金属
        for(auto x : v[i]) {
            req[x] += need;
        }
    }
    //全部需求都被满足就是可以达成mid
    return true;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int l = 0, r = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> has[i];
        r += has[i];
    }
    cin >> m;
    for(int i = 1; i <= m; i++) {
        int l, k;
        cin >> l >> k;
        while(k--) {
            int x;
            cin >> x;
            v[l].push_back(x);
        }
    }
    int ans = 0, Mid;
    while(l <= r) {
        //二分答案，检查中点是否满足条件
        Mid = ((l + r) / 2);
        if(check(Mid)) {
            //如果满足条件，答案等于中点
            ans = Mid;
            //然后找是否有大于Mid的答案
            l = Mid + 1;
        } else {
            //如果中点不满足条件，找是否有小于Mid的答案
            r = Mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}
/*
 5
 2 0 0 1 0
 3
 5 2 3 4
 2 1 1
 3 1 2
首先，我们注意到答案具有单调性，所以
我们可以用二分搜索解决这个问题！
我们二分最终答案mid，接下来我们只需要判断答案能否为mid
发现金属的合成路线是单向传递的，我们可以从高到低递推一遍
计算每个金属至少需要多少个才能合成n号金属就行
 */