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

ll x1, y1_;
ll x2, y2;
ll dx, dy;
ll r, c;
ll n;
char s[100100];

bool check(ll x) {
    return abs(dx-x*r)+abs(dy-x*c) <= n*x;
}

int main() {
    cin >> x1 >> y1_;
    cin >> x2 >> y2;
    cin >> n;
    for(int i=0; i<n; i++) cin >> s[i];
    bool flag = 0;
    dx = x2-x1; dy = y2-y1_;
    if(dx == 0 && dy == 0) {
        cout << 0 << endl;
        flag = 1;
    } else if(n == 0) {
        flag = 1;
        cout << abs(dx) + abs(dy) << endl;
    }
    if(!flag)
    for(int i=0; i<n; i++) {
        if(s[i] == 'L') -- r;
        else if(s[i] == 'R') ++ r;
        else if(s[i] == 'U') ++ c;
        else -- c;
        if(abs(dx-r)+abs(dy-c) <= i+1) {
            flag = 1;
            cout << i+1 << endl;
            break;
        }
    }
    if(!flag) {
        ll r_ = 1e18/n;
        // cout << r << ' ' << c << endl;
        // cout << dx << ' ' << dy << endl;
        // cout << r_ << endl;
        // cout << abs(dx-r_*r) << ' ' << abs(dy-r_*c) << ' ' << n*r_ << endl;
        ll l_=0, mid;
        r_ += 10;
        while(l_ <= r_) {
            mid = (l_+r_) >> 1;
            if(check(mid)) r_ = mid - 1;
            else l_ = mid + 1;
        }
        if(!check(mid)) ++ mid;
        while(check(mid)) -- mid;
        ll rr=0, cc=0;
        for(int i=0; i<n; i++) {
            if(s[i] == 'L') -- rr;
            else if(s[i] == 'R') ++ rr;
            else if(s[i] == 'U') ++ cc;
            else -- cc;
            // cout << i << ' ' << mid <<endl;
            if(abs(dx-r*mid-rr)+abs(dy-c*mid-cc) <= i+1+n*mid) {
                flag = 1;
                cout << i+1+n*mid << endl;
                break;
            }
        }
        if(!flag) cout << -1 << endl;
    }
    return 0;
}