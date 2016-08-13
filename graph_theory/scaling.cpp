int n, c[MAXN][MAXN], f[MAXN][MAXN];
bool visited[MAXN];

bool try_augment(int u, int t, int m)
{
    if (visited[u]) return false;
    visited[u] = true;

    if (u == t) return true;

    for (int i = 0; i < n; i++) {
        if (u == i) continue;
        if (c[u][i] - f[u][i] >= m && try_augment(i, t, m)) {
            f[u][i] += m, f[i][u] -= m;
            return true;
        }
    }

    return false;
}

bool augment(int s, int t, int m)
{
    fill_n(visited, MAXN, false);
    return try_augment(s, t, m);
}

int max_flow(int s, int t)
{
    int m = 1 << 30, res = 0;

    while (m) {
        while (augment(s, t, m));
        m >>= 1;
    }

    for (int i = 0; i < n; i++)
        res += f[s][i];

    return res;
}
