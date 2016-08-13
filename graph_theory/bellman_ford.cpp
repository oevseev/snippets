int n, d[MAXN];
vector<pair<int, int>> adj;

bool bellman_ford(int s)
{
    fill_n(d, n, INT_MAX);
    d[s] = 0;

    for (int i = 1; i < n; i++) {
        for (int u = 0; u < n; u++) {
            if (d[u] == INT_MAX) continue;
            for (auto e : adj[u]) {
                int v = e.first, w = e.second;
                d[v] = min(d[v], d[u] + w);
            }
        }
    }

    for (int u = 0; u < n; u++) {
        for (auto e : adj[u]) {
            int v = e.first, w = e.second;
            if (d[v] > d[u] + w) return false;
        }
    }

    return true;
}
