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

    for (int i = 1; i <= n; i++) {
        if (!visited[i])
            dfs(i);
    }

    reverse(res, res + cur);
}
