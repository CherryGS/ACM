#include <bits/stdc++.h>
#define mem(a,b) memset(a,(b),sizeof(a))
#define Temp template<typename T>
using namespace std;
typedef long long LL;
typedef const int& cint;
Temp inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}

#define mid ((l+r)>>1)
#define lson rt<<1,l,mid
#define rson rt<<1|1,mid+1,r
#define len (r-l+1)

const int maxn=200000+10;
int n,m,r,mod=1e9+7;
//见题意 
int e,beg[maxn],nex[maxn],to[maxn],t[maxn];
//链式前向星数组，w[]、wt[]初始点权数组 
int a[maxn<<2],laz[maxn<<2];
//线段树数组、lazy操作 
int son[maxn],id[maxn],fa[maxn],cnt,dep[maxn],siz[maxn],top[maxn]; 
//son[]重儿子编号,id[]新编号,fa[]父亲节点,cnt dfs_clock/dfs序,dep[]深度,siz[]子树大小,top[]当前链顶端节点 
int res=0;
//查询答案 
int ans[maxn];
int mx_t[maxn][20];

struct node {
    int l, x, id;
    bool operator < (const node&a) const {
        return l > a.l;
    }
};
vector<node> q1, q2; // q1 -> query ; q2 -> t

inline void pushdown(int rt,int lenn){
    laz[rt<<1]+=laz[rt];
    laz[rt<<1|1]+=laz[rt];
    a[rt<<1]+=laz[rt]*(lenn-(lenn>>1));
    a[rt<<1|1]+=laz[rt]*(lenn>>1);
    a[rt<<1]%=mod;
    a[rt<<1|1]%=mod;
    laz[rt]=0;
}

inline void add(int x,int y){//链式前向星加边 
    to[++e]=y;
    nex[e]=beg[x];
    beg[x]=e;
}
//-------------------------------------- 以下为线段树 

inline void query(int rt,int l,int r,int L,int R){
    if(L<=l&&r<=R){res+=a[rt];res%=mod;return;}
    else{
        if(laz[rt])pushdown(rt,len);
        if(L<=mid)query(lson,L,R);
        if(R>mid)query(rson,L,R);
    }
}

inline void update(int rt,int l,int r,int L,int R,int k){
    if(L<=l&&r<=R){
        laz[rt]+=k;
        a[rt]+=k*len;
    }
    else{
        if(laz[rt])pushdown(rt,len);
        if(L<=mid)update(lson,L,R,k);
        if(R>mid)update(rson,L,R,k);
        a[rt]=(a[rt<<1]+a[rt<<1|1])%mod;
    }
}
//---------------------------------以上为线段树 
inline int qRange(int x,int y){
    int ans=0;
    while(top[x]!=top[y]){//当两个点不在同一条链上 
        if(dep[top[x]]<dep[top[y]])swap(x,y);//把x点改为所在链顶端的深度更深的那个点
        res=0;
        query(1,1,n,id[top[x]],id[x]);//ans加上x点到x所在链顶端 这一段区间的点权和
        ans+=res;
        ans%=mod;//按题意取模 
        x=fa[top[x]];//把x跳到x所在链顶端的那个点的上面一个点
    }
    //直到两个点处于一条链上
    if(dep[x]>dep[y])swap(x,y);//把x点深度更深的那个点
    res=0;
    query(1,1,n,id[x],id[y]);//这时再加上此时两个点的区间和即可
    ans+=res;
    return ans%mod;
}

inline void updRange(int x,int y,int k){//同上 
    k%=mod;
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]])swap(x,y);
        update(1,1,n,id[top[x]],id[x],k);
        x=fa[top[x]];
    }
    if(dep[x]>dep[y])swap(x,y);
    update(1,1,n,id[x],id[y],k);
}

inline void dfs1(int x,int f,int deep){//x当前节点，f父亲，deep深度 
    dep[x]=deep;//标记每个点的深度 
    fa[x]=f;//标记每个点的父亲 
    siz[x]=1;//标记每个非叶子节点的子树大小 
    int maxson=-1;//记录重儿子的儿子数
    mx_t[x][0] = f;
    for(int i=beg[x];i;i=nex[i]){
        int y=to[i];
        if(y==f)continue;//若为父亲则continue 
        dfs1(y,x,deep+1);//dfs其儿子 
        siz[x]+=siz[y];//把它的儿子数加到它身上 
        if(siz[y]>maxson)son[x]=y,maxson=siz[y];//标记每个非叶子节点的重儿子编号 
    }
}

inline void dfs2(int x,int topf){//x当前节点，topf当前链的最顶端的节点 
    id[x]=++cnt;//标记每个点的新编号 
    top[x]=topf;//这个点所在链的顶端 
    if(!son[x])return;//如果没有儿子则返回 
    dfs2(son[x],topf);//按先处理重儿子，再处理轻儿子的顺序递归处理 
    for(int i=beg[x];i;i=nex[i]){
        int y=to[i];
        if(y==fa[x]||y==son[x])continue;
        dfs2(y,y);//对于每一个轻儿子都有一条从它自己开始的链 
    }
}

int deal(int loc, cint max_t) {
    // cout << loc << "-----" << endl;
    for(int i=18; i>=0; i--) {
        if(max_t >= t[mx_t[loc][i]]) loc = mx_t[loc][i];
    }
    // cout << "-----" << loc << endl;
    return loc;
}

void debug() {
    for(int i=0; i<=18; i++) {
        for(int j=1; j<=n; j++)
            cout << mx_t[j][i] << ' ';
            cout << endl;
    }
}

void debug1() {
    cout << endl;
    for(auto k : q1) {
        cout << k.id << ' ' << k.l << ' ' << k.x << endl;
    }
    cout << "---" << endl;
    for(auto k:q2) {
        cout << k.id << ' ' << k.l << endl;
    }
    cout << endl;
}

int main(){
    r = 1;
    read(n);
    for(int i=1;i<n;i++){
        int a,b;
        read(a);read(b);
        add(a,b);add(b,a);
    }
    dfs1(r,r,1);
    dfs2(r,r);
    for(int i=1; i<=n; i++) read(t[i]);
    for(int i=1; i<=n; i++) q2.push_back( {t[i], 0, i} );
    // cout << mx_t[4][0] << endl;
    for(int i=1; i<=18; i++) {
        for(int j=1; j<=n; j++) {
            mx_t[j][i] = mx_t[mx_t[j][i-1]][i-1];
        }
    }
    // debug();
    read(m);
    int ql, qr, st;
    for(int i=1; i<=m; i++) {
        read(st); read(ql); read(qr);
        if(qr >= t[st] && ql <= t[st]) q1.push_back( {ql, deal(st, qr), i} );
    }
    sort(q1.begin(), q1.end());
    sort(q2.begin(), q2.end());
    int le1 = q1.size(), le2 = q2.size();
    int l1 = 0, l2 = 0;
    // debug1();
    while(l1 < le1 || l2 < le2) {
        while((q1[l1].l > q2[l2].l || l2 == le2) && l1 < le1) {
            ans[q1[l1].id] = qRange(q1[l1].x, q1[l1].x);
            ++l1;
        }
        while((q1[l1].l <= q2[l2].l || l1 == le1) && l2 < le2) {
            updRange(1, q2[l2].id, 1);
            ++l2;
        }
        // cout << l1 << ' ' << l2 << ' ' << q1[l1].l << ' ' << q2[l2].l << endl;
    }
    for(int i=1; i<=m; i++) cout << ans[i] << endl;
}