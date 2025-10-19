#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define READ_VEC(a, n) vector<ll> a(n); for (int i = 0; i < (n); i++) cin >> a[i];

void solve() {
    int n; cin >> n;
    string s;
    cin >> s;
    vector<int> p;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') p.push_back(i+1);
    }
    cout << p.size() << endl;
    for (const int& x : p) cout << x << " ";
    cout << endl;
    
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