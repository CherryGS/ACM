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

int n;
int query(cint l, cint r) {
    if(l == r) return l;
    cout << "? " << l << ' ' << r << endl;
    cout.flush();
    int tmp;
    cin >> tmp;
    return tmp; 
}
void ans(cint x) {
    cout << "! " << x << endl;
}

void sol() {
    int s = query(1, n);
    if(n == 2) { ans((s == 1 ? 2 : 1)); return ; }
    int l, r, mid;
    if(s != 1 && query(1, s) == s) { 
        l = 1, r = s-1;
        while(l+1 < r) {
            mid = (l+r) >> 1;
            if(query(mid+1, s) == s) l = mid+1;
            else r = mid;
        }
        if(l == r) ans(l);
        else { ans(query(r, s) == s ? r : l); }
    } else {
        l = s+1, r = n;
        while(l+1 < r) {
            mid = (l+r) >> 1;
            if(query(s, mid) == s) r = mid;
            else l = mid+1;
        }
        if(l == r) ans(l);
        else { ans(query(s, l) == s ? l : r); }
    }
}

int main() {
    cin >> n;
    sol();
    return 0;
}