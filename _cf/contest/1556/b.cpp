#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int t, n;
int a[100100];

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        int r;
        int s = 0;
        for(int i=1; i<=n; i++) cin >> a[i], s += a[i]&1 ? 1 : -1;
        if(abs(s) > 1) { cout << -1 << endl; continue;}
        queue<int> e;
        ll ans1 = 0;
        if(s >= 0) {
            for(int i=2; i<=n; i+=2)
                if(a[i]&1) e.push(i);
            for(int i=1; i<=n; i+=2)
                if(a[i]%2==0) {
                    if(e.empty()) {
                        break;
                    }
                    ans1 += abs(e.front() - i);
                    e.pop();
                }
        }
        ll ans2 = 0;
        if(s <= 0) {
        for(int i=1; i<=n; i+=2)
            if(i%2!=0 && a[i]&1) e.push(i);
        for(int i=2; i<=n; i+=2)
            if(a[i]%2==0) {
                if(e.empty()) {
                    break;
                }
                ans2 += abs(e.front() - i);
                e.pop();
            }
        }
        if(s == 0) cout << min(ans1, ans2) << endl;
        else cout << (s > 0 ? ans1 : ans2) << endl;
    }
    return 0;
}