// n^2
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

char s[100010];
int m;

int main() {
    // freopen("1.in", "r", stdin);
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> s >> m;
    for(int i=1; i<=m; i++) {
        int l, r;
        char x, y;
        cin >> l >> r >> x >> y;
        for(int j=l-1; j<r; j++) {
            if(s[j] == x) { s[j] = y; }
        }
    }
    int l = strlen(s);
    for(int i=0; i<l; i++) { cout << s[i]; }
    cout << '\n';
    return 0;
}