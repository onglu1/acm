//
// Created by onglu on 2022/3/16.
//

#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define son(x, f) tree[x].ch[f]
#define val(x) tree[x].val
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
int n, m, tot;
map<int, int> pos, dth, fa;
struct node {
    int val;
    int ch[2];
} tree[N];
int newNode(int x) {
    val(++tot) = x;
    son(tot, 0) = son(tot, 1) = -1;
    return tot;
}
void Insert(int x, int rt, int d) {
//    cerr << rt << endl;
    int f = x > val(rt);
    if(son(rt, f) == -1) {
        int t = newNode(x);
        son(rt, f) = t;
        pos[x] = t;
        dth[x] = d;
        fa[x] = val(rt);
    } else {
        Insert(x, son(rt, f), d + 1);
    }
}
int root = -1;
int isroot(int x) {
    if(!pos.count(x)) return false;
    return root == pos[x];
}
int issiblings(int x, int y) {
    if(!pos.count(x) || !pos.count(y)) return false;
    if(!fa.count(x) || !fa.count(y)) return false;
    return fa[x] == fa[y];
}
int isparent(int pre, int nxt) {
    if(!pos.count(pre) || !pos.count(nxt)) return false;
    if(!fa.count(nxt)) return false;
    return pre == fa[nxt];
}
int isson(int pre, int nxt, int f) {
    if(!pos.count(pre) || !pos.count(nxt)) return false;
    return son(pos[pre], f) == pos[nxt];
}
int issamelevel(int x, int y) {
    if(!pos.count(x) || !pos.count(y)) return false;
    return dth[x] == dth[y];
}
string s;
void judge(int x) {
    if(x) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}
void work() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if(root == -1) {
            root = newNode(x);
            dth[root] = 1;
            pos[x] = root;
        } else {
            Insert(x, root, 1);
        }
    }
//    cout << pos[2] << endl;
    int q;
    cin >> q;
    cin.ignore();
    while(q--) {
        getline(cin, s);
        if(s.find("root") != string::npos) {
            int root;
            sscanf(s.c_str(), "%d is the root", &root);
            judge(isroot(root));
        }
        if(s.find("siblings") != string::npos) {
            int x, y;
            sscanf(s.c_str(), "%d and %d are siblings", &x, &y);
            judge(issiblings(x, y));
        }
        if(s.find("same level") != string::npos) {
            int x, y;
            sscanf(s.c_str(), "%d and %d are on the same level", &x, &y);
            judge(issamelevel(x, y));
        }
        if(s.find("is the parent of") != string::npos) {
            int x, y;
            sscanf(s.c_str(), "%d is the parent of %d", &x, &y);
            judge(isparent(x, y));
        }
        if(s.find("is the left child of") != string::npos) {
            int x, y;
            sscanf(s.c_str(), "%d is the left child of %d", &x, &y);
//            printf("%d %d", x, y);
            judge(isson(y, x, 0));
        }
        if(s.find("is the right child of") != string::npos) {
            int x, y;
            sscanf(s.c_str(), "%d is the right child of %d", &x, &y);
            judge(isson(y, x, 1));
        }


    }
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    work();
    return 0;
}