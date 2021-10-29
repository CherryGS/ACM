#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

int t, n;
struct stu {
    int b, id;
    bool operator < (const stu& a) const {
        if(b == a.b) return id < a.id;
        return b < a.b;
    }
} a[1001];

inline int check(cint l, cint r, cint st, cint sw, cint ii) {
    int mid, le = l, ri = r;
    while(l <= r) {
        mid = (le+ri) >> 1;
        if(a[mid].d >= st) ri = mid - 1;
        else l = mid + 1;
    }
    if(a[ri].b >= st || ri == r) return 0;
    int k1 = ri;
    le = l, ri = r;
    while(l <= r) {
        mid = (le+ri) >> 1;
        if(a[mid].d > st) ri = mid - 1;
        else l = mid + 1;
    }
    if(a[ri].b != st) return 0;
    int k2 = ri;
    while(k1 <= k2) {
        mid = (k1+k2) >> 1;
        if((a[mid].id > ii) ^ (!sw)) k1 = mid + 1;
        else k2 = mid - 1;
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; i++) {cin >> a[i].b; a[i].id = i;}
        sort(a+1, a+1+n);
        int ans = 0;
        for(int i = 2; i < n; i++) {
            int key = (a[i].b << 1);
            if(i < (n>>1)) {
                int l = i-1;
                while(l) ans += check(i+1, n, key-a[l].b, a[l--].id < a[i].id, i);
            } else {
                int r = i+1;
                while(r <= n) ans += check(1, i-1, key-a[r].b, a[r++].id < a[i].id, i);
            }
        }
        cout << ans << endl;
    }
    return 0;
}