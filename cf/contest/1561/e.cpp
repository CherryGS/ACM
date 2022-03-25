#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int t, n;
int a[2030];
vector<int> ans;

void reserve(cint x, cint st) {
    if(x == 1) return ;
    int loc;
    ans.push_back(x);
    for(int i=x; i>x/2; i--) {
        swap(a[i], a[x-i+1]);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        bool flag = 0;
        for(int i=1; i<=n; i++) {
            cin >> a[i];
            if((a[i]&1) != (i&1)) flag = 1;
        }
        ans.clear();
        if(!flag)
        for(int i=n; i>1; i-=2) {
            int s1, s2;
            for(int j=1; j<=i; j++) {
                if(a[j] == i) s1 = j;
                if(a[j] == i-1) s2 = j;
            }
            if(s1 != 1) {
                reserve(s1, i-1);
                for(int j=1; j<=i; j++)
                    if(a[j] == i-1) s2 = j;
            }
            if(s2 != 2) {
                reserve(s2-1, 1);
                reserve(s2+1, 1);
                reserve(3, 1);
            }
            reserve(i, 1);
        }
        if(flag) cout << -1 << endl;
        else {
            cout << ans.size() << endl;
            for(int v: ans) {
                cout << v << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}