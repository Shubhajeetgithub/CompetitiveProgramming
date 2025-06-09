#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    //n >= 3
    a[0] = 1;
    a[n-1] = 2;
    for (int i = 1; i < n-1; i++) a[i] = i+2;

    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
    
    
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