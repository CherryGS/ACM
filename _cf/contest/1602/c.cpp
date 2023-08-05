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

int t;
int n;
int a[200200];

int gcd(cint x, cint y) {
    return y == 0 ? x : gcd(y, x%y);
}

int main() {
    //freopen("1.in", "r", stdin);
    //cout.flags(ios::fixed); cout.precision(8);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i=1; i<=n; i++) cin >> a[i];
        int ans = 0;
        bool flag = 0;
        for(int i=1; i<=n; i++) if(a[i]) { flag = 1; break; }
        if(flag == 0) for(int i=1; i<=n; i++) cout << i << ' ';
        else {
            for(int i=0; i<30; i++) {
                int r = (1<<i);
                int sum = 0;
                for(int j=1; j<=n; j++) if(r&a[j]) ++sum;
                ans = gcd(sum, ans);
            }
            for(int i=1; i<=ans; i++)
                if(!(ans%i)) cout << i << ' ';
        }
        cout << '\n';
    }
    return 0;
}