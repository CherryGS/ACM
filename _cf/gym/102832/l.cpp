#include <bits/stdc++.h>
using namespace std;

#ifdef _DEBUG
#define pr1(x) cout << x << ' ';
#define pr2(x) cout << x << endl;
#else
#define pr1(x)
#define pr2(x)
#endif
typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;
typedef pair<int, int> pii;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

ll n, k, s;
ll ans[100100];

bool check(ll now, ll y) {
    for(int i=1; i<=n; i++) {
        ans[i] = now;
        if(now >= k && y >= (n-i)) {
            now -= k;
            y -= (n-i);
        }
        else ++now;
    }
    return y == 0 ? 1 : 0;
}

int main() {
    cin >> n >> k >> s;
    s -= n*(n-1)/2;
    ll r1 = s >= 0 ? 0 : (abs(s)/(k+1));
    bool flag = 0;
    ll y, now;
    for(ll i=0; i<=n; i++) {
        ll pre = (r1+i)*(k+1)+s;
        if(pre >= 0 && !(pre%n)) {
            y = r1+i;
            now = pre/n;
            if(check(now, y)) {
                flag = 1;
                break;
            }
        }
    }
    if(!flag) cout << -1 << endl;
    else {
        // cout << now << ' ' << y << ' ' << s << endl;
        // bool flag = 1;
        // if(!check(now, y)) {
        //     if(!check(now+(k+1), y+n)) flag = 0;
        // }
        // // cout << y << endl;
        // if(!flag) cout << -1 << endl;
        // else 
        for(int i=1; i<=n; i++)
            cout << ans[i] << ' ';
            cout << endl;
    }
    return 0;
}