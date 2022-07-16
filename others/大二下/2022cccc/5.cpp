#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int n;
int a[6];
bool flag[6][7];

int main() {
    for(int i=0; i<6; i++) { cin >> a[i]; flag[i][a[i]] = 1;}
    cin >> n;
    for(int i=0; i<6; i++) {
        if(n-1 >= 6-a[i]) { cout << 6-n; }
        else { cout << 6-n+1; }
        if(i != 5) { cout << ' '; }
    }
    cout << endl;
}
/*
1 1 1 1 1 6
1
*/