#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

const int mod = 998244353;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n;
int sum[(1<<16)+1];
int val[(1<<16)+1];
int ans[(1<<16)+1];
int mp[(1<<16)+1];

int query(cint key, cint x, cint y) {
    int tmp;
    if(key==1) cout << "AND " << x << ' ' << y << endl;
    else if(key==2) cout << "OR " << x << ' ' << y << endl;
    else if(key==3) cout << "XOR " << x << ' ' << y << endl;
    cout.flush();
    cin >> tmp;
    return tmp;
}

int main() {
    cin >> n;
    int a, id=0, lf=0;
    sum[0]=1;
    for(int i=2; i<=n; i++) {
        a = query(3, 1, i);
        ans[i] = a;
        if(!sum[a]) sum[a] = i;
        else {
            id=i;
        }
    }
    if(id) {
        int key = query(1, sum[ans[id]], id);
        ans[1] = ans[id] ^ key;
        for(int i=2; i<=n; i++)
            ans[i] ^= ans[1];
    } else {
        bool flag=0;
        int k1 = sum[1];
        int k2 = sum[2];
        int a1 = query(1, k1, 1);
        int a2 = query(1, k2, 1);
        int key = a1 + a2%2;
        for(int i=1; i<=n; i++) ans[i] ^= key;
    }
    cout << "! ";
    for(int i=1; i<=n; i++) cout << ans[i] << ' ';
    return 0;
}