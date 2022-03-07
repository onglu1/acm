//第二题
#include <bits/stdc++.h>
using namespace std;
int n, a[109];
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[x] = 1;
    }
    int cnt = 0;
    for(int i = 1; i <= 100; i++) {
        if(a[i]) {
            cnt++;
            for(int j = i; j <= 100; j += i) {
                a[j] = 0;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}

