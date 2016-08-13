typedef priority_queue<pair<int, int>, vector<pair<int, int>>,
    greater<pair<int, int>>> min_priority_queue;

int n, m, d[MAXN];
vector<pair<int, int>> adj[MAXN];

void dijkstra(int start)
{
    min_priority_queue q;

    fill_n(d, n, INT_MAX);
    q.push(make_pair(0, start));
    d[start] = 0;

    while (!q.empty()) {
        int p = q.top().first, u = q.top().second;
        q.pop();

        if (p > d[u]) continue;

        for (auto e : adj[u]) {
            int dst = p + e.second;
            if (dst < d[e.first]) {
                d[e.first] = dst;
                q.push(make_pair(dst, e.first));
            }
        }
    }
}
