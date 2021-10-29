#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int t;
int n;
int a[1010];

bool check(cint x) {

    for(int i=1; i<=n; i++)
        if(a[i] != i) return 0;
    return 1;
}

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i=1; i<=n; i++) cin >> a[i];
        for(int i=1; i<=n+1; i++) {
            if(check(i)) {
                cout << i-1 << endl;
                break;
            }
            if(i == n+1) break;
            int r = !(i&1)+1;
            for(int j=r; j<=n-1; j+=2) {
                if(a[j] > a[j+1]) swap(a[j], a[j+1]);
            }
        }
    }
    return 0;
}