//
// Created by onglu on 2022/3/19.
//

#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define val(x) tree[x].val
#define son(x, f) tree[x].ch[f]
#define endl '\n'
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
//#define int long long
using namespace std;
const int N = 2e6 + 1009;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309
struct node {
    int val, id;
    int ch[2];
} tree[N];
int n, m, a[N];
int root, tot;
map<int, int> M;
int New(int x) {
    val(++tot) = x;
    son(tot, 0) = son(tot, 1) = 0;
    return tot;
}
void Insert(int rt, int x) {
    if(son(rt, x < val(rt))) {
        Insert(son(rt, x < val(rt)), x);
    } else {
        son(rt, x < val(rt)) = New(x);
    }
}
void work() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if(i == 1) root = New(x);
        else Insert(root, x);
    }
    queue<pair<int, int> > q;
    q.push({root, 1});
    printf("%d", val(root));
    while(q.size()) {
        int x = q.front().first, id = q.front().second; q.pop();
        M[id] = 1;
        if(son(x, 0)) {
            q.push({son(x, 0), id * 2});
            printf(" %d", val(son(x, 0)));
        }
        if(son(x, 1)) {
            q.push({son(x, 1), id * 2 + 1});
            printf(" %d", val(son(x, 1)));
        }
    }
    printf("\n");
    for(auto x : M) {
        if(x.first == root) continue;
        if(!M.count(x.first - 1)) {
            printf("NO\n");
            return ;
        }
    }
    printf("YES\n");
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Case = 1;
//  cin >> Case;
    while (Case--) work();
    return 0;
}