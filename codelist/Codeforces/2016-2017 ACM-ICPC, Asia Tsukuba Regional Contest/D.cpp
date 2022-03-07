#include <bits/stdc++.h>

#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int N = 2e6 + 1009;
int n, m, a[N];
string s, t;
struct node {
    int a[26];
};
bool operator<(const node &a, const node &b) {
    for(int i = 0; i < 26; i++) {
        if(a.a[i] != b.a[i])
            return a.a[i] < b.a[i];
    }
    return a.a[25] < b.a[25];
}
set<node> S;
void get(int x) {
    S.clear();
    if(t.size() < x) return ;
    node p;
    for(int i = 0; i < 26; i++) p.a[i] = 0;
    for(int i = 0; i < x - 1; i++) {
        p.a[t[i] - 'a']++;
    }
    for(int i = x - 1; i < t.size(); i++) {
        p.a[t[i] - 'a']++;
        S.insert(p);
        p.a[t[i - (x - 1)] - 'a']--;
    }
}
int check(int x) {
    node p;
    for(int i = 0; i < 26; i++) p.a[i] = 0;
    for(int i = 0; i < x - 1; i++) {
        p.a[s[i] - 'a']++;
    }
    for(int i = x - 1; i < s.size(); i++) {
        p.a[s[i] - 'a']++;
        if(S.count(p)) {
            return 1;
        }
        p.a[s[i - (x - 1)] - 'a']--;
    }
    return 0;
}
signed main() {
#ifdef LOCALCOMPILE
    auto startTime = clock();
    freopen("C:\\Users\\onglu\\CLionProjects\\ACM\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\ACM\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s >> t;
//    cout << 111 << endl;
    int ans = 0;
    for(int i = 1; i <= min(s.size(), t.size()); i++) {
        get(i);
        if(check(i)) {
            ans = i;
        }

    }
    cout << ans << endl;
#ifdef LOCALCOMPILE
    cout << "The run time is: " <<(double)(clock() - startTime) * 1000 / CLOCKS_PER_SEC << "ms" << endl;
#endif
    return 0;
}