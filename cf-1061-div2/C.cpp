#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define READ_VEC(a, n) vector<ll> a(n); for (int i = 0; i < (n); i++) cin >> a[i];
#define PRINT_VEC(a, n) for (int i = 0; i < (n); i++) cout << a[i] << " "; cout << endl;
#define BUILD_TREE(n, adj) vector<vector<int>> adj(n+1); for(int i=2, p; i<=n; i++){ cin>>p; adj[p].push_back(i); }

void solve() {
    int n, k; cin >> n >> k;
    READ_VEC(a, n);
    sort(a.begin(), a.end());
    int maxA = a.back();
    vector<int> freq(maxA + 1, 0);
    for (int x : a) freq[x]++;
    vector<int> pref(maxA + 1, 0);
    for (int i = 1; i <= maxA; i++) {
        pref[i] = pref[i - 1] + freq[i];
    }
    for (int g = n; g >= 1; g--) {
        int limitVal = 4 * g;
        if (limitVal > maxA) limitVal = maxA;
        int limCount = pref[limitVal];
        int multiples = 0;
        for (int x = g; x <= limitVal; x += g) {
            multiples += freq[x];
        }
        int bad = limCount - multiples;
        if (bad <= k) {
            cout << g << "\n";
            return;
        }
    }
    cout << 1 << "\n";
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