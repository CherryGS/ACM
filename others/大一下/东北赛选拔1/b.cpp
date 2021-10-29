#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int t;
ll r, a, b;

bool check(ll x) {
    return 2*x*(x+1) <= a;
}

int main() {
    cin >> t;
    while(t--) {
        ll sx = 0, sy = 0; 
        ll x, y;
        cin >> r;
        if(r == 1) {
            cin >> a;
            ll l = 1, r = sqrt(a)+1, mid;
            while(l <= r) {
                mid = (l+r) >> 1;
                if(check(mid)) l = mid+1;
                else r = mid-1;
            }
            if(!check(l)) --l;
            ++l;

            if(2*l*l <= a) {
                int r = a-2*l*l;
                x = l; y = 0;
                while(r && x) {
                    --r;
                    --x;
                    --y;
                }
                while(r) {
                    --r;
                    --x;
                    ++y;
                }
            } else {
                int r = a-2*(l-1)*l-1;
                x = 0; y = l;
                while(r) {
                    --r;
                    --y;
                    if(x<=0) x = -x+1;
                    else x = -x;
                }
            }
            cout << x-sx << ' ' << y-sy << endl;
            sx = x; sy = y;
        } else {
            cin >> a >> b;
            a += sx; b += sy;
            ll l = abs(a) + abs(b);
            ll bs = 0;
            if(y <= 0) {
                bs = 2*l*l + l-a;
            } else {
                bs = 2*l*l-2*(l-1);
                bs += (l-b)*2;
                if(a > 0) -- bs;
            }
            cout << bs << endl;
        }
    }
    return 0;
}
/*
1
1 8
*/