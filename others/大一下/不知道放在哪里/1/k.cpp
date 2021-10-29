#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n, m;
char a[1001], b[1001];
int ans[1002];

int main() {
    cin >> n >> m;
    cin >> a;
    cin >> b;
    for(int i=1; i<=n; i++) ans[m-n+i] = a[i-1]-'a';
    for(int i=m; i>n; i--) ans[i-n] = (int(b[i-1]-'a')-ans[i] +26+26) % 26;
    for(int i=1; i<=m; i++)
        putchar('a'+ans[i]);
    return 0;
}