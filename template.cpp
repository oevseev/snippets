#pragma region Template

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:67108864")
#endif

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cinttypes>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define sz(x) (int)(x).size()

#define fst first
#define snd second
#define A(x) get<0>(x)
#define B(x) get<1>(x)
#define C(x) get<2>(x)

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#define eputs(s) eprintf("%s\n", (s))
#else
#define eprintf(...) ((void)0)
#define eputs(s) ((void)0)
#endif

mt19937 gen(random_device{}());

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

typedef complex<double> cd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;
typedef tuple<ll, ll, ll> tlll;

const int INF = (int)1.01e9;
const int MOD = 1000000007;
const double EPS = 1e-9;
const double PI = acos(-1);

#pragma endregion

// #define FNAME ""

bool solve()
{
    return true;
}

int main()
{
#ifdef FNAME
    assert(freopen(FNAME ".in", "r", stdin));
    freopen(FNAME ".out", "w", stdout);
#endif

    while (solve()) {
        eprintf("Time: %.3f\n", (double)clock() / CLOCKS_PER_SEC);
    }

    return 0;
}
