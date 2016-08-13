int cur[MAXN];
bool visited[MAXN];
vector<int> adj[MAXN];

void topsort(int start, vector<int> &res)
{
    stack<int> s;
    s.push(start);
    visited[start] = true;

    auto beg = res.end();

    while (!s.empty()) {
        int u = s.top(), k = cur[u];

        while (k < adj[u].size() && visited[adj[u][k]])
            k++;
        cur[u] = k;

        if (k < adj[u].size()) {
            int v = adj[u][k];
            s.push(v);
            visited[v] = true;
        }
        else {
            res.push_back(u);
            s.pop();
        }
    }

    reverse(beg, res.end());
}
