int n, cur, res[MAXN], comp[MAXN];
bool visited[MAXN];
vector<int> adj[MAXN], rev[MAXN];

void dfs1(int u)
{
    if (visited[u]) return;
    visited[u] = true;

    for (int v : adj[u])
        dfs1(v);

    res[cur++] = u;
}

void dfs2(int u, int cur)
{
    if (comp[u] != 0) return;
    comp[u] = cur;

    for (int v : rev[u])
        dfs2(v, cur);
}

void kosaraju()
{
    cur = 0;
    fill_n(visited, MAXN, false);

    for (int i = 1; i <= n; i++) {
        if (!visited[i])
            dfs1(i);
    }

    int cur_comp = 1;
    fill_n(comp, MAXN, 0);

    for (int i = n; i > 0; i--) {
        int u = res[i];
        if (comp[u] == 0) {
            dfs2(u, cur_comp);
            cur_comp++;
        }
    }
}
