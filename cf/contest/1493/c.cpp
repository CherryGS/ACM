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
int n, k;
string s;
int num[26];

void solve(cint x, cint y) {
    // cout << x << "---" << y << endl;
    s[x] = 'a'+y;
    int d = 25;
    // cout << "-----" << endl;
    // for(int i=0; i<26; i++) {
    //     cout << num[i] << "--" << char('a'+i) << endl;
    // }
    for(int i=s.length()-1; i>x; i--) {
        while(d >=0 && !num[d]) --d;
        if(d < 0) s[i] = 'a';
        else {s[i] = 'a'+d; ++num[d]; if(num[d] == k) num[d] = 0;}
    }
    cout << s;
    cout << endl;
}

int main() {
    int r;
    cin >> t;
    while(t--) {
        cin >> n >> k >> s;
        if(n%k) {cout << -1 << endl; continue;}
        for(int i=0; i<26; i++) num[i] = 0;
        for(int i=0; i<s.length(); i++) {
            r = s[i] - 'a';
            num[r] = (num[r]+1) % k;
        }
        int sum = 0;
        // for(int i=0; i<26; i++) {
        //     cout << num[i] << "--" << char('a'+i) << endl;
        // }
        for(int i=0; i<26; i++) sum += (k-num[i]) % k;
        if(!sum) cout << s << endl;
        else {
            bool flag = 0;
            int tmp;
            for(int i = s.length()-1; i>=0 && !flag; i--) {
                r = s[i] - 'a';
                if(num[r] == 1) {
                    sum -= k-1;
                    num[r] = 0;
                } else {
                    sum += 1;
                    num[r] = (num[r]+k-1)%k;
                }
                for(int j=r+1; j<26; j++) {
                    tmp = 0;
                    if(!num[j]) tmp += k-1;
                    else tmp -= 1;
                    if(sum + tmp < s.length()-i) {
                        num[j] = (num[j]+1)%k;
                        flag = 1;
                        solve(i, j);
                        break;
                    }
                }
            }
        }
    }
    return 0;
}
/*
1
16 8
cadjfdsljfdkljds
*/