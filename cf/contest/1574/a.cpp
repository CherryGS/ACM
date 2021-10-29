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

int t;
int n;

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        string ans;
        for(int i=1; i<=n; i++) ans += '(';
        for(int i=1; i<=n; i++) ans += ')';
        int r = n-1;
        for(int i=1; i<=n; i++) {
            cout << ans << endl;
            swap(ans[r], ans[r+1]);
            --r;
        }
    }
    return 0;
}