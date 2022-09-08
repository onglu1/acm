#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
using namespace std;
const int N = 1e6 + 1009;
int n, ans;
signed main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    string s;
    for(int i = 1; i <= n; i++) {
        cin >> s;
        if(s[0] == 'i' || s[0] == 'l') {
            int base = 4;
            if(s[0] == 'i') base = 4;
            else if(s[0] == 'l') base = 8;
            string t;
            getline(cin, t);
            if(s[s.size() - 1] == ']') {
                for(int j = 0; j < t.size(); j++) {
                    if(t[j] == '[') {
                        int k = j + 1;
                        int num = 0;
                        while(t[k] != ']') {
                            num = num * 10 + t[k] - '0';
                            k += 1;
                        }
                        ans += base * num;
                        j = k;
                    }
                }
            } else {
                ans += base;
                for(int j = 0; j < t.size(); j++) {
                    if(t[j] == ',') {
                        ans += base;
                    }
                }
            }
        } else {
            int pre = -1;
            string t;
            cin >> t;
            for(int j = 0; j < t.size(); j++) if(t[j] == '"') {
                if(pre == -1) {
                    pre = j;
                } else {
                    ans += (j - pre - 1);
                    pre = -1;
                }
            }
        }
    }
    int pp[4];
    pp[0] = ans % 1024; ans /= 1024;
    pp[1] = ans % 1024; ans /= 1024;
    pp[2] = ans % 1024; ans /= 1024;
    pp[3] = ans % 1024; ans /= 1024;
    string ss[] = {"B", "KB", "MB", "GB"};
    for(int i = 3; i >= 0; i--) {
        if(pp[i] != 0) {
            cout << pp[i] << ss[i];
        }
    }
    cout << endl;
    return 0;
}