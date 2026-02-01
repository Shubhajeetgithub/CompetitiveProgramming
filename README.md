# Templates
1) Interactive problems

```cpp
#define ASK(x, k) ([&](){ \
cout << "? " << (x) << " " << (k) << endl << flush; \
int _r; cin >> _r; \
return _r; \
}())

#define ANS(x) cout << "! " << (x) << endl << flush;
```

2) Tree problems (dfs + dp)
```cpp
#define BUILD_TREE(n, adj) vector<vector<int>> adj(n+1); for(int i=2, p; i<=n; i++){ cin>>p; adj[p].push_back(i); }

int dfs(const vector<vector<int>>& adj, int parent, vector<int>& WBcnts, string s) {
	if (WBcnts[parent] != -1) return WBcnts[parent];
	int sum = 0;
	if (s[parent - 1] == 'W') sum += 1;
	else sum -= 1;
	for (const int& child : adj[parent]) {
		sum += dfs(adj, child, WBcnts, s);
	}
	return WBcnts[parent] = sum;
}

void solve() {
	int n; cin >> n;
	BUILD_TREE(n, adj);
	string s;
	cin >> s;
	// root is vertex 1
	vector<int> WBcnts(n+1, -1);
	int __ = dfs(adj, 1, WBcnts, s);
	int cnt = 0;
	for (const int& c: WBcnts) {
		if (c == 0) cnt++;
	}
	cout << cnt << endl;
}
```
3) VECTOR IO
```cpp
using ll = long long;
#define READ_VEC(a, n) vector<ll> a(n); for (int i = 0; i < (n); i++) cin >> a[i];
#define PRINT_VEC(a, n) for (int i = 0; i < (n); i++) cout << a[i] << " "; cout << endl;
```
4) BIT
```cpp
int msb = 31 - __builtin_clz(n);  // position of highest set bit (0-based)
// For 64-bit: `63 - __builtin_clzll(n)
int lsb = __builtin_ctz(n);  // position of lowest set bit (0-based)
int ones = __builtin_popcount(n);      // number of 1s in n
// __builtin_popcountll(n);  // for long long
bool isPow2 = n && !(n & (n - 1));  // true if n is a power of 2
int rightmost = n & -n;  // isolates the lowest set bit
n = n & (n - 1);  // removes the lowest set bit
int modulo = n & ((1 << k) - 1);  // n % (2^k)
```
5) COMBINATORICS
```cpp
const int M = 998244353;
ll modPow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % M;
        a = (a * a) % M;
        b >>= 1;
    }
    return res;
}

ll inv(ll x) {
    return modPow(x, M - 2);    
}

ll divide(ll x, ll y) {
    return (x * inv(y)) % M;
}

ll nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    ll ans = 1;
    for (int i = r; i >= 1; i--) {
        ans = (ans * divide(n + i - r, i)) % M;
    }
    return ans;
}
```
6) MOD questions
```cpp
#include <iostream>
using ll = long long;
#define MOD 998244353
struct Mint {
    int value;
    static const int MOD_value = MOD;
    Mint(ll v = 0) {
        value = int(v % MOD);
        if (value < 0) value += MOD;
    }
    Mint(ll a, ll b) : value(0) {
        *this += a;
        *this /= b;
    }
    Mint& operator+=(Mint const& b) {
        value += b.value;
        if (value >= MOD) value -= MOD;
        return *this;
    }
    Mint& operator-=(Mint const& b) {
        value -= b.value;
        if (value < 0) value += MOD;
        return *this;
    }
    Mint& operator*=(Mint const& b) {
        value = int((ll)value * b.value % MOD);
        return *this;
    }
    Mint& operator/=(Mint const& b) { return *this *= inverse(b); }
    friend Mint mexp(Mint a, ll e) {
        Mint res = 1;
        while (e) {
            if (e & 1) res *= a;
            a *= a;
            e >>= 1;
        }
        return res;
    }
    friend Mint inverse(Mint a) { return mexp(a, MOD - 2); }
    friend Mint operator+(Mint a, Mint const& b) { return a += b; }
    friend Mint operator-(Mint a, Mint const& b) { return a -= b; }
    friend Mint operator*(Mint a, Mint const& b) { return a *= b; }
    friend Mint operator/(Mint a, Mint const& b) { return a /= b; }
    Mint& operator++() { return *this += 1; }        // pre-increment
    Mint operator++(int) { Mint tmp = *this; ++(*this); return tmp; } // post-increment
    Mint& operator--() { return *this -= 1; }        // pre-decrement
    Mint operator--(int) { Mint tmp = *this; --(*this); return tmp; } // post-decrement
    friend bool operator==(Mint const& a, Mint const& b) { return a.value == b.value; }
    friend bool operator!=(Mint const& a, Mint const& b) { return a.value != b.value; }
    friend std::ostream& operator<<(std::ostream& os, Mint const& a) { return os << a.value; }
};
```
# STL

### List
Helps performing delete operations fast (as it is implemented as **doubly linked list**) -> O(1) for deletion
```cpp
list<int> a;

// insert operations 
a.push_back(10);
a.push_front(5);
list<int>::iterator it = a.begin();
advance(it, 2);     // move iterator 2 steps forward
a.insert(it, 20);    // insert 20 before it

// erase operation
list<int>::iterator it2 = a.begin();
while (it2 != a.end()) {
	if (/*some checks*/) it2 = a.erase(it2);
	else ++it2;
}
```

# Number Theory
### Sieve
#### Finding primes in O(NloglogN)
```cpp
int N = 2e5 + 10;
bool isPrime[N] = {true};
isPrime[0] = false; isPrime[1] = false;
for (int i = 2; i * i < N; i++) 
	if (isPrime[i]) {
		for (int j = i * i; j < N; j += i) isPrime[j] = false;
	}
}
```
less optimised version ->
```cpp
for (int i = 2; i < N; i++) 
	if (isPrime[i]) {
		for (int j = 2 * i; j < N; j += i) isPrime[j] = false;
	}
}
```
#### Highest prime and lowest prime
```cpp
int lp[N] = {0}, hp[N];
for (int i = 2; i < N; i++) 
	if (isPrime[i]) {
		lp[i] = i; hp[i] = i;
		for (int j = 2 * i; j < N; j += i) {
			isPrime[j] = false;
			hp[j] = i;
			if (lp[j] == 0) lp[j] = i;
		}
	}
}
```
#### Prime factors
```cpp
std::vector<std::vector<int>> pf(N);
for (int i = 2; i < N; i++) {
    if (!pf[i].empty()) continue;
    for (int j = i; j < N; j += i) {
        pf[j].push_back(i);
    }
}
```
#### Show (p, cnt_p) where cnt_p is number of elements in array having p as prime factor
```cpp
std::map<int, int> hsh;
for (int i = 0; i < n; i++) {
    int x; std::cin >> x;
    hsh[x]++;
}
std::map<int, int> distinct_prime_cnt;
for (auto& [i, freq] : hsh) {
    if (i > 1 && freq > 0) {
        for (int x : pf[i]) {
            distinct_prime_cnt[x] += hsh[i];
        }
    }
}
```
#### Prime factorisation
```cpp
map<int, int> prime_factors;
while (num > 1) {
	int pf = hp[num];
	while (num % pf == 0) {
		num /= pf;
		prime_factors[pf]++;
	}
}
for (auto& [key, val] : prime_factors) cout << key << "^" << val << " ";
```
Alternate using segmented sieve (useful for N ~ 10^12)
```cpp
// Generate primes up to limit using sieve
std::vector<ll> sieve(ll limit) {
    std::vector<bool> isPrime(limit + 1, true);
    std::vector<ll> primes;
    isPrime[0] = isPrime[1] = false;
    for (ll i = 2; i <= limit; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (ll j = i * i; j <= limit; j += i)
                isPrime[j] = false;
        }
    }
    return primes;
}
  
// Prime factorization function
std::map<ll, int> primeFactorization(ll n) {
    std::map<ll, int> factors;
    ll limit = sqrt(n) + 1;
    std::vector<ll> primes = sieve(limit);
    for (ll p : primes) {
        if (p * p > n) break;
        while (n % p == 0) {
            factors[p]++;
            n /= p;
        }
    }
    if (n > 1) factors[n]++; // Remaining prime factor
    return factors;
}
```
#### Divisors
```cpp
vector<vector<int>> divisors(N);
for (int i = 2; i < N; i++) {
	for (int j = i; j < N; j += i) divisors[j].push_back(i);
}
```
Note that when we are only interested in number of divisors, instead of writing .size(), write this code
```cpp
std::vector<int> D(N);
for (int i = 1; i < N; i++) {
    for (int j = 2*i; j < N; j += i) D[j]++;
}
```
this is because `push_back` operation requires reallocation and copying, thus having large constant factor.
#### Multiples
```cpp
int hsh[N];
int multiple_cnt[N];
for (int i = 0; i < n; i++) {
	int x; cin >> x;
	hsh[x]++;
}
for (int i = 1; i < N; i++) {
	for (int j = i; j < N; j += i) multiple_cnt[i] += hsh[j];
}
```

#### Smallest excluded prime
```cpp
std::vector<int> small_primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
// use for k <= 10^18 as 2 * 3 * ... * 53 > 10^18
std::vector<int> small_primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
// use for k <= 10^9 as 2 * 3 * .. * 29 > 10^9
int sep(ll k) { // smallest excluded prime
    for (int p : small_primes) {
        if (k % p != 0) return p;
    }
    return -1;
}
```

#### Total count of primes (with repetitions)
```cpp
int cnt_primes[N];
cnt_primes[0] = cnt_primes[1] = 0;
for (int i = 2; i < N; i++) {
	if (isPrime[i]) cnt_primes[i] = 1;
	else cnt_primes[i] = 1 + cnt_primes[i / hp[i]];
}
```
#### Segmented sieve
Sometimes we need to find all prime numbers in a range  $[L,R]$  of small size (e.g.  $R - L + 1 \approx 1e7$ ), where  $R$  can be very large (e.g.  $1e12$ ).
To solve such a problem, we can use the idea of the Segmented sieve. We pre-generate all prime numbers up to  $\sqrt R$ , and use those primes to mark all composite numbers in the segment  $[L, R]$ .

```cpp
vector<bool> segmentedSieve(long long L, long long R) {     
	// generate all primes up to sqrt(R)     
	long long lim = sqrt(R);     
	vector<bool> mark(lim + 1, false);     
	vector<long long> primes;     
	for (long long i = 2; i <= lim; ++i) {         
		if (!mark[i]) {             
			primes.emplace_back(i);             
			for (long long j = i * i; j <= lim; j += i)                 
				mark[j] = true;         
		}     
	}      
	vector<bool> isPrime(R - L + 1, true);     
	for (long long i : primes)         
		for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
			isPrime[j - L] = false;     
	if (L == 1)         
		isPrime[0] = false;     
	return isPrime; 
}
```
# RANGE QUERIES

| Type of query   | DS (static)  | DS (dynamic) |
| --------------- | ------------ | ------------ |
| MIN / MAX       | Sparse Table | Segment Tree |
| SUM             | Prefix Sum   | Fenwick Tree |
| XOR (^)         | Prefix XOR   | Fenwick Tree |
| GCD             | Sparse Table | Segment Tree |
| AND(&) / OR(\|) | Sparse Table | Segment Tree |
```cpp
// ============ MIN/MAX Queries ============

// Sparse Table for static MIN/MAX (O(n log n) build, O(1) query)
template<typename T>
class SparseTable {
    vector<vector<T>> st;
    vector<int> lg;
    bool is_min;
    
    T op(T a, T b) { return is_min ? min(a, b) : max(a, b); }
    
public:
    SparseTable(const vector<T>& arr, bool min_query = true) : is_min(min_query) {
        int n = arr.size();
        int k = __lg(n) + 1;
        st.assign(k, vector<T>(n));
        lg.assign(n + 1, 0);
        
        for (int i = 2; i <= n; i++) lg[i] = lg[i/2] + 1;
        
        st[0] = arr;
        for (int i = 1; i < k; i++) {
            for (int j = 0; j + (1 << i) <= n; j++) {
                st[i][j] = op(st[i-1][j], st[i-1][j + (1 << (i-1))]);
            }
        }
    }
    
    T query(int l, int r) { // [l, r] inclusive
        int i = lg[r - l + 1];
        return op(st[i][l], st[i][r - (1 << i) + 1]);
    }
};

// Segment Tree for dynamic MIN/MAX (O(n) build, O(log n) query/update)
template<typename T>
class SegmentTree {
    vector<T> tree;
    int n;
    bool is_min;
    T neutral;
    
    T op(T a, T b) { return is_min ? min(a, b) : max(a, b); }
    
    void build(const vector<T>& arr, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = arr[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(arr, 2*v, tl, tm);
            build(arr, 2*v+1, tm+1, tr);
            tree[v] = op(tree[2*v], tree[2*v+1]);
        }
    }
    
    T query(int v, int tl, int tr, int l, int r) {
        if (l > r) return neutral;
        if (l == tl && r == tr) return tree[v];
        int tm = (tl + tr) / 2;
        return op(query(2*v, tl, tm, l, min(r, tm)),
                  query(2*v+1, tm+1, tr, max(l, tm+1), r));
    }
    
    void update(int v, int tl, int tr, int pos, T val) {
        if (tl == tr) {
            tree[v] = val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm) update(2*v, tl, tm, pos, val);
            else update(2*v+1, tm+1, tr, pos, val);
            tree[v] = op(tree[2*v], tree[2*v+1]);
        }
    }
    
public:
    SegmentTree(const vector<T>& arr, bool min_query = true) : is_min(min_query) {
        n = arr.size();
        neutral = is_min ? numeric_limits<T>::max() : numeric_limits<T>::min();
        tree.assign(4 * n, neutral);
        build(arr, 1, 0, n - 1);
    }
    
    T query(int l, int r) { return query(1, 0, n - 1, l, r); }
    void update(int pos, T val) { update(1, 0, n - 1, pos, val); }
};

// ============ SUM Queries ============

// Prefix Sum for static SUM (O(n) build, O(1) query)
template<typename T>
class PrefixSum {
    vector<T> prefix;
    
public:
    PrefixSum(const vector<T>& arr) {
        int n = arr.size();
        prefix.resize(n + 1);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + arr[i];
        }
    }
    
    T query(int l, int r) { return prefix[r + 1] - prefix[l]; }
};

// Fenwick Tree for dynamic SUM (O(n) build, O(log n) query/update)
template<typename T>
class FenwickTree {
    vector<T> tree;
    int n;
    
public:
    FenwickTree(int size) : n(size), tree(size + 1) {}
    
    FenwickTree(const vector<T>& arr) : n(arr.size()), tree(arr.size() + 1) {
        for (int i = 0; i < n; i++) update(i, arr[i]);
    }
    
    void update(int idx, T delta) {
        for (++idx; idx <= n; idx += idx & -idx) tree[idx] += delta;
    }
    
    T query(int idx) { // sum [0, idx]
        T sum = 0;
        for (++idx; idx > 0; idx -= idx & -idx) sum += tree[idx];
        return sum;
    }
    
    T query(int l, int r) { return query(r) - (l > 0 ? query(l - 1) : 0); }
};

// ============ XOR Queries ============

// Prefix XOR for static XOR (O(n) build, O(1) query)
template<typename T>
class PrefixXOR {
    vector<T> prefix;
    
public:
    PrefixXOR(const vector<T>& arr) {
        int n = arr.size();
        prefix.resize(n + 1);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] ^ arr[i];
        }
    }
    
    T query(int l, int r) { return prefix[r + 1] ^ prefix[l]; }
};

// Fenwick Tree for dynamic XOR (O(n) build, O(log n) query/update)
template<typename T>
class FenwickTreeXOR {
    vector<T> tree;
    int n;
    
public:
    FenwickTreeXOR(int size) : n(size), tree(size + 1) {}
    
    FenwickTreeXOR(const vector<T>& arr) : n(arr.size()), tree(arr.size() + 1) {
        for (int i = 0; i < n; i++) update(i, arr[i]);
    }
    
    void update(int idx, T val) {
        for (++idx; idx <= n; idx += idx & -idx) tree[idx] ^= val;
    }
    
    T query(int idx) { // xor [0, idx]
        T res = 0;
        for (++idx; idx > 0; idx -= idx & -idx) res ^= tree[idx];
        return res;
    }
    
    T query(int l, int r) { return query(r) ^ (l > 0 ? query(l - 1) : 0); }
};

// ============ GCD Queries ============

// Sparse Table for static GCD (O(n log n) build, O(1) query)
template<typename T>
class SparseTableGCD {
    vector<vector<T>> st;
    vector<int> lg;
    T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
public:
    SparseTableGCD(const vector<T>& arr) {
        int n = arr.size();
        int k = n > 0 ? __lg(n) + 1 : 0;
        st.assign(k, vector<T>(n));
        lg.assign(max(1, n) + 1, 0);
        if (n == 0) return;
        for (int i = 2; i <= n; i++) lg[i] = lg[i/2] + 1;
        st[0] = arr;
        for (int i = 1; i < k; i++) {
            for (int j = 0; j + (1 << i) <= n; j++) {
                st[i][j] = gcd(st[i-1][j], st[i-1][j + (1 << (i-1))]);
            }
        }
    }
    T query(int l, int r) {
        if (st.empty()) return T(0);
        int len = r - l + 1;
        int i = lg[len];
        return gcd(st[i][l], st[i][r - (1 << i) + 1]);
    }
};

// Segment Tree for dynamic GCD (O(n) build, O(log n) query/update)
template<typename T>
class SegmentTreeGCD {
    vector<T> tree;
    int n;
    
    T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
    
    void build(const vector<T>& arr, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = arr[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(arr, 2*v, tl, tm);
            build(arr, 2*v+1, tm+1, tr);
            tree[v] = gcd(tree[2*v], tree[2*v+1]);
        }
    }
    
    T query(int v, int tl, int tr, int l, int r) {
        if (l > r) return 0;
        if (l == tl && r == tr) return tree[v];
        int tm = (tl + tr) / 2;
        return gcd(query(2*v, tl, tm, l, min(r, tm)),
                   query(2*v+1, tm+1, tr, max(l, tm+1), r));
    }
    
    void update(int v, int tl, int tr, int pos, T val) {
        if (tl == tr) {
            tree[v] = val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm) update(2*v, tl, tm, pos, val);
            else update(2*v+1, tm+1, tr, pos, val);
            tree[v] = gcd(tree[2*v], tree[2*v+1]);
        }
    }
    
public:
    SegmentTreeGCD(const vector<T>& arr) {
        n = arr.size();
        tree.assign(4 * n, 0);
        build(arr, 1, 0, n - 1);
    }
    
    T query(int l, int r) { return query(1, 0, n - 1, l, r); }
    void update(int pos, T val) { update(1, 0, n - 1, pos, val); }
};

// ============ AND/OR Queries ============

// Sparse Table for static AND/OR (O(n log n) build, O(1) query)
template<typename T>
class SparseTableBitwise {
    vector<vector<T>> st;
    vector<int> lg;
    bool is_and;
    
    T op(T a, T b) { return is_and ? (a & b) : (a | b); }
    
public:
    SparseTableBitwise(const vector<T>& arr, bool and_query = true) : is_and(and_query) {
        int n = arr.size();
        int k = __lg(n) + 1;
        st.assign(k, vector<T>(n));
        lg.assign(n + 1, 0);
        
        for (int i = 2; i <= n; i++) lg[i] = lg[i/2] + 1;
        
        st[0] = arr;
        for (int i = 1; i < k; i++) {
            for (int j = 0; j + (1 << i) <= n; j++) {
                st[i][j] = op(st[i-1][j], st[i-1][j + (1 << (i-1))]);
            }
        }
    }
    
    T query(int l, int r) {
        int i = lg[r - l + 1];
        return op(st[i][l], st[i][r - (1 << i) + 1]);
    }
};

// Segment Tree for dynamic AND/OR (O(n) build, O(log n) query/update)
template<typename T>
class SegmentTreeBitwise {
    vector<T> tree;
    int n;
    bool is_and;
    T neutral;
    
    T op(T a, T b) { return is_and ? (a & b) : (a | b); }
    
    void build(const vector<T>& arr, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = arr[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(arr, 2*v, tl, tm);
            build(arr, 2*v+1, tm+1, tr);
            tree[v] = op(tree[2*v], tree[2*v+1]);
        }
    }
    
    T query(int v, int tl, int tr, int l, int r) {
        if (l > r) return neutral;
        if (l == tl && r == tr) return tree[v];
        int tm = (tl + tr) / 2;
        return op(query(2*v, tl, tm, l, min(r, tm)),
                  query(2*v+1, tm+1, tr, max(l, tm+1), r));
    }
    
    void update(int v, int tl, int tr, int pos, T val) {
        if (tl == tr) {
            tree[v] = val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm) update(2*v, tl, tm, pos, val);
            else update(2*v+1, tm+1, tr, pos, val);
            tree[v] = op(tree[2*v], tree[2*v+1]);
        }
    }
    
public:
    SegmentTreeBitwise(const vector<T>& arr, bool and_query = true) : is_and(and_query) {
        n = arr.size();
        neutral = is_and ? ~T(0) : T(0); // all 1s for AND, all 0s for OR
        tree.assign(4 * n, neutral);
        build(arr, 1, 0, n - 1);
    }
    
    T query(int l, int r) { return query(1, 0, n - 1, l, r); }
    void update(int pos, T val) { update(1, 0, n - 1, pos, val); }
};
```

Usage 
0 based indexing [l, r] with l, r inclusive
```cpp
vector<int> arr = {3, 1, 4, 1, 5, 9, 2, 6}; 
cout << "Array: [3, 1, 4, 1, 5, 9, 2, 6]\n\n"; 
// ===== MIN/MAX ===== 
cout << "MIN/MAX Queries:\n"; 
// Static - Sparse Table 
SparseTable<int> st_min(arr, true); // true = min 
SparseTable<int> st_max(arr, false); // false = max 
cout << " Min[2,5] = " << st_min.query(2, 5) << "\n"; 
cout << " Max[2,5] = " << st_max.query(2, 5) << "\n"; 
// Dynamic - Segment Tree 
SegmentTree<int> seg_min(arr, true); 
cout << " Before update: Min[0,7] = " << seg_min.query(0, 7) << "\n"; 
seg_min.update(1, 10); // Change arr[1] from 1 to 10 
cout << " After update arr[1]=10: Min[0,7] = " << seg_min.query(0, 7) << "\n\n"; 

// ===== SUM ===== 
cout << "SUM Queries:\n"; 
// Static - Prefix Sum 
PrefixSum<int> psum(arr); cout << " Sum[2,5] = " << psum.query(2, 5) << "\n"; 
// Dynamic - Fenwick Tree 
FenwickTree<int> fen(arr); cout << " Before update: Sum[0,7] = " << fen.query(0, 7) << "\n"; 
fen.update(3, 5); // Add 5 to arr[3] 
cout << " After update (add 5 to arr[3]): Sum[0,7] = " << fen.query(0, 7) << "\n\n"; 

// ===== XOR ===== 
cout << "XOR Queries:\n"; 
// Static - Prefix XOR 
PrefixXOR<int> pxor(arr); cout << " XOR[2,5] = " << pxor.query(2, 5) << "\n"; 
// Dynamic - Fenwick Tree XOR 
FenwickTreeXOR<int> fen_xor(arr); 
cout << " Before update: XOR[0,7] = " << fen_xor.query(0, 7) << "\n"; 
fen_xor.update(0, 3); // Toggle bits: arr[0] ^= 3 
cout << " After update (xor arr[0] with 3): XOR[0,7] = " << fen_xor.query(0, 7) << "\n\n"; 

// ===== GCD ===== 
cout << "GCD Queries:\n"; vector<int> arr2 = {12, 18, 24, 6, 30}; 
// Static - Sparse Table GCD 
SparseTableGCD<int> st_gcd(arr2); cout << " Array: [12, 18, 24, 6, 30]\n"; cout << " GCD[1,3] = " << st_gcd.query(1, 3) << "\n"; 
// Dynamic - Segment Tree GCD 
SegmentTreeGCD<int> seg_gcd(arr2); cout << " Before update: GCD[0,4] = " << seg_gcd.query(0, 4) << "\n"; 
seg_gcd.update(3, 12); // Change arr[3] from 6 to 12 
cout << " After update arr[3]=12: GCD[0,4] = " << seg_gcd.query(0, 4) << "\n\n"; 

// ===== AND/OR ===== 
cout << "AND/OR Queries:\n"; vector<int> arr3 = {7, 5, 3, 1, 6, 4, 2}; 
// Static - Sparse Table AND/OR 
SparseTableBitwise<int> st_and(arr3, true); // true = AND 
SparseTableBitwise<int> st_or(arr3, false); // false = OR 
cout << " Array: [7, 5, 3, 1, 6, 4, 2]\n"; cout << " AND[1,4] = " << st_and.query(1, 4) << "\n"; 
cout << " OR[1,4] = " << st_or.query(1, 4) << "\n"; 
// Dynamic - Segment Tree AND/OR 
SegmentTreeBitwise<int> seg_or(arr3, false); cout << " Before update: OR[0,6] = " << seg_or.query(0, 6) << "\n"; 
seg_or.update(0, 15); // Change arr[0] from 7 to 15 
cout << " After update arr[0]=15: OR[0,6] = " << seg_or.query(0, 6) << "\n";`
```


# Some observations
1) (a + b) and (a ^ b) have the same parity (AND and XOR share the same parity)
2) Manhattan distance property: if b lies between a and c, then MANH(a, b) + MANH(b, c) = MANH(a, c)
3) k bitstring (i.e., count of 0s and 1s are equal in every window of size k) -> can be represented as ss...ss' where s.size() == k and s' is a prefix of s
4) A `periodic` string that is palindromic is `piecewise` palindromic.
5) To find the kth number after performing some deletions in the sequence 1, 2, ... M, express the number of terms left in the sequence 1,2 .., p as f(p) and using `binary search` find the smallest k such that `f(p) = k`.
6) To add the same number to a range of elements a_l, a_l+1, ..., a_r use `difference array` trick.
7) To find the greatest j such that `a[j] >= a[i]` and `j < i` or the smallest j such that `a[j] < a[i]` and `j > i` use `Monotonic stack`. 
```cpp
for (int i = 0; i < n; i++) {
	if (st.empty()) st.push(i);
	else {
		while (!st.empty() && a[st.top()] < a[i]) st.pop();
		if (!st.empty()) l[i] = st.top();
		st.push(i);
	}
}
```
8) `a[r[i]] > a[i], a[l[i]] >= a[i]` , no. of subsegments with `a[i] max = (i-l[i]) * (r[i]-i)` . `l` and `r` can be found using monotonic stack.
9) **sum of max values over all subsegments** = $\sum_{i=0}^{n}$ `a[i] * (# subsegments where a[i] is max)` = $\sum_{i=0}^{n}a[i]*(i-l[i])*(r[i]-i)$
10) Maximum XOR over given numbers -> `XOR Trie`.
```cpp
struct TrieNode {
    TrieNode* child[2];
    int leaf_cnt;
    TrieNode() {
        leaf_cnt = 0;
        child[0] = nullptr;
        child[1] = nullptr;
    }
};
class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    // assuming 32 bit int
    void insert(const int& x) {
        TrieNode* cur = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (x >> i) & 1;
            if (!cur->child[bit])
                cur->child[bit] = new TrieNode();
            cur = cur->child[bit];
        }
        (cur->leaf_cnt)++;
    }
    void remove(const int& x) {
        TrieNode* cur = root;
        TrieNode* path[32];  // store path for backtracking
        int bits[32];        // store bits along the path 
        for (int i = 31; i >= 0; i--) {
            int bit = (x >> i) & 1;
            if (!cur->child[bit]) return; // x not present
            path[i] = cur;                // parent at this level
            bits[i] = bit;
            cur = cur->child[bit];
        }
        cur->leaf_cnt--;
        // cleanup if leaf_cnt == 0
        if (cur->leaf_cnt == 0) {
            for (int i = 0; i <= 31; i++) {
                TrieNode* parent = path[i];
                int bit = bits[i];
                TrieNode* node = parent->child[bit];
                // only delete if node has no children and leaf_cnt == 0
                if (node->leaf_cnt == 0 && !node->child[0] && !node->child[1]) {
                    delete node;
                    parent->child[bit] = nullptr;
                } else {
                    break; // stop if node still needed
                }
            }
        }
    }
    int maxXor(const int& x) {
        TrieNode* cur = root;
        int y = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = ((x >> i) & 1) ^ 1; // prefer opposite bit
            if (cur->child[bit]) {
                cur = cur->child[bit];
                if (bit) y |= (1 << i);
            }
            else if (cur->child[bit ^ 1]) {
                cur = cur->child[bit ^ 1];
                if (bit ^ 1) y |= (1 << i);
            }
            else break;
        }
        return x ^ y;
    }
};
```
11) To find the longest balanced bracket subsequence, use `Segment tree` with these join relations $(a_1, b_1, c_1)$, $(a_2, b_2, c_2)$ (b -> cnt of open unused bracket, c -> cnt of closed unused bracket) $t = \min(b_1, c_2), a = a_1 + a_2 + 2 * t, b = b_1 + b_2 - t, c = c_1 + c_2 - t$. 
# Other templates
### Inversion count -> Merge sort -> O(NlogN)
```cpp
long long mergeAndCount(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp;
    int i = left, j = mid + 1;
    long long count = 0;

    while (i <= mid && j <= right) {
        if (arr[i] < arr[j]) {
            // arr[i] is smaller than all remaining arr[j..right]
            count += (right - j + 1);
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
        }
    }
    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= right) temp.push_back(arr[j++]);

    for (int k = left; k <= right; k++) {
        arr[k] = temp[k - left];
    }
    return count;
}

long long mergeSortAndCount(vector<int>& arr, int left, int right) {
    if (left >= right) return 0;
    int mid = left + (right - left) / 2;
    long long count = 0;
    count += mergeSortAndCount(arr, left, mid);
    count += mergeSortAndCount(arr, mid + 1, right);
    count += mergeAndCount(arr, left, mid, right);
    return count;
}

long long countIncreasingPairs(vector<int>& arr) {
    return mergeSortAndCount(arr, 0, arr.size() - 1);
}
```
### Sort 0,1,2 -> Dutch National flag algo ( Quick Sort 3 way partition ) -> O(N)
```cpp
void threeWayPartition(vector<int>& arr, int lowVal, int highVal) {
    int n = arr.size();
    int start = 0, end = n - 1;
    int i = 0;
    while (i <= end) {
        if (arr[i] < lowVal) {
            swap(arr[i], arr[start]);
            start++;
            i++;
        }
        else if (arr[i] > highVal) {
            swap(arr[i], arr[end]);
            end--;
            // do not increment i here, because swapped element needs to be checked
        }
        else {
            i++;
        }
    }
}
```
### LIS with tracking in O(NlogN)
```cpp
vector<int> printLIS(vector<int>& arr) {
    int n = arr.size();
    vector<int> tail;              // stores last element of LIS of each length
    vector<int> tailIndex;         // stores indices of tail elements
    vector<int> prevIndex(n, -1);  // to reconstruct LIS
    for (int i = 0; i < n; i++) {
        // Find position using binary search
        int pos = lower_bound(tail.begin(), tail.end(), arr[i]) - tail.begin();
        if (pos == (int)tail.size()) {
            tail.push_back(arr[i]);
            tailIndex.push_back(i);
        } else {
            tail[pos] = arr[i];
            tailIndex[pos] = i;
        }
        // Link to predecessor
        if (pos > 0) {
            prevIndex[i] = tailIndex[pos - 1];
        }
    }
    // Reconstruct LIS
    vector<int> lis;
    int idx = tailIndex.back();
    while (idx != -1) {
        lis.push_back(arr[idx]);
        idx = prevIndex[idx];
    }
    reverse(lis.begin(), lis.end());
	return lis;
}
```
### Interval merging
```cpp
struct Interval {
    int start, end;
};

// Function to merge overlapping intervals
vector<Interval> mergeIntervals(vector<Interval>& intervals) {
    if (intervals.empty()) return {};
    // Sort intervals by start time
    sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {
        return a.start < b.start;
    });
    vector<Interval> merged;
    merged.push_back(intervals[0]);
    for (size_t i = 1; i < intervals.size(); i++) {
        Interval& last = merged.back();
        if (intervals[i].start <= last.end) {
            // Overlap: extend the last interval
            last.end = max(last.end, intervals[i].end);
        } else {
            // No overlap: add new interval
            merged.push_back(intervals[i]);
        }
    }
    return merged;
}
```
