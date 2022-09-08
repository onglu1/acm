#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <string.h>
#include <string>
#include <map>
#include <set>
#define pii pair<int, int>
#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
int read() {
    char c; int num, f = 1;
    while(c = getchar(),!isdigit(c)) if(c == '-') f = -1; num = c - '0';
    while(c = getchar(), isdigit(c)) num = num * 10 + c - '0';
    return f * num;
}
namespace KMP {
    void get_next(char *t, int m, int *nxt) {
        int j = nxt[0] = 0;
        for(int i = 1; i < m; i++) {
            while(j && t[i] != t[j]) j = nxt[j - 1];
            nxt[i] = j += (t[i] == t[j]);
        }
    }
    vector<int> find(char *t, int m, int *nxt, char *s, int n) {
        vector<int> ans;
        int j = 0;
        for(int i = 0; i < n; i++) {
            while(j && s[i] != t[j]) j = nxt[j - 1];
            j += s[i] == t[j];
            if(j == m) {
                ans.push_back(i - m + 1);
                j = nxt[j - 1];
            }
        }
        return ans;
    }
}
const int N = 2e6 + 1009;
int nxt[N];
char s[N], t[N];
signed main()
{
    scanf("%s%s", s, t);
    int n = strlen(s), m = strlen(t);
    KMP :: get_next(s, n, nxt);
//    vector<int> pos = KMP :: find(t, m, nxt, s, n);
//    for(auto x : pos) printf("%d\n", x + 1);
//    for(int i = 0; i < m; i++) printf("%d%c", nxt[i], " \n"[i == m - 1]);
    for(int i = 0; i < n; i++) cout << nxt[i] << " ";
    return 0;
}