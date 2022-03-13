//
// Created by onglu on 2022/3/9.
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
int nxt(string &s, int pos) {
    while(pos < s.size() && (isalpha(s[pos]) || isdigit(s[pos]))) pos++;
    return pos;
}
int issplit(string &s, int pos) {
    if(pos >= s.size()) return true;
    if(isalpha(s[pos])) return false;
    if(isdigit(s[pos])) return false;
    return true;

}
void work() {
    string s;
    getline(cin, s);
    cout << s << endl;
    cout << "AI: ";
    for(int i = 0; i < s.size(); i++) {
        if(s[i] != 'I' && 'A' <= s[i] && s[i] <= 'Z') {
            s[i] = s[i] - 'A' + 'a';
        }
    }
    int i = 0;
    string t = "";
    int pre = 0;
    while(i < s.size()) {
        if(s[i] == ' ') {
            i += 1;
            pre = 1;
            continue;
        }
        else if((isalpha(s[i]) || isdigit(s[i]))) {
            int j = nxt(s, i);
            t += (pre == 1 ? " " : "") + s.substr(i, j - i);
            i = j;
        } else {
            t += s[i];
            i += 1;
            pre = 0;
        }
    }
    i = 0;
    pre = 0;
    int prefix = 0;
    while(i < t.size()) {
        if(isalpha(t[i]) || isdigit(t[i])) {
            if(i + 7 <= t.size() && t.substr(i, 7) == "can you" && issplit(t, i + 7)) {
                cout << "I can";
                i = i + 7;
            } else if(i + 9 <= t.size() && t.substr(i, 9) == "could you" && issplit(t, i + 9)) {
                cout << "I could";
                i = i + 9;
            } else if(i + 1 <= t.size() && t.substr(i, 1) == "I" && issplit(t, i + 1)){
                cout << "you";
                i = i + 1;
            } else if(i + 2 <= t.size() && t.substr(i, 2) == "me" && issplit(t, i + 2)){
                cout << "you";
                i = i + 2;
            } else {
                int j = nxt(t, i);
                cout << t.substr(i, j - i);
                i = j;

            }
            prefix = 1;
        } else {

            if(t[i] == '?') {
                prefix = 1;
                cout << "!";
            }
            else if(t[i] == ' ') {
                if(prefix) cout << t[i];
            } else {
                prefix = 1;
                cout << t[i];
            }
            i++;
        }
    }
    cout << endl;
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Case = 0;
    cin >> Case;
    cin.ignore();
    while (Case--) work();
    return 0;
}