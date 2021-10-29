#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
int a[100100];
int b[100100];
int t;

int main (){
    cin >> n;
    cin >> t;
    for(int i=1; i<=n; i++) cin >> a[i] >> b[i];
    int r1 = 0, r2 = 0;
    ll s1 = 0, t1 = 0;
    ll s2 = 0, t2 = 0;
    for(int i=1; i<=n; i++) {
        if(a[i] < 0) t1 += a[i] * b[i];
        else s1 += a[i] * b[i];
    }
    if(s1) r1 = 1;
    else {
        r1 = 2;
        for(int i=1; i<=n; i++) {
            if(a[i] > 0) {
                s2 -= b[i] * b[i] * a[i];
            }
            if(a[i] > 0 && b[i] != 0) break;
            if(i == n) {
                r1 = 3;
            }
        }
    }
    if(t1) r2 = 1;
    else {
        r2 = 2;
        for(int i=1; i<=n; i++) {
            if(a[i] < 0) {
                t2 -= b[i] * b[i] * a[i];
            }
            if(a[i] < 0 && b[i] != 0) break;
            if(i == n) {
                r2 = 3;
            }
        }
    }
    // cout << r1 << ' ' << r2 << ' ' << t << endl;
    if(r1 == 3) cout << 0 << endl;
    else {
        if(r1 == 2) s1 = s2;
        if(r2 == 2) t1 = t2;
        if(r1 > r2) { r1 = r2; s1 = - t1; }
        if(r1 == r2) { s1 = s1 - t1;}
        if(t < r1) cout << 0 << endl;
        else if(t == r1) cout << s1 << endl;
        else cout << "infinity" << endl;
    }

    return 0;
}