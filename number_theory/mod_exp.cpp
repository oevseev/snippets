int mpow(int n, int p, int m)
{
    int res = 1 % m;
    while (p) {
        if (p & 1) res = (res * 1LL * n) % m;
        n = (n * 1LL * n) % m;
        p >>= 1;
    }
    return res;
}
