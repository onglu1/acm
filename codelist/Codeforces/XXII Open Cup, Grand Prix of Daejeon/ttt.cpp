/*
Author: cnyz
----------------
Looking! The blitz loop this planet to search way.
Only my RAILGUN can shoot it. 今すぐ
*/
#include<bits/stdc++.h>
using namespace std;
using db=double;
using ll=long long;
using pii=pair<int,int>;
using vi=vector<int>;
using ull=unsigned long long;
#define pb push_back
#define emp emplace_back
#define fir first
#define sec second
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define sz(a) (int)a.size()
const int inf=1e8,N=250000;
multiset<pii> U[N*2+10],V[N*2+10];
struct node {
    int ux,uy,vx,vy,val;
    node(): ux(inf),uy(inf),vx(inf),vy(inf),val(inf+inf) {}
    void change(int id) {
        ux=uy=vx=vy=inf;
        if(sz(U[id])) ux=begin(U[id])->fir,uy=begin(U[id])->sec;
        if(sz(V[id])) vx=begin(V[id])->fir,vy=begin(V[id])->sec;
        val=min(ux+vx,uy+vy);
    }
} tr[N*8+10];
node operator + (node a,node b) {
    node ret;
    ret.ux=min(a.ux,b.ux),ret.uy=min(a.uy,b.uy),
    ret.vx=min(a.vx,b.vx),ret.vy=min(a.vy,b.vy),
    ret.val=min({a.vx+b.ux,a.uy+b.vy,a.val,b.val});
    return ret;
}
void update(int p,int l,int r,int id) {
    if(l==r) return tr[p].change(id);
    int mid=(l+r)>>1;
    if(id<=mid) update(p*2,l,mid,id);
    else update(p*2+1,mid+1,r,id);
    tr[p]=tr[p*2]+tr[p*2+1];
}
int main() {
    int q;scanf("%d",&q);
    FOR(i,1,q) {
        int op,opt,x,y;scanf("%d %d %d %d",&op,&opt,&x,&y);
        int id=(opt==1?x-y:y-x)+N;
        multiset<pii> &tm=(opt==1?U[id]:V[id]);
        if(op==1) tm.insert({x,y});
        else tm.erase({x,y});
        update(1,0,N+N,id);
        int ans=tr[1].val;
        if(ans>=inf) ans=-1;
        printf("%d\n",ans);
    }
}