const int MOD = 1e9 + 7;

int mpow(int n, int p)
{
    int res = 1;

    while (p) {
        if (p & 1) res = (res * 1LL * n) % MOD;
        n = (n * 1LL * n) % MOD;
        p >>= 1;
    }

    return res;
}
