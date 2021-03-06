#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include <queue>
#include<sstream>
#include <stack>
#include <set>
#include <bitset>
#include<vector>
#define FAST ios::sync_with_stdio(false)
#define abs(a) ((a)>=0?(a):-(a))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define mem(a,b) memset(a,b,sizeof(a))
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define rep(i,a,n) for(int i=a;i<=n;++i)
#define per(i,n,a) for(int i=n;i>=a;--i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PII;
const int maxn = 2e5+200;
const int inf=0x3f3f3f3f;
const double eps = 1e-7;
const double pi=acos(-1.0);
const int mod = 1e9+7;
inline int lowbit(int x){return x&(-x);}
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
void ex_gcd(ll a,ll b,ll &d,ll &x,ll &y){if(!b){d=a,x=1,y=0;}else{ex_gcd(b,a%b,d,y,x);y-=x*(a/b);}}//x=(x%(b/d)+(b/d))%(b/d);
inline ll qpow(ll a,ll b,ll MOD=mod){ll res=1;a%=MOD;while(b>0){if(b&1)res=res*a%MOD;a=a*a%MOD;b>>=1;}return res;}
inline ll inv(ll x,ll p){return qpow(x,p-2,p);}
inline ll Jos(ll n,ll k,ll s=1){ll res=0;rep(i,1,n+1) res=(res+k)%i;return (res+s)%n;}
inline ll read(){ ll f = 1; ll x = 0;char ch = getchar();while(ch>'9'|ch<'0') {if(ch=='-') f=-1; ch = getchar();}while(ch>='0'&&ch<='9') x = (x<<3) + (x<<1) + ch - '0',  ch = getchar();return x*f; }
int dir[4][2] = { {1,0}, {-1,0},{0,1},{0,-1} };

ll pos[maxn];
ll neg[maxn];

ll pre1[maxn];
ll pre2[maxn];

ll p1 = 0;
ll p2 = 0;

int main()
{
    ll n = read(), t = read();
    ll flag = 0;
    rep(i,1,n)
    {
        ll x = read();
        if(x < 0) neg[++p1] = -x;
        else if(x>0) pos[++p2] = x;
        else flag = 1;
    }

    sort(neg+1,neg+1+p1);
    pre1[0] = pre2[0] = 0;
    rep(i,1,p1) pre1[i] = pre1[i-1] + neg[i];
    rep(i,1,p2) pre2[i] = pre2[i-1] + pos[i];
    ll ans = 0;
    ll cur = 0;
    rep(i,1,p1)
    {
        if(neg[i] > t) break;
        cur ++;
    }
    ans = max(ans, cur) ;

    cur = 0;
    rep(i,1,p2)
    {
        if(pos[i] > t) break;
        cur++;
    }
    ans = max(ans,cur);

    rep(i,1,p1)
    {
        ll tmp = neg[i];
        ll Left = t - neg[i] * 2;
        if(Left < 0 ) break;
        ll idx = upper_bound(pos+1,pos+1+p2, Left) - pos;
        idx --;
        cur = idx + i;
        ans = max(cur,ans);
    }

    rep(i,1,p2)
    {
        ll tmp = pos[i];
        ll Left = t - pos[i]*2;
        if(Left < 0) break;
        ll idx = upper_bound(neg+1,neg+1+p1,Left) - neg;
        idx --;
        cur = idx + i;
        ans = max(cur,ans);
    }
    cout<<ans + flag<<'\n';
    return 0;
}