#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;
typedef pair<int, int> pii;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int t;
int q, n;
char s[1001000];
int sum[2][1001000];

int lowbit(cint x) { return x & -x; }
void add(int x, bool st) {
    while(x <= n) {
        sum[st][x]++;
        x += lowbit(x);
    }
}
int query(int x, bool st) {
    int ans = 0;
    while(x) {
        ans += sum[st][x];
        x -= lowbit(x);
    }
    return ans;
}

int main() {
    cin >> t;
    while(t--) {
        cin >> s;
        cin >> q;
        n = strlen(s);
        for(int i=0; i<n; i++) {
            if(s[i] == '(' || s[i] == ')') add(i+1, 0);
            else add(i+1, 1);
        }
        for(int i=1; i<=q; i++) {
            int l, r;
            cin >> l >> r;
            int s1 = query(r, 0) - query(l-1, 0);
            int s2 = query(r, 1) - query(l-1, 1);
            if(s1&1)
        }
    }
    return 0;
}