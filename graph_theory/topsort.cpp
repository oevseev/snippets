int n, cur, res[MAXN];
bool visited[MAXN];
vector<int> adj[MAXN];

void dfs(int u)
{
    if (visited[u]) return;
    visited[u] = true;

    for (int v : adj[u])
        dfs(v);
    res[cur++] = u;
}

void topsort()
{
    cur = 0;
    fill_n(visited, MAXN, false);

    for (int i = 0; i < n; i++) {
        int old = cur;
        if (!visited[i])
            dfs(i);
        reverse(res + old, res + cur);
    }
}
