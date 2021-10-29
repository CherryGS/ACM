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
const int bs=100100;

int n;
int a[200200];
int num[101];
int cnt[200200];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    int tmp=0,id;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        ++num[a[i]];
        if(num[a[i]] > tmp) {
            id=a[i];
            tmp=num[a[i]];
        }
    }
    int ans=0;
    for(int i=1; i<=100; i++)
        if(num[i] && i != id) {
            int sum=bs;
            cnt[sum]=0;
            memset(cnt, -1, sizeof cnt);
            for(int j=1; j<=n; j++) {
                if(a[j]==id) ++sum;
                else if(a[j] == i) --sum;
                
                if(cnt[sum]>=0) ans = max(ans, j-cnt[sum]);
                else cnt[sum]=j;
            }
        }
    cout << ans << endl;
    return 0;
}
/*
20
4 16 13 4 5 7 9 6 3 12 2 4 5 2 5 9 9 4 14 11
*/