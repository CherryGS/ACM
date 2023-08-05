#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

const int mod = 998244353;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

ll n, q;
int qu[2][200200], cnt[2];
int num[2][200200];

int main() {
    cin >> n >> q;
    ll ans = (n-2) * (n-2);
    int a, x;
    ll s[2] = {n, n};
    for(int i=1; i<=q; i++) {
        cin >> a >> x;
        a--;
        int key = upper_bound(qu[a]+1, qu[a]+cnt[a]+1, x, greater< int >()) - qu[a];
        if(key > cnt[a]) {
            ans -= (s[a^1]-2);
            s[a] = x;
            qu[a][++cnt[a]] = x;
            num[a][cnt[a]] = s[a^1] - 2;
        } else {
            ans -= num[a][key];
        }
    }
    cout << ans;
    return 0;
}