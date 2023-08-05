#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&

int t, n;
int mx;
int arr[101];

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        mx = 0;
        for(int i = 1; i <= n; i++) {
            cin >> arr[i];
            if(i != 1) mx = max(mx, arr[i]);
        }
        int ans = max(arr[1] * 3, mx+1);
        if(ans%2) ans++;
        cout << ans << endl;
    }
    return 0;
}