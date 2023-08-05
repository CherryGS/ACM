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
ll W, H;
ll w, h;
ll x1, x2, y1, y2;

int main() {
    cin >> t;
    while(t--) {
        cin >> W >> H;
        cin >> x1 >> x2 >> y1 >> y2;
        cin >> w >> h;
        if(w+(x2-x1) > W || h+(y2-y1) > H) cout << -1 << endl;
        else {
            ll dx, dy;
            
        }
    }
    return 0;
}