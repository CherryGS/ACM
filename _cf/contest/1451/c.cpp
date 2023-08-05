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

int t, n, k;
string a, b;
int sum[27][2];

int main() {
    cin >> t;
    while(t--) {
        memset(sum, 0, sizeof sum);
        cin >> n >> k >> a >> b;
        for(int i=0; i<n; i++)
            ++sum[a[i]-'a'+1][0], ++sum[b[i]-'a'+1][1];
        int s=0;
        bool flag=0;
        for(int i=26; i && !flag; i--) {
            if(abs(sum[i][1]-sum[i][0])%k) flag=1;
            else s += sum[i][1]-sum[i][0];
            if(s<0) flag=1;
        }
        if(!flag) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}