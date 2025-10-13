#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
    ll n;
    cin >> n;
    int ones = __builtin_popcountll(n);
    if (ones % 2 != 0) {
        // odd
        cout << "NO\n";
        return;
    }
    int first = __builtin_ctzll(n);
    int last = 63 - __builtin_clzll(n); 
    while (first < last) {
        int bitL = (n >> first) & 1;
        int bitR = (n >> last) & 1;
        if (bitL != bitR) {
            cout << "NO\n";
            return;
        }
        first++;
        last--;
    }
    cout << "YES\n";
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