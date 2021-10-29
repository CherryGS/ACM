#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;
typedef pair<int, int> pii;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int t, n;
int a[1001];

bool check(cint x) {
    for(int i=2; i<=sqrt(x); i++)
        if(!(x%i)) return 1;
    return 0;
}

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        int ans = 0;
        for(int i=1; i<=n; i++) cin >> a[i];
        for(int i=1; i<=n; i++) a[i] += a[i-1];
        if(check(a[n])) {
            cout << n << endl;
            for(int i=1; i<=n; i++) cout << i << ' ';
            cout << endl;
        }
        else 
        for(int i=1; i<=n; i++) {
            if(check(a[n] - a[i] + a[i-1])) {
                cout << n-1 << endl;
                for(int j=1; j<=n; j++)
                    if(i != j) cout << j << ' ';
                cout << endl;
                break;
            }
        }
    }
    return 0;
}