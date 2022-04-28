#include <bits/stdc++.h>
#define int long long
using namespace std;
void work() {
    string s;
    string a, b, c;
    cin >> s;
    int t = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '*') {
            a = s.substr(0, i);
            t = i;
        }
        if(s[i] == '=') {
            b = s.substr(t + 1, i - t - 1);
            c = s.substr(i + 1);
        }
    }
    if(a.size() + b.size() - 1 > c.size() || a.size() + b.size() < c.size()) {
        cout << -1 << endl;
        return ;
    }

}
signed main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    int Case;
    cin >> Case;
    while(Case--) work();
    return 0;
}