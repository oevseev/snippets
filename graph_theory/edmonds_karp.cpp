int n, c[MAXN][MAXN], f[MAXN][MAXN], mf[MAXN], p[MAXN];

int edmonds_karp(int s, int t)
{
    int res = 0;

    while (true) {
        fill_n(mf, n, INT_MAX);
        fill_n(p, n, -1);

        queue<int> q;
        p[s] = s, q.push(s);

        while (!q.empty() && (p[t] != -1)) {
            int u = q.front();
            q.pop();

            for (int v = 0; v < n; v++) {
                if (u == v || p[v] != -1 || (c[u][v] - f[u][v] <= 0))
                    continue;
                mf[v] = min(mf[u], c[u][v] - f[u][v]);
                p[v] = u, q.push(v);
            }
        }

        if (p[t] == -1)
            break;

        int d = mf[t];
        while (p[t] != t) {
            f[p[t]][t] += d, f[t][p[t]] -= d;
            v = u;
        }
    }

    for (int i = 0; i < n; i++)
        res += f[s][i];

    return res;
}
