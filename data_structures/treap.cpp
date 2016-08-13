mt19937 gen;

struct Node {
    Node *l = nullptr, *r = nullptr;

    int x, y = gen(), v = 0;
    int64_t sum = 0;

    Node(int _x) : x(_x) {}
    Node(int _x, int _v) : x(_x), v(_v), sum(_v) {}
};

typedef Node *Treap;
typedef pair<Treap, Treap> ptt;

int64_t s(Treap t)
{
    return t ? t->sum : 0LL;
}

Treap fix(Treap t)
{
    if (t) t->sum = t->x + s(t->l) + s(t->r);
    return t;
}

Treap find(Treap t, int x)
{
    if (!t)
        return nullptr;

    if (x < t->x)
        return find(t->l, x);
    else if (x > t->x)
        return find(t->r, x);
    else
        return t;
}

Treap merge(Treap a, Treap b)
{
    if (!a || !b)
        return a ? a : b;

    if (a->y > b->y) {
        a->r = merge(a->r, b);
        return fix(a);
    }
    else {
        b->l = merge(a, b->l);
        return fix(b);
    }
}

ptt split(Treap t, int x)
{
    if (!t)
        return make_pair(nullptr, nullptr);

    if (t->x >= x) {
        ptt p = split(t->l, x);
        t->l = p.second;
        return make_pair(p.first, fix(t));
    }
    else {
        ptt p = split(t->r, x);
        t->r = p.first;
        return make_pair(fix(t), p.second);
    }
}

Treap insert(Treap t, int x, int v)
{
    ptt p = split(t, x);
    ptt q = split(p.second, x + 1);

    return merge(p.first, merge(new Node(x, v), q.second));
}

Treap erase(Treap t, int x)
{
    ptt p = split(t, x);
    ptt q = split(p.second, x + 1);

    return merge(p.first, q.second);
}
