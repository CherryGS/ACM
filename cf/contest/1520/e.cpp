#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
#define ull unsigned long long
#define cint const int&
#define Pi acos(-1)

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int t;
int n;
string s;
ll pre_ans[1001000][2];

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> s;
        if(n == 1) {
            cout << 0 << endl;
            continue;
        }
        ll sum_dis, num;
        sum_dis = num = 0;
        for(int i=0; i<n; i++) {
            if(s[i] == '*') ++ num;
            else sum_dis += num;
            pre_ans[i][0] = sum_dis;
        }
        sum_dis = num = 0;
        for(int i=n-1; i>=0; i--) {
            if(s[i] == '*') ++ num;
            else sum_dis += num;
            pre_ans[i][1] = sum_dis;
        }
        ll ans = inf_ll;
        for(int i=0; i<n-1; i++)
            ans = min(ans, pre_ans[i][0] + pre_ans[i+1][1]);
        cout << ans << endl;
    }
    return 0;
}
/*
1
6
*....*
*/