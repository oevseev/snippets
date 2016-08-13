int n, sqrt_n, a[MAXN], s[SQRT_MAXN];

int sum(int l, int r)
{
    int ll = (l + sqrt_n - 1) / sqrt_n;
    int rr = max((r + 1) / sqrt_n, ll);

    int ans = 0;

    for (int i = ll; i < rr; i++)
        ans += s[i];
    for (int i = l; i < min(ll * sqrt_n, r + 1); i++)
        ans += a[i];
    for (int i = rr * sqrt_n; i <= r; i++)
        ans += a[i];

    return ans;
}

void precalc()
{
    sqrt_n = sqrt(n);
    if (sqrt_n * sqrt_n != n) sqrt_n++;

    for (int i = 0; i < n; i++)
        s[i / sqrt_n] += a[i];
}
