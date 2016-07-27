int xgcd(int a, int b, int &x, int &y)
{
    x = 1, y = 0;
    int x0 = 0, y0 = 1;

    while (a) {
        int q = a / b;
        a %= b, swap(a, b);
        x -= q * x0, swap(x, x0);
        y -= q * y0, swap(y, y0);
    }

    return a;
}
