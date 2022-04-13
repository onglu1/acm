#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 1009;
int n, m;
int lsize, rsize;
struct node {
    int l, r;
} ;
stack<node> s1, s2;
//在s中插入t区间，顺便合并
void add(const node &t, stack<node> &s) {
    if(s.empty() || t.r < s.top().l) {
        s.push(t);
        return ;
    }
    stack<node> tmp;
    while(true) {
        if(s.empty()) {
            s.push(t);
            break;
        }
        if(t.r < s.top().l) {
            //合并
            if(t.r == s.top().l - 1) {
                s.top().l = t.l;
            } else {
                s.push(t);
            }
            break;
        }
        tmp.push(s.top());
        s.pop();
    }
    while(!tmp.empty()) {
        if(!s.empty() && s.top().l == tmp.top().r + 1) {
            s.top().l = tmp.top().l;
        } else {
            s.push(tmp.top());
        }
        tmp.pop();
    }
}
// 把s2最后q个元素加入s1
void push(stack<node> &s1, stack<node> &s2, int q) {
    while (q > 0) {
        if(s2.empty()) break;
        int len = min(q, s2.top().r - s2.top().l + 1);
        q -= len;
        if (len < s2.top().r - s2.top().l + 1) {
            add({s2.top().l, s2.top().l + len - 1}, s1);
            s2.top().l = s2.top().l + len;
        } else {
            add(s2.top(), s1);
            s2.pop();
        }
    }
}
//输出
void print() {
    stack<node> s = s1;
    vector<int> ans;
    while(s.size()) {
        for(int i = s.top().l; i <= s.top().r; i++) {
            ans.push_back(i);
        }
        s.pop();
    }
    std::reverse(ans.begin(), ans.end());
    s = s2;
    while(s.size()) {
        for(int i = s.top().l; i <= s.top().r; i++) {
            ans.push_back(i);
        }
        s.pop();
    }
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " \n"[i + 1 == ans.size()];
    }
}
signed main() {
    cin >> n >> m;
    s2.push({1, n});
    lsize = 0;
    rsize = n;
    while(m--) {
        int opt, q;
        cin >> opt >> q;
        if(opt == 0) {
            q -= lsize;
            if(q <= 0) continue;
            rsize -= q;
            lsize += q;
            push(s1, s2, q);
        } else {
            q = n - q + 1;
            q -= rsize;
            if(q <= 0) continue;
            lsize -= q;
            rsize += q;
            push(s2, s1, q);
        }
    }
    print();
    return 0;
}