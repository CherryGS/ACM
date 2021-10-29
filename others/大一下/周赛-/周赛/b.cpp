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
bool mp[1000001];

int main() {
    cin >> n;
    int a;
    mp[1] = 1;
    for(int i=2; i<=1000000; i++)
        for(int j=2; j*i <= 1000000; j++)
            if(!mp[i*j]) mp[i*j] = 1;
    while(n--) {
        cin >> a;
        if(mp[a]) cout << "Julytreetql" << endl;
        else cout << "CRBtql" << endl;
    }
    return 0;
}