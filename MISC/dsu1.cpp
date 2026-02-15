#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

class UnionFind {
private:
    int n;
    std::vector<int> sz;
    std::vector<int> id;
    int numComponents;
    std::unordered_set<int> roots;
public:
    UnionFind(int size) {
        if (size <= 0) {
            std::cout << "Illegal\n";
            exit(1);
        }
        n = numComponents = size;
        sz.resize(size);
        id.resize(size);
        for (int i = 0; i < size; ++i) {
            id[i] = i;
            sz[i] = 1;
            roots.insert(i);
        }
    }
    int find(int p) {
        int root = p;
        while (root != id[root]) root = id[root];
        while (p != root) {
            int next = id[p];
            id[p] = root;
            p = next;
        }
        return root;
    }
    bool isConnected(int p, int q) { return find(p) == find(q); }
    int componentSize(int p) { return sz[find(p)]; }
    int size() { return n; }
    int components() { return numComponents; }
    const std::unordered_set<int>& getRoots() const { return roots; }
    void unify(int p, int q) {
        int root1 = find(p), root2 = find(q);
        if (root1 == root2) return;
        if (sz[root1] < sz[root2]) {
            sz[root2] += sz[root1];
            id[root1] = root2;
            roots.erase(root1);
        } else {
            sz[root1] += sz[root2];
            id[root2] = root1;
            roots.erase(root2);
        }
        numComponents--;
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n; std::cin >> n;
    UnionFind graph(n);
    std::vector<std::pair<int, int>> removedEdges;
    for (int i = 0; i < n-1; i++) {
        int a, b; std::cin >> a >> b; a--; b--;
        if (graph.isConnected(a, b)) removedEdges.push_back({a, b});
        else graph.unify(a, b);
    }
    int r = removedEdges.size();
    std::cout << r << '\n';
    auto it = removedEdges.begin();
    while (r > 0) {
        auto it1 = graph.getRoots().begin();
        auto it2 = std::next(it1);
        std::cout << it->first + 1 << " " << it->second + 1 << " " << (*it1) + 1 << " " << (*it2) + 1 << '\n';
        graph.unify(*it1, *it2);
        r--;
        it++;
    }
    return 0;
}