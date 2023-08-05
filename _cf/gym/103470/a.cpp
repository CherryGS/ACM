#include <bits/stdc++.h>

using namespace std;

char s[2][2] = {{'U', 'D'}, {'L', 'R'}};
int n, a, b;

int main() {
    cin >> n >> a >> b;
    int dx, dy;
    string ans;
    for(int i=1; i<n; i++) ans += (a > n/2 ? 'D' : 'U');
    for(int i=1; i<n; i++) ans += (b > n/2 ? 'R' : 'L');
    if(a > n/2) dx = n;
    else dx = 1;
    if(b > n/2) dy = n;
    else dy = 1;
    // cout << ans << endl;
    for(int i=1; i<=abs(dx-a); i++) ans += (dx == n ? 'U' : 'D');
    for(int i=1; i<=abs(dy-b); i++) ans += (dy == n ? 'L' : 'R');
    cout << ans << endl;

}