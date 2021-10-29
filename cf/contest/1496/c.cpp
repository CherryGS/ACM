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
ll q1[100100], ct1;
ll q2[100100], ct2;

int main() {
    int x, y;
    cin >> t;
    while(t--) {
        ct1 = ct2 = 0;
        cin >> n;
        for(int i=1; i<=2*n; i++) {
            cin >> x >> y;
            if(x == 0) q2[++ct2] = abs(y);
            else q1[++ct1] = abs(x);
        }
        sort(q1+1, q1+ct1+1);
        sort(q2+1, q2+ct2+1);
        double ans1 = 0.0;
        for(int i=1; i<=ct1; i++) {
            ans1 += sqrt(pow(q1[i],2)+pow(q2[i],2));
        }
        printf("%.10f\n", ans1);
    }
    return 0;
}