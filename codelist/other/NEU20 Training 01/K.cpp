#include <bits/stdc++.h>
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)

using namespace std;
int n;

#define gc()(is==it?it=(is=in)+fread(in,1,Q,stdin),(is==it?EOF:*is++):*is++)
const int Q=(1<<24)+1;
char in[Q],*is=in,*it=in,c;
void read(int &n){
    for(n=0;(c=gc())<'0'||c>'9';);
    for(;c<='9'&&c>='0';c=gc())n=n*10+c-48;
}

const int N = 2e5 + 9;
const int inf = 0x7fffffff;
struct Tree {
    struct node{
        int l,r;
        int val,key;
        int cnt,Size;
    }a[N];
    int n,opt,root,seed=233,tot=0;
    int rand(){
        return seed=(int)seed*482711LL % 2147483647;
    }
    void clear() {
        memset(a, 0, sizeof(a));
        seed = 233;
        opt = 0; root = 0;
        tot = 0; n = 0;
        New(-inf);New(inf);
        root=1;a[1].r=2;
        up(root);
    }
    int New(int val){
        a[++tot].val=val;
        a[tot].key=rand();
        a[tot].cnt=a[tot].Size=1;
        return tot;
    }
    void up(int k){
        a[k].Size=a[a[k].l].Size+a[a[k].r].Size+a[k].cnt;
    }

    void zig(int &p){
        int q=a[p].l;
        a[p].l=a[q].r;a[q].r=p;p=q;
        up(a[p].r),up(p);
    }
    void zag(int &p){
        int q=a[p].r;
        a[p].r=a[q].l;a[q].l=p;p=q;
        up(a[p].l),up(p);
    }
    void ins(int &p,int val){
        if(p==0){
            p=New(val);
            return ;
        }
        if(val==a[p].val){
            a[p].cnt++;up(p);
            return ;
        }
        if(val<a[p].val){
            ins(a[p].l,val);
            if(a[p].key<a[a[p].l].key)zig(p);
        }
        else{
            ins(a[p].r,val);
            if(a[p].key<a[a[p].r].key)zag(p);
        }
        up(p);
    }
    void del(int &p,int val){
        if(p==0)return ;
        if(val==a[p].val){
            if(a[p].cnt>1){
                a[p].cnt--;up(p);
                return;
            }
            if(a[p].l||a[p].r){
                if(a[p].r==0||a[a[p].l].key>a[a[p].r].key)
                    zig(p),del(a[p].r,val);
                else
                    zag(p),del(a[p].l,val);
                up(p);
            }
            else p=0;
            return;
        }
        val<a[p].val?del(a[p].l,val):del(a[p].r,val);
        up(p);
    }
    int getrankbyval(int p,int val){
        if(p==0)return 0;
        if(val==a[p].val)return a[a[p].l].Size+1;
        if(val<a[p].val)return getrankbyval(a[p].l,val);
        return getrankbyval(a[p].r,val)+a[a[p].l].Size+a[p].cnt;
    }
    int getvalbyrank(int p,int rank){
        if(p==0)return inf;
        if(a[a[p].l].Size>=rank)return getvalbyrank(a[p].l,rank);
        if(a[a[p].l].Size+a[p].cnt>=rank)return a[p].val;
        return getvalbyrank(a[p].r,rank-a[a[p].l].Size-a[p].cnt);
    }
    int getpre(int val){
        int ans=1;
        int p=root;
        while(p){
            if(val==a[p].val){
                if(a[p].l>0){
                    p=a[p].l;
                    while(a[p].r>0)p=a[p].r;
                    ans=p;
                }
                break;
            }
            if(a[p].val<val&&a[p].val>a[ans].val)ans=p;
            p=val<a[p].val?a[p].l:a[p].r;
        }
        return a[ans].val;
    }
    int getnext(int val){
        int ans=2;
        int p=root;
        while(p){
            if(val==a[p].val){
                if(a[p].r>0){
                    p=a[p].r;
                    while(a[p].l>0)p=a[p].l;
                    ans=p;
                }
                break;
            }
            if(a[p].val>val&&a[p].val<a[ans].val)ans=p;
            p=val<a[p].val?a[p].l:a[p].r;
        }
        return a[ans].val;
    }
} t;


struct node {
    int t, x;
};
bool operator<(const node &a, const node &b) {
    return a.t > b.t;
}
priority_queue<node> q;
void work() {
    static int cnt = 0;
    printf("Case %d:\n", ++cnt);
    read(n);
    int ct = 0;
    while(q.size()) q.pop();
    t.clear();
    for(int i = 1; i <= n; i++) {
        int opt;
        read(opt);
        if(opt == 1) {
            int st, x, ed;
            read(st); read(x);
            read(ed);
            t.ins(t.root, x);
            ct++;
            q.push({ed, x});
        } else {
            int st, k;
            read(st); read(k);
            while(q.size() && q.top().t < st) {
                t.del(t.root, q.top().x);
                q.pop();
                ct--;
            }
            if(k > 0 && ct >= k) {
                printf("%d\n", t.getvalbyrank(t.root,k+1));
            } else printf("-1\n");
        }
    }
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    int Case;
    read(Case);
//    cin >> Case;
//Case = 1;
    while (Case--) work();
    return 0;
}
-