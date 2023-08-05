#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

int mx[1001000];
int mn[1001000];

using namespace std;
int main() {
    int n;
    int a,b;
    cin >> n;
    memset(mn, 0x3f, sizeof mn);
    memset(mx, -0x3f, sizeof mx);
    for(int i = 1; i <= n; i++) {
        cin >> a >> b;
        if(mx[b] > a) {
            cout << "NO" << endl;
            return 0;
        }
        mx[b] = a;
        mn[b] = a;
    }
    cout << "YES" << endl;

    return 0;
}