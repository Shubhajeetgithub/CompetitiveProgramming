#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    long long diff = a[1] - a[0]; // as n >= 2
    for (int i = 1; i < n-1; i++) {
        if (a[i+1] - a[i] != diff) {
            cout << "NO" << endl;
            return;
        }
    }
    // DIFF = x-y, a[0] = x + ny
    //so y = (a[0] - diff)/(n+1)
    if (a[0] < diff) {
        cout << "NO" << endl;
        return;
    }
    if (((a[0] - diff) % (n + 1)) != 0) {
        cout << "NO" << endl;
        return;
    }
    
    long long y = (a[0] - diff) / (n + 1);
    if (diff + y < 0) { // as x = y + diff
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    return;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    cin.ignore();
    while (tt--) {
        solve();
        fflush(stdout);
    }
    return 0;
}