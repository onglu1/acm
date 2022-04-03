#include <bits/stdc++.h>

using namespace std;
int k, n;
int get(int k) {
    if(k > 50) k = 50;
    return k / 10;
}
int main() {
    cin >> k >> n;
    for (int i = 1; i <= n; i++)
        k += get(k) + 5;
    cout << k;
    return 0;
}