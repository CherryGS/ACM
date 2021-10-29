#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef const int& cint;
typedef pair<int, int> pii;

const int mod = 1e9+7;
const int inf_int = 0x7fffffff;
const int hf_int = 0x3f3f3f3f;
const ll inf_ll = 0x7fffffffffffffff;
const double ept = 1e-9;

int n, k;
int a[200200];
bool vis[200200];
vector<int> e;

int main() {
    cin >> n >> k;
    for(int i=1; i<=k; i++) {
        cin >> a[i];
        vis[a[i]] = 1;
    }
    for(int i=1; i<=n; i++)
        if(!vis[i]) e.push_back(i);
    int num = 0;
    int r = 0;
    for(int i=1; i<k; i++) {
        num=1;  
        cout << a[i] << ' ';
        while(r < e.size() && num && e[r] < a[i]) {
            cout << e[r] << ' ';
            ++r;
            --num;
        }
        if(i == k-1) {
            for(int j=e.size()-1; j>=r; j--)
                if(e[j] > a[k]) cout << e[j] << ' '; 
        }
    }
    if(k == 1) {
        for(int i=n; i>=1; i--) cout << i << ' ';
        cout << endl;
    }
    else {
        cout << a[k] << ' ';
        for(int j=e.size()-1; j>=r; j--)
            if(e[j] < a[k])
            cout << e[j] << ' ';
        cout << endl;
    }

    return 0;
}