#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;
typedef pair<int, int> pii;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n;
int ans[1001];

int query(cint id, cint x, bool st) {
    cout << "? ";
    for(int i=1; i<=n; i++) {
        if((i == id) ^ st) cout << x << ' ';
        else cout << 1 << ' ';
    }
    cout << endl;
    int tmp;
    cin >> tmp;
    return tmp;
}

int main() {
    cin >> n;
    int sum = 0;
    for(int i=n; i>1; i--) {
        int r = query(n, i, 0);
        if(r) ++sum;
    }
    int st = n - sum;
    ans[st] = n;
    for(int i=1; i<=n; i++) {
        if(i != st) {
            if(i < st) {
                ans[i] = query(n, st-i+1, 1);
            }
            else {
                ans[i] = query(n, i-st+1, 0);
            }
        }
    }
    cout << "! ";
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++)
            if(ans[j] == i) {
                cout << j << ' ';
                break;
            }
    }
    cout << endl;
    return 0;
}