int im[MAXN], mt[MAXN];
bool visited[MAXN];
vector<int> adj[MAXN];

bool try_kuhn(int u)
{
    if (visited[u]) return false;
    visited[u] = true;

    for (int v : adj[u]) {
        if (im[u] == v) continue;
        if (mt[v] == -1 || try_kuhn(mt[v])) {
            im[u] = v, mt[v] = u;
            return true;
        }
    }

    return false;
}

int kuhn()
{
    int res = 0;
    bool upd = true;

    fill_n(im, n, -1);
    fill_n(mt, MAXN, -1);

    while (upd) {
        upd = false;
        fill_n(visited, n, false);

        for (int i = 0; i < n; i++) {
            if (im[i] == -1 && try_kuhn(i)) {
                res++;
                upd = true;
            }
        }
    }

    return res;
}
