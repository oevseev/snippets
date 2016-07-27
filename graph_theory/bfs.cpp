vector<int> adj[MAXN];
bool visited[MAXN];

void dfs(int start)
{
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (!visited[v]) q.push(v);
            visited[v] = true;
        }
    }
}
