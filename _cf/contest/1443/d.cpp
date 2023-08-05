#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

int t, n;
int a[30030];

int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i=1; i<=n; i++) cin >> a[i];
        int mn = a[1];
        bool flag = 0;
        for(int i=2; i<=n; i++)
            if(a[i] > a[i-1]) {
                flag = 1;
            } else if(a[i] < a[i-1]){
                if(!flag) mn = min(mn, a[i]);
                else {
                    mn -= a[i-1] - a[i];
                }
            }
        if(mn >= 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}