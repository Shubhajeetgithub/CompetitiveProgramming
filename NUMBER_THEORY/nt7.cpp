#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define READ_VEC(a, n) vector<ll> a(n); for (int i = 0; i < (n); i++) cin >> a[i];
#define PRINT_VEC(a, n) for (int i = 0; i < (n); i++) cout << a[i] << " "; cout << endl;
#define BUILD_TREE(n, adj) vector<vector<int>> adj(n+1); for(int i=2, p; i<=n; i++){ cin>>p; adj[p].push_back(i); }

vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
int sep(ll k) { // smallest excluded prime
    for (int p : primes) {
        if (k % p != 0) return p;
    }
    return -1;
}
ll modinv(ll a, ll mod) {
    ll b = mod, u = 1, v = 0;
    while (b != 0) {
        ll t = a / b;
        a -= t * b; std::swap(a, b);
        u -= t * v; std::swap(u, v);
    }
    if (a != 1) return -1;
    if (u < 0) u += mod;
    return u;
}
void solve() {
    int n; ll k;
    std::cin >> n >> k;
    std::vector<ll> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    // find smallest prime factor not in k
    // 2 * 3 * ... * 29 > 10^9
    int s = sep(k);
    // make all numbers divisible by s
    for (int i = 0; i < n; i++) {
        if (a[i] % s != 0) {
            int req = (s - (a[i] % s));
            // x * (k % s) cong req mod s
            // x cong req * modinv(k % s, s) mod s
            ll x = (req * modinv(k % s, s)) % s;
            a[i] += x * k;
        }
    }
    PRINT_VEC(a, n);
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