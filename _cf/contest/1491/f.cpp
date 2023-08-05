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

int tmp;
int t, n;
int q[10010], cnt;

bool query(cint l, cint r, cint pt) {
    cout << "?" << ' ' << 1 << ' ' << r-l+1 << endl;
    cout << pt << endl;
    for(int i=l; i<=r; i++) cout << i << ' ';
    cout << endl;
    cout.flush();
    cin >> tmp;
    return !tmp;
}


int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        int loc, tmp;
        cnt = 0;
        for(int i=1; i<n; i++) {
            if(!query(1,i, i+1)) {
                loc = i+1;
                break;
            }
        }
        for(int i=loc+1; i<=n; i++) {
            if(query(loc, loc, i)) q[++cnt] = i;
        }
        int l=1, r=loc-1, mid;
        while(l<r) {
            mid = (l+r) >> 1;
            if(query(l, mid, loc)) l = mid+1;
            else r = mid;
        }
        for(int i=1; i<=loc-1; i++)
            if(i != l) q[++cnt] = i;
        cout << "! " << cnt << ' ';
        for(int i=1; i<=cnt; i++) cout << q[i] << ' ';
        cout << endl;
    }

    return 0;
}
/*
1
4
--11
*/