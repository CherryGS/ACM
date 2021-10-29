#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double db;
typedef long double ld;

#define IL inline
#define fi first
#define se second
#define mk make_pair
#define pb push_back
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
#define dbg1(x) cout << #x << " = " << x << ", "
#define dbg2(x) cout << #x << " = " << x << endl

template<typename Tp> IL void read(Tp &x) {
    x=0; int f=1; char ch=getchar();
    while(!isdigit(ch)) {if(ch == '-') f=-1; ch=getchar();}
    while(isdigit(ch)) { x=x*10+ch-'0'; ch=getchar();}
    x *= f;
}
int buf[42];
template<typename Tp> IL void write(Tp x) {
    int p = 0;
    if(x < 0) { putchar('-'); x=-x;}
    if(x == 0) { putchar('0'); return;}
    while(x) {
        buf[++p] = x % 10;
        x /= 10;
    }
    for(int i=p;i;i--) putchar('0' + buf[i]);
}

const int mod = 998244353;
const int N = 5000 + 5;

int n;
int a[N], inv[N], f[N][N];

int main() {
    read(n);
    for(int i=1;i<=n;i++) read(a[i]);
    inv[1] = 1;
    for(int i=2;i<=n;i++) inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
    for(int j=n;j>=1;j--) {
        ll sum = 0, cnt = 0;
        for(int i=n;i>=0;i--) {
            if(a[i] < j) {
                f[a[i]][j] = 1;
                if(cnt > 0) (f[a[i]][j] += sum * inv[cnt] % mod) %= mod;
            }
            if(a[i] > j) {
                (sum += f[j][a[i]]) %= mod;
                cnt++;
            }
        }
    }
    ll ans = 0;
    for(int i=1;i<=n;i++) (ans += f[0][i]) %= mod;
    (ans *= inv[n]) %= mod;
    write(ans); putchar(10);
    return 0;
}