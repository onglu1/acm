#include <bits/stdc++.h>
#define int long long
using namespace std;
int vis[20], rk[500];
int ans, n;
int cont(string s) {

}
signed main()
{
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    int cnt = 0;
    for(int i = 'a'; i <= 'r'; i++) if(i != 'm') {
        rk[i] = ++cnt;
    }
    string s1, s2;
    cin >> s1;
    cin >> s2;
    int a = cont(s1);
    int b = cont(s2);
    return 0;
}