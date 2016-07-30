int n, d[MAXN];
vector<tuple<int, int, int>> edges;

bool bellman_ford(int s)
{
    int u, v, w;

    fill_n(d, n, INT_MAX);
    d[s] = 0;

    for (int i = 1; i < n; i++) {
        for (auto edge : edges) {
            tie(u, v, w) = edge;
            if (d[u] == INT_MAX) continue;
            d[v] = min(d[v], d[u] + w);
        }
    }

    for (auto edge : edges) {
        tie(u, v, w) = edge;
        if (d[v] > d[u] + w) return false;
    }

    return true;
}
