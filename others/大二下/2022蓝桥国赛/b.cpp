#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

char st[17];
char a[18] = "aejcldbhpiogfqnkr";
char b[18] = "ncfjboqiealhkrpgd";

int main() {
    for(int i=0; i<17; i++) { st[i] = 'a' + i; }
    ll s1 = 0, s2 = 0;
    for(ll i=1;; i++) {
        // if(i % 1000) {
        //     for(int j=0; j<17; j++) {
        //         cout << st[i];
        //     }
        //     cout << endl;
        // }
        next_permutation(st, st+17);
        for(int j=0; j<17; j++) {
            if(st[j] != a[j]) { break; }
            if(j == 16) { s1 = i; }
        }
        for(int j=0; j<17; j++) {
            if(st[j] != b[j]) { break; }
            if(j == 16) { s2 = i; }
        }
        if(s2 && s1) { break; }
    }
    cout << s1 << '\n';
    cout << s2 << '\n';
    return 0;
}