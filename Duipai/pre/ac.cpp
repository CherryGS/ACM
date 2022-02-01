#include <bits/stdc++.h>
#define DEBUG freopen("_in.txt", "r", stdin);
// #define DEBUG freopen("_in.txt", "r", stdin), freopen("_out.txt", "w", stdout);
typedef long long ll;
using namespace std;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll maxn = 2e5 + 10;
const ll maxm = 2e7 + 10;
const ll mod = 1e9 + 7;
const double pi = acos(-1);
const double eps = 1e-8;

ll T, n;
ll c1[maxn], vis[maxn],c2[maxn];

ll lowbit(ll i)
{
    return i & (-i);
}

void update1(ll x)
{
    for (ll i = x; i <= n; i += lowbit(i))
    {
        c1[i]++;
    }
}

ll query1(ll x)
{
    ll ans = 0;
    for (ll i = x; i; i -= lowbit(i))
    {
        ans += c1[i];
    }
    return ans;
}

void update2(ll x)
{
    for (ll i = x; i <= n; i += lowbit(i))
    {
        c2[i]++;
    }
}

ll query2(ll x)
{
    ll ans = 0;
    for (ll i = x; i; i -= lowbit(i))
    {
        ans += c2[i];
    }
    return ans;
}

int main()
{
    // DEBUG;
    scanf("%lld", &T);
    while (T--)
    {
        scanf("%lld", &n);
        for (ll i = 1; i <= n; i++)
        {
            c1[i] = 0;
            c2[i] = 0;
            vis[i]=0;
        }
        ll v;
        scanf("%lld", &v);
        ll maxx = v, cnt1 = 1, cnt2 = 0, ans = 0, cnt3 = 0;
        update1(v);
        vis[v] = 1;
        printf("%lld", ans);
        for (ll i = 2; i <= n; i++)
        {
            ll v;
            scanf("%lld", &v);
            if (v < maxx)
            {
                ans += i - query1(v)-1-(cnt3 - query2(v));
                printf(" %lld", ans);
                if (cnt1 >= 2)
                {
                    cnt2++;
                }
            }
            else if (v == maxx)
            {
                printf(" %lld", ans);
                cnt1++;
                if (cnt1 >= 2)
                {
                    cnt2++;
                }
            }
            else
            {
                ans += 2;
                ans += cnt2;
                printf(" %lld", ans);
                cnt1 = 1;
                cnt2 = 0;
                maxx = v;
            }
            if(vis[v])
            {
                cnt3++;
                update2(v);
            }
            update1(v);
            vis[v] = 1;
        }
        printf("\n");
    }
    return 0;
}