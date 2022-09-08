#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int MAX_N = 100 + 10, MAX_M = 'Z' + 10;

vector<int> fr[MAX_M], ed[MAX_M], fi[MAX_M], mid[MAX_M];

bool hd[MAX_N];
char s[MAX_N][MAX_N];
int T, n, nxt[MAX_N];

int getFr(char s[], int x) {
    fr[s[0]].push_back(x);
    int m = strlen(s), p = 0;
    for (; p < m; ++p)
        if (s[p] != s[0]) {
            return p;
        }
}

int getEd(char s[], int x) {
    int m = strlen(s), p = m - 1;
    ed[s[m - 1]].push_back(x);
    for (; p >= 0; --p)
        if (s[p] != s[m - 1]) {
            return p;
        }
}

bool pure(int x) {
    int m = strlen(s[x]), p = 0;
    for(int i = 0; i < m; i++) if(s[x][i] != s[x][0]) return false;
    fi[s[x][0]].push_back(x);
    return true;
}
int work() {
    cin >> n;
    for (int i = 'A'; i <= 'Z'; ++i)
        fr[i].clear(), ed[i].clear(), fi[i].clear(), mid[i].clear();

    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        nxt[i] = -1;
        hd[i] = 1;

        if (!pure(i)) {
            int x = getFr(s[i], i), y = getEd(s[i], i);
            for (int j = x; j <= y; ++j)
                if (s[i][j] != s[i][j - 1]) mid[s[i][j]].push_back(i);
        }
    }
    static int _ = 0;
    _++;
    cout << "Case #" << _ << ": ";
    for (int i = 'A'; i <= 'Z'; ++i) {
        if (mid[i].size() > 1) return false;
        else if (mid[i].size() == 1) if ((fr[i].size() || ed[i].size() || fi[i].size())) return false;
        if((fr[i].size() > 1)) return false;
        if(ed[i].size() > 1) return false;
    }
    for (int i = 'A'; i <= 'Z'; ++i) {
        int m = fi[i].size();
        for (int j = 0; j < m - 1; ++j) {
            int p = fi[i][j], q = fi[i][j + 1];
            nxt[p] = q;
            hd[q] = 0;
        }
    }
    for (int i = 'A'; i <= 'Z'; ++i) {
        if (fr[i].size()) {
            auto x = fr[i].begin();
            if (fi[i].size()) {
                nxt[*fi[i].rbegin()] = *x;
                hd[*x] = 0;
            }
        }
    }
    for (int i = 'A'; i <= 'Z'; i++) {
        if (ed[i].size()) {
            auto x = ed[i].begin();
            if (fi[i].size()) {
                nxt[*x] = *fi[i].begin();
                hd[*fi[i].begin()] = 0;
            } else if (fr[i].size()) {
                nxt[*x] = *fr[i].begin();
                hd[*fr[i].begin()] = 0;
            }
        }
    }
    int tot = 0;
    for (int i = 0; i < n; ++i) if (hd[i]){
        for (int x = i; x != -1; x = nxt[x])
            ++tot;
    }
    if (tot < n) return false;
    for (int i = 0; i < n; ++i) if (hd[i]){
        for (int x = i; x != -1; x = nxt[x])
            cout << s[x];
    }
    cout << endl;
    return true;
}
signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Case = 1;
    cin >> Case;
    while(Case--)
        if(!work())
            cout << "IMPOSSIBLE" << endl;
    return 0;
}
