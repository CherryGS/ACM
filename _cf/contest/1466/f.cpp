#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

const int mod = 998244353;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n, m;
bool mp[500500], bk[500500];
int q[500500], ct;
vector<int> v[500500];

ll ksm(ll bs, int x) {
    ll tmp=1;
    while(x) {
        if(x&1) tmp = (tmp*bs) % mod;
        bs = (bs*bs) % mod;
        x >>= 1;
    }
    return tmp;
}

void deal(cint x) {
    bk[x] = 0;
    for(auto k=v[x].begin(); k!=v[x].end(); k++) {
        if(v[*k].size() && bk[*k]) deal(*k);
    }
    v[x].clear();
}

int main() {
    cin >> n >> m;
    int num, tmp, l, r;
    for(int i=1; i<=n; i++) {
        cin >> num;
        if(num == 1) {
            cin >> tmp;
            if(!mp[tmp] || bk[tmp]) {
                mp[tmp] = 1;
                q[++ct] = i;
                deal(tmp);
            }
        } else {
            cin >> l >> r;
            if(!(mp[l] & mp[r])) {
                mp[l] = mp[r] = 1;
                q[++ct] = i;
                if(!((mp[l]&(!bk[l]))|(mp[r]&(!bk[r])))) {
                    // cout << i << " --- " << endl;
                    bk[l] = bk[r] = 1;
                    v[l].push_back(r);
                    v[r].push_back(l);
                }
            }
        }
    }
    cout << ksm(2, ct) << ' ' << ct << endl;
    for(int i=1; i<=ct; i++) cout << q[i] << ' ' ;
    cout << endl;

    return 0;
}
/*
6 6
2 1 2
2 2 3
2 3 4
2 4 5
2 5 6
2 6 1
*/