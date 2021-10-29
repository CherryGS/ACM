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

string s;

bool check() {
    int le = s.length();
    int sum = 0;
    for(int i=0; i<le; i++) sum += s[i]-'0';
    for(int i=0; i<le; i++)
        if(!((sum-s[i]+'0')%8)) return 1;
    return 0;
}

int main() {
    cin >> s;
    if(check()) cout << "Yes";
    else cout << "No";

    return 0;
}