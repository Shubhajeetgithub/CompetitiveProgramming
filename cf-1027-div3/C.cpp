#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<long long> d(n-1);
    for (int i = 0; i < n-1; i++) {
        d[i] = a[i+1] - a[i];
    }
    long long ans = 1;
    long long prev = 0;
    for (int i = 0; i < n-1; i++) {
        if (d[i] + prev > 1) {
            ans++;
            prev = 0;
        } else prev += d[i];
    }
    cout << ans << endl;
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