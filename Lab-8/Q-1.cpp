#include<bits/stdc++.h>
using namespace std;

struct Edge {
    int start, end, weight;
};

class DS {
    vector<int> parent, rank;

public:
    DS(int n) {
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int xRoot = find(x);
        int yRoot = find(y);
        if (xRoot == yRoot)
            return;

        if (rank[xRoot] < rank[yRoot])
            parent[xRoot] = yRoot;
        else if (rank[xRoot] > rank[yRoot])
            parent[yRoot] = xRoot;
        else {
            parent[yRoot] = xRoot;
            rank[xRoot]++;
        }
    }
};

bool sortByWeight(const Edge &a, const Edge &b) {
    return a.weight > b.weight;
}

vector<Edge> maxSpanningTree(vector<Edge> &edges, int n) {
    sort(edges.begin(), edges.end(), sortByWeight);
    vector<Edge> MST;
    DS dsu(n);
    for (const auto &edge : edges) {
        int u = edge.start;
        int v = edge.end;
        int uRoot = dsu.find(u);
        int vRoot = dsu.find(v);
        if (uRoot != vRoot) {
            MST.push_back(edge);
            dsu.unite(uRoot, vRoot);
        }
    }
    return MST;
}

int main() {
    int n = 4;
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    vector<Edge> MST = maxSpanningTree(edges, n);

    cout << "Edges in Maximum Spanning Tree:" << endl;
    for (const auto &edge : MST) {
        cout << edge.start << " - " << edge.end << " weight: " << edge.weight << endl;
    }

    return 0;
}
