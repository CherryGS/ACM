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

int t;
string a;

int main() {
    cin >> t;
    while(t--) {
        cin >> a;
        int n = a.length();
        if(a.length()&1) {
            cout << "No" << endl;
            continue;
        }
        bool flag=1;
        int s1=0, s2=0, s3=0, s4=0, s5=0, s6=0;
        for(int i=0; i<n && flag; i++) {
            if(a[i] == '(') ++s1;
            else if(a[i] == ')') ++s2;
            else ++s3;
            if(s1+s3<s2) {flag=0; break;}
            if(a[n-i-1] == '(') ++s4;
            else if(a[n-i-1] == ')') ++s5;
            else ++s6;
            if(s5+s6<s4) {flag=0; break;}
        }
        if(abs(s1-s2) <= s3 && flag) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
/*
1
((??)(
*/