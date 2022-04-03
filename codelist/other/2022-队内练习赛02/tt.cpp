#include<bits/stdc++.h>
#define maxn 305
#define LL long long
using namespace std;

int n,m,S,c[maxn][maxn],d[maxn],vis[maxn],id[maxn],ans;
int min_cut() {
    ans = 1 << 29;
    for(int i=1;i<=n;i++) id[i]=i;
    for(;n>1;){
        memset(vis,0,sizeof vis);
        memset(d,0,sizeof d);
        int p=0,s=0;
        for(int i=1;i<=n;i++){
            int k=0;
            for(int j=1;j<=n;j++) if(!vis[j] && (k==0||d[j]>d[k])) k=j;
            vis[k]=1;p=s,s=k;
            for(int j=1;j<=n;j++)
                if(!vis[j])
                    d[j] += c[id[k]][id[j]];
        }
        for(int i=1;i<=n;i++)
            c[id[i]][id[p]] += c[id[i]][id[s]],
                    c[id[p]][id[i]] += c[id[s]][id[i]];
        id[s] = id[n--];
        ans = min(ans , d[s]);
    }
    return ans;
}
int main(){
    while(~scanf("%d%d%d",&n,&m,&S) && n){
        memset(c,0,sizeof c);
        memset(d,0,sizeof d);
        for(int u,v,w;m--;){
            scanf("%d%d%d",&u,&v,&w);
            c[u][v] += w , c[v][u] += w;
        }

        printf("%d\n", min_cut());
    }
}