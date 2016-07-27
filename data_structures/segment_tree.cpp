int st[2 * MAXN];

void init_st()
{
    for (int i = MAXN - 1; i > 0; i--)
        st[i] = st[i << 1] + st[(i << 1) + 1];
}

int sum(int l, int r)
{
    int res = 0;
    for (l += MAXN, r += MAXN; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res += st[l++];
        if (r & 1) res += st[--r];
    }
    return res;
}

void add(int i, int n)
{
    i += MAXN;
    while (i > 0) {
        st[i] += n;
        i >>= 1;
    }
}
