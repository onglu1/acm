#include <bits/stdc++.h>
using namespace std;
//第一题
int main()
{
    int preid = 0, d;
    char c;
    vector<int> v[2];
    while(~scanf("%d/%c", &d, &c)) {
        static int cnt = 0;
        cnt++;
        if(cnt == 1) {
            v[0].push_back(d);
        } else {
            if(c == 'N')
                preid = 1 - preid;
            v[preid].push_back(d);
        }
    }
    sort(v[0].begin(), v[0].end());
    sort(v[1].begin(), v[1].end());
    if(v[0].empty()) {
        swap(v[0], v[1]);
    }
    if(!v[0].empty() && ! v[1].empty()) {
        if(v[0][0] > v[1][0]) {
            swap(v[0], v[1]);
        }
    }
    for(auto x : v[0]) printf("%d ", x);
    printf("\n");
    if(v[1].size()) {
        for(auto x : v[1]) printf("%d ", x);
        printf("\n");
    }
    return 0;
}

