#include <bits/stdc++.h>
using namespace std;
struct node {
    int a, b, c;
    string s;
};
vector<node> v;
int cmp(node &a, node &b) {
    if(a.a != b.a) return a.a > b.a;
    if(a.b != b.b) return a.b > b.b;
    return a.c > b.c;
}
int n;
signed main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        int pos1 = s.find('.'), pos2 = s.find('.', pos1 + 1);
        int a = 0, b = 0, c = 0;
        for(int j = 0; j < pos1; j++) {
            a = a * 10 + s[j] - '0';
        }
        for(int j = pos1 + 1; j < pos2; j++) {
            b = b * 10 + s[j] - '0';
        }
        for(int j = pos2 + 1; j < s.size(); j++) {
            c = c * 10 + s[j] - '0';
        }
        v.push_back({a, b, c, s});
    }
    sort(v.begin(), v.end(), cmp);
    for(auto x : v) {
        cout << x.s << endl;
    }
    return 0;
}