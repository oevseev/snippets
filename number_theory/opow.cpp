int64_t opow(int64_t n, int64_t p)
{
    int64_t res = 1;

    if (n == 0 || n == 1)
    	return n;
    if (n == -1)
    	return (p % 2) ? -1 : 1;

    while (p > 0) {
        int64_t new_res = res * n;
        if (res != 0 && new_res / res != n)
            return INT64_MAX;
        res = new_res;
        p--;
    }
    return res;
}
