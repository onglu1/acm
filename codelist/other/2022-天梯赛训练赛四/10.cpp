//
// Created by onglu on 2022/3/16.
//

#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()

#define endl '\n'
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
//#define int long long
using namespace std;
//const int N = 1e6 + 1009;
const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309
int n, m;

struct node {
    string ad, nxt;
    int data;
    int id;
} a[N];
map<string, int> M;
int pos[N], vis[N];
void work() {
    string head;
    cin >> head >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].ad >> a[i].data >> a[i].nxt;
        M[a[i].ad] = i;
    }
    if(!M.count(head)) {
        cout << "";
        return ;
    }
    n = 0;
    while(1){
        n++;
        a[M[head]].id = n;
        pos[n] = M[head];
        if(a[M[head]].nxt == "-1") break;
        head = a[M[head]].nxt;
    }
    for(int i = 1; i <= (n + 1) / 2; i++) {
        if(!vis[n - i + 1]) {
            cout << a[pos[n - i + 1]].ad << " " << a[pos[n - i + 1]].data << " ";
            vis[n - i + 1] = 1;
            if(!vis[i]) {
                cout << a[pos[i]].ad << endl;
            } else cout << -1 << endl;
        }

        if(!vis[i]) {
            cout << a[pos[i]].ad << " " << a[pos[i]].data << " ";
            vis[i] = 1;
            if(!vis[n - (i + 1) + 1]) {
                cout << a[pos[n - (i + 1) + 1]].ad << endl;
            } else cout << -1 << endl;
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