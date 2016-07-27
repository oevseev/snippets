int a[MAXN+1];

void add(int i, int n)
{
    while (i <= MAXN) {
        a[i] += n;
        i += i & -i;
    }
}

int ps(int i)
{
    int res = 0;
    while (i > 0) {
        res += a[i];
        i -= i & -i;
    }
    return res;
}