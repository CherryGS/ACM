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

int t, n, m;
ll a[303*303];
ll id[303*303];

bool cmp(cint x, cint y) {
    return a[x] == a[y] ? x < y : a[x] < a[y];
}

bool cmp1(cint x, cint y) {
    return a[x] == a[y] ? x > y : a[x] < a[y];
}

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> m;
        for(int i=1; i<=n*m; i++) cin >> a[i];
        for(int i=1; i<=n*m; i++) id[i] = i;
        sort(id+1, id+1+n*m, cmp);
        ll ans = 0;
        

        for(int lim = m; lim <= n*m; lim += m) {
            sort(id+lim-m+1, id+lim+1, cmp1);
        }
        // for(int i=1; i<=n*m; i++)
        //     cout << id[i] << ' ';
        //     cout << endl;

        for(int lim=m; lim<=n*m; lim+=m) {
            for(int i=lim-m+1; i<=lim; i++) {
                for(int j=i+1; j<=lim; j++) {
                    if(id[i] < id[j]) ++ans;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}