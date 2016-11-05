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
#include <vector>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forb(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forn1(i, n) for (int i = 1; i <= (int)(n); i++)
#define forb1(i, n) for (int i = (int)(n); i > 0; i--)
#define forab(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define sz(x) (int)(x).size()

#define X first
#define Y second
#define A(x) get<0>(x)
#define B(x) get<1>(x)
#define C(x) get<2>(x)

#ifdef DEBUG
    #define db(x) cerr << #x << " = " << (x) << endl
    #define db2(x, y) cerr << #x << " = " << (x) << ", " << #y << \
        " = " << (y) << endl
    #define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
    #define eputs(s) eprintf("%s\n", (s))
#else
    #define db(x) ;
    #define db2(x, y) ;
    #define eprintf(...) ;
    #define eputs(s) ;
#endif

mt19937 gen;

inline int rnd(int x)
{
    return gen() % x;
}

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

typedef complex<double> cd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;
typedef tuple<ll, ll, ll> tlll;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<tiii> viii;
typedef vector<vector<int>> vvi;

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
#ifdef DEBUG
        eprintf("Time: %.3f\n", (double)clock() / CLOCKS_PER_SEC);
#endif
    }

    return 0;
}
