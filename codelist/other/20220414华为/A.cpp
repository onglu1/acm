#include <bits/stdc++.h>
using namespace std;
void no() {
    cout << '/' << endl;
    exit(0);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    getline(cin, s);
    int i = 0;
    vector<string> sta;
    while(i < s.size()) {
        int j = i + 1;
        while(j < s.size() && s[j] != '/') j++;
        if(j - i - 1 == 0) no();
        string ss = s.substr(i + 1, j - i - 1);
        i = j;
        if(ss == ".") continue;
        if(ss == "..") {
            if(sta.empty()) no();
            else {
                sta.pop_back();
                continue;
            }
        }
        if(ss.size() == 0) no();
        for(auto c : ss) {
            if( !(  ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')  ) ) {
                no();
            }
        }
        sta.push_back(ss);
    }
    for(auto x : sta) {
        cout << "/" << x;
    }
    cout << endl;
    return 0;
}
/*
 *
/aa/bb/./../cc
 */