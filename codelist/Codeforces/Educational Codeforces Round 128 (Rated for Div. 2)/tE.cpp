#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
int gcd(int x,int y){
    if(x == 0)return y;
    else return gcd(y%x,x);
}
int qpow(int x,int y){
    int ans = 1;
    for(;y;y/=2,x=x*x%mod){
        if(y&1)ans=ans*x%mod;
    }
    return ans;
}
int n,m,l,R;
int a[N];
int b[N];
int q1[N];
int q2[N];
int h1[N];
int h2[N];
char r[2][N];
signed main(){
    int T = 1;
    scanf("%lld",&T);
    while(T--){
        scanf("%lld",&n);
        int min1 = n,max1 = 0;
        int min2 = n,max2 = 0;
        int num1q = 0;
        int num1h = 0;
        int num2q = 0;
        int num2h = 0;
        for(int i = 1; i <= n; i++){
            cin >> r[1][i];
            q1[i] = num1q;
            if(r[1][i] == '*'){
                min1 = min(min1,i);
                max1 = max(max1,i);
                num1q++;
            }
        }
        for(int i = 1; i <= n; i++){
            cin >> r[2][i];
            q2[i] = num2q;
            if(r[2][i] == '*'){
                min2 = min(min2,i);
                max2 = max(max2,i);
                num2q++;
            }
        }
        for(int i = n; i >= 1; i--){
            h2[i] = num2h;
            h1[i] = num1h;
            if(r[1][i] == '*'){
                num1h++;
            }
            if(r[2][i] == '*'){
                num2h++;
            }
        }
        q1[0] = 0,q2[0] = 0;
        h1[0] = num1h,h2[0] = num2h;
        q1[n + 1] = num1q,q2[n + 1] = num2q;
        h1[n + 1] = 0,h2[n + 1] = 0;
        min1 = min(min1,min2);
        max1 = max(max1,max2);
        int ans = mod;
        ans = min(num1h,num2h) + max1 - min1;
        for(int i = min1; i <= max1; i++){
            ans = min(ans,max1 - min1 + 1 + q1[i] + h2[i]);
            ans = min(ans,max1 - min1 + 1 + q2[i] + h1[i]);
        }
        printf("%lld\n",ans);
    }
}
/*
5
1
*
.
2
.*
**
3
*.*
.*.
4
**.*
**..
5
*.*.*
*...*

*/
