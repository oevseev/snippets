bool visited[MAXN];
vector<int> adj[MAXN];

void dfs(int start)
{
    stack<int> s;
    s.push(start);
    visited[start] = true;

    while (!s.empty()) {
        int u = s.top();
        s.pop();

        for (int v : adj[u]) {
            if (!visited[v]) s.push(v);
            visited[v] = true;
        }
    }
}
