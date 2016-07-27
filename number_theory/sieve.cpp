void gen_sieve()
{
    fill_n(sieve, MAXN, true);
    sieve[0] = sieve[1] = false;

    for (int i = 2; i * i <= MAXN; i++) {
        if (!sieve[i]) continue;
        for (int j = i * i; j <= MAXN; j += i)
            sieve[j] = false;
    }
}
