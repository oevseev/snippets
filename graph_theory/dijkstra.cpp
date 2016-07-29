vector<int> adj[MAXN];
int n, m, d[MAXN], w[MAXN][MAXN];

void dijkstra(int start)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>,
        greater<pair<int, int>>> q;

    fill_n(d, n, INT_MAX);
    q.push(make_pair(0, start));
    d[start] = 0;

    while (!q.empty()) {
        int p = q.top().first, u = q.top().second;
        q.pop();

        if (p > d[u]) continue;

        for (int v : adj[u]) {
            int dst = p + w[u][v];
            if (dst < d[v]) {
                d[v] = dst;
                q.push(make_pair(dst, v));
            }
        }
    }
}
