#include <bits/stdc++.h>
using namespace std;

std::mt19937 rng(std::random_device{}());
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;
typedef pair<int, int> pii;
typedef const ll& cll;

#define ls (loc<<1)
#define rs ((loc<<1)|1)

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int t, n, q;
int a[2002];
int mp[4002][2002];
int num[2002];

// struct node {
//     int x, k;
//     bool operator < (const node&a) const {
//         return k < a.k;
//     }
//     void init() {
//         cin >> x >> k;
//     }
// }s[100100];

void sol() {
    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) mp[i][j] = 0;
    memset(num, 0, sizeof num);
    for(int i=1; i<=n; i++) num[a[i]]++;
    for(int i=1; i<=n; i++) {
        
    }
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i=1; i<=n; i++) cin >> a[i];
        sol();
        cin >> q;
        for(int i=1; i<=q; i++) {
            int x, k;
            cin >> x >> k;
            int r = a[x];
            int kk = min(n, k);
            for(int j=1; j<=kk; j++) r = mp[j][r];
            cout << r << '\n';
        }
    }
    return 0;
}
/*
1

*/