#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
int n;
int arr[200200];
int t;
int b;

int sq(int l, int r, int base) {
    int mid;
    cout<<"-=-=-=" << base << endl;
    while(l <= r) {
        mid = (l+r) >> 1;
        if(arr[mid] > base) r = mid - 1;
        else l = mid + 1; 
        cout<< l << " " << r << "--" << arr[mid] << endl;
    }
    if(arr[r] > base) --r;
    return r;
}

int sq2(int l, int r, int base) {
    int mid;
    cout<<"-=-=-=" << base << endl;
    while(l <= r) {
        mid = (l+r) >> 1;
        if(arr[mid] >= base) r = mid - 1;
        else l = mid + 1; 
        cout<< l << " " << r << "--" << arr[mid] << endl;
    }
    return r + 1;
}

int main() {
    int ans = 0;
    cin >> n >> t;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        if(arr[i] >= 0 && arr[i-1] <= 0) b = i;
    }
    for(int i = 1; i < b; i++) if(b < n) if(t+arr[i]*2 >= arr[b]){
        int k = sq(b, n, t+arr[i]*2);
        cout << "--" << ans  << "-" << k << "-----" << i << endl;
        ans = max(ans, k - i + 1);
    }
    cout << "------------------------------" << endl;
    for(int i = n; i >= b; i--) if(b > 1) if(t-arr[i]*2 >= abs(arr[b-1])){
        int k = sq2(1, b-1, t-arr[i]*2);
        cout << "__" << ans  << "-" << k << "-----" << i << endl;
        ans = max(ans, i - k + 1);
    }
    for(int i = 1; i <= n; i++)
        if(abs(arr[i]) <= t)
            if(arr[i] < 0) ans = max(ans, b-i);
            else ans = max(ans, i-b+1);
    cout << ans;
    return 0;
}