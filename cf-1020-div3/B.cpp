#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x; cin >> n >> x;
    vector<int> a(n);
    
    if (x == n) {
        for (int i = 0; i < n; i++) a[i] = i;
    }
    else {
        a[n-1] = x;
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (i != x) a[j++] = i;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
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