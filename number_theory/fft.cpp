typedef complex<double> cd;

void fft(vector<cd> &a, bool inv)
{
    int n = (int)a.size();
    int j = 0;

    for (int i = 1; i < n; i++) {
        int t = n >> 1;
        for (; j >= t; t >>= 1)
            j -= t;
        j += t;
        if (i < j) swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        int z = (inv ? -1 : 1);
        double angle = 2 * M_PI / len * z;
        cd wlen(cos(angle), sin(angle));

        for (int i = 0; i < n; i += len) {
            cd w(1, 0);

            for (int j = 0; j < len / 2; j++) {
                cd u = a[i + j], v = w * a[i + j + len/2];
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }

    if (inv) {
        for (int i = 0; i < n; i++)
            a[i] /= n;
    }
}
