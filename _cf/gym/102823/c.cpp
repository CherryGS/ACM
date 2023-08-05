#include <bits/stdc++.h>
using namespace std;

std::mt19937 rng(std::random_device{}());
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;
typedef const ll& cll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;

#define ls (loc<<1)
#define rs ((loc<<1)|1)

const int mod1 = 1e9+7;
const int mod2 = 998244353;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int t;
ll n, m;
ll s[100100];

bool check1() {
    // INVALID
    if(m > n) return 1;

    // 第n行不多于2^(n-1)个
    int st = 0;
    for(int i=1; i<=m; i++) {
        if(s[i] != s[i+1] || i == m) {
            if(i-st > (1ll<<(s[i]-1))) return 1;
            st = i;
        }
    }

    // 向上扩展总数不大于n
    st = 0;
    ll sum = 0;
    for(int i=1; i<=m; i++) {
        if(s[i] != s[i-1] || i == m) {
            ll b = s[i] - s[st];
            ll r = i - st;
            for(int j=1; j<=min(b, 32ll); j++) {
                sum += r;
                r = (r+1) / 2;
            }
            if(b > 32) { sum += b-32; }
            st = i;
        }
    }
    if(sum > n) return 1;

    return 0;
}

bool check2() {
    // DEFINITELY

    if(s[m] > 32) return 0;

    if((1ll<<s[m])-1 != n) return 0;

    return 1;
}

bool check3() {
    // POSSIBLE
    if(s[m] > 32) return 0;

    for(int i=0; i<=32; i++)
        if(n == (1ll<<i)) break;
        else if(n < (1ll << i)) return 0;
    if((1ll<<s[m])-1 > n) return 0;
    return 1;
}

bool check4() {
    // IMPOSSIBLE

    return 1;
}

int main() {
    freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> t;
    int TT = t;
    while(t--) {
        cin >> n >> m;
        for(int i=1; i<=m; i++) cin >> s[i];
        sort(s+1, s+1+m);
        cout << "Case " << TT-t << " :";
        if(check1()) cout << "INVALID" << endl;
        else if(check2()) cout << "DEFINITELY" << endl;
        else if(check3()) cout << "POSSIBLE" << endl;
        else cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}