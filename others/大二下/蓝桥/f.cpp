//玄学
#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

int n, x;
int h[100100];
int a[100100];

bool check(int step) {
    for(int i=1; i<n; i++) { a[i] = h[i]; }
    a[0] = -x*2;
    ll sum = 0;
    for(int i=0; i<n; i++) {
        if(a[i] != h[i]) {
            ll dt = h[i] - a[i];
            if(i + step >= n) { dt = 0; }
            else {
                for(int j=i+step; j>i; j--) {
                    if(a[j] > 0) {
                        if(a[j] >= dt) { a[j] -= dt; dt = 0; break; }
                        else { dt -= a[j]; a[j] = 0; }
                    }
                }
            }
            if(dt) { return false; }
        }
    }
    return true;
}

int main() {
    // freopen("1.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> n >> x;
    for(int i=1; i<n; i++) { cin >> h[i]; }
    int l = 1, r = n, mid;
    while(l < r) {
        mid = l + ((r-l) >> 1);
        if(check(mid)) { r = mid; }
        else { l = mid + 1; }
    }
    cout << r;
}