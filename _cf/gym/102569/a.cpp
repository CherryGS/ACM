#include <iostream>
#include <cstdio>
#include <algorithm>

#define ll long long

ll arr[500010];

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    ll m = arr[1];
    for(int i = 2; i <= n; i++) m = arr[i] - m;
    int q, l, r;
    ll tmp;
    cin >> q;
    while(q--) {
        cin >> l >> r >> tmp;
        if(l < 1) l = 1;
        if(r > n) r = n;
        if(!((r-l) % 2)) {
            if(!((n%2) ^ (l%2))) m += tmp;
            else m -= tmp;
        }
        cout << m << endl;
    }
    return 0;
}