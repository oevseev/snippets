int64_t t[4 * MAXN];

void update(int idx, int l, int r, int pos, int64_t d)
{
    if (r - l == 1) {
        t[idx] = d;
        return;
    }

    int m = (l + r) / 2;
    if (pos < m) add(2 * idx + 1, l, m, pos, d);
    else add(2 * idx + 2, m, r, pos, d);

    t[idx] = t[2 * idx + 1] + t[2 * idx + 2];
}

int64_t query(int idx, int l, int r, int L, int R)
{
    int64_t res = 0;

    if (l == L && r == R)
        return t[idx];

    int m = (l + r) / 2;
    if (L < m) res += rsq(2 * idx + 1, l, m, L, min(m, R));
    if (R > m) res += rsq(2 * idx + 2, m, r, max(L, m), R);

    return res;
}
