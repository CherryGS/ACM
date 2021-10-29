#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define ll long long
#define cint const int&

const int mod = 1e9 + 7;

struct stu {
    ll p[5][5];
    int x, y;
    stu() { memset(p, 0, sizeof(p)); }
    void cl() {
        if(x == y)
            for (int i = 1; i <= x; i++) p[i][i] = 1;
    }
};

stu operator*(const stu& a, const stu& b) {
    stu tem;
    for (int i = 1; i <= a.x; i++)
        for (int j = 1; j <= b.y; j++)
            for (int k = 1; k <= b.x; k++)
                (tem.p[i][j] += a.p[i][k] * b.p[k][j]) %= mod;
    tem.x = a.x;
    tem.y = b.y;
    return tem;
}

inline stu ksm(stu a, ll x) {
    stu bs;
    bs.x = a.x;
    bs.y = a.y;
    bs.cl();
    for (; x; x >>= 1, a = a * a)
        if (x % 2) bs = bs * a;
    return bs;
}

ll ksm1(ll bs, int x) {
    ll ans=1;
    while(x) {
        if(x&1) ans = (ans*bs) % mod;
        bs = (bs*bs) % mod;
        x >>= 1;
    }
    return ans;
}

int main() {
    int t;
    scanf("%d", &t);
    int a, b, h;
    while(t--) {    
        scanf("%d%d%d",&a,&b,&h);
        if(a >= b) {
            printf("%lld\n", (ksm1(b, h+1)+((a-b)*(ksm1(b,h+1)-1)*ksm1(b-1, mod-2))%mod)%mod);
        } else {
            stu x, y;
            x.x = 1;
            x.y = 3;
            y.x = 3;
            y.y = 3;
            x.p[1][1] = ksm1(a, h+1);
            x.p[1][3] = b-a;
            ll mp[5][5] = {
                {0,0,0,0,0},
                {0,b-a,1,0,0},
                {0,0,0,0,0},
                {0,1,0,1,0},
                {0,0,0,0,0}
            };
            memcpy(y.p, mp, sizeof mp);
            stu ans = x*ksm(y, h);
            printf("%lld\n", ans.p[1][1]);
        }
    }
}