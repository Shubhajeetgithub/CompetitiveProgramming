#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    bool f[102] = {false};
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        f[a[i]] = true;
    }
    for (int i = 0; i <= 101; i++) {
        if (!f[i]) {
            cout << i << endl;
            return;
        }
    }
    cout << -1 << endl;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tt;
    cin >> tt;
    cin.ignore();
    while (tt--) {
        solve();
    }
    return 0;
}