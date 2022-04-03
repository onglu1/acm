//
// Created by onglu on 2022/3/19.
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
const int N = 2e6 + 1009;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309
int n, m, a[N];
string s;
vector<char> v;
map<char, int> M;
void work() {
    cin >> s;
    for(char c : s) {
        v.push_back(c);
    }
    sort(rall(v));
    v.resize(unique(all(v)) - v.begin());
    for(int i = 0; i < v.size(); i++) {
        M[v[i]] = i;
    }
    printf("int[] arr = new int[]{");
    printf("%c", v[0]);
    for(int i = 1; i < v.size(); i++) {
        printf(",%c", v[i]);
    }
    printf("};\n");
    printf("int[] index = new int[]{");
    for(auto x : s) {
        static int cnt = 0;
        cnt++;
        if(cnt == 1) {
            printf("%d", M[x]);
        } else {
            printf(",%d", M[x]);
        }
    }
    printf("};\n");
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