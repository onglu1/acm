#include <bits/stdc++.h>
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
#define int long long
using namespace std;
const int N = 2e5 + 1009;
int n, ans, g[3][3];
int cnt[2];
vector<string> v;
signed main()
{
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios ::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    ans = 0;
    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < s.size(); j++) if(s[j] == 'w') {
            if(0 < j && j + 1 < s.size() && s[j - 1] == 'o' && s[j + 1] == 'o') {
                ans++;
            }
        }
        if(s.size() == 1) {
            if(s[0] == 'o') cnt[0] += 1;
            else cnt[1] += 1;
        } else {
            int bef, suf;
            if(s[0] == 'o') bef = 0;
            else if(s.size() > 1 && s[0] == 'w' && s[1] == 'o') bef = 1;
            else bef = 2;
            if(s[s.size() - 1] == 'o') suf = 0;
            else if(s.size() > 1 && s[s.size() - 1] == 'w' && s[s.size() - 2] == 'o') suf = 1;
            else suf = 2;
            g[bef][suf]++;
        }
    }

    return 0;
}
/*
0表示为o，
1表示为wo
2表示为ww
*/