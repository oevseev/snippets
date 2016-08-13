mt19937 gen;

struct Node {
    Node *l = nullptr, *r = nullptr;
    int x, y = gen(), size = 1;
    int64_t sum = 0;
    bool rev = false;

    Node(int _x) : x(_x), sum(_x) {}
};

typedef Node *Treap;
typedef pair<Treap, Treap> ptt;

int sz(Treap t)
{
    return t ? t->size : 0;
}

int64_t s(Treap t)
{
    return t ? t->sum : 0LL;
}

Treap fix(Treap t)
{
    if (t) {
        t->size = 1 + sz(t->l) + sz(t->r);
        t->sum = t->x + s(t->l) + s(t->r);
    }
    return t;
}

Treap push(Treap t)
{
    if (t && t->rev) {
        swap(t->l, t->r);
        if (t->l) t->l->rev ^= true;
        if (t->r) t->r->rev ^= true;
        t->rev = false;
    }
    return t;
}

Treap find(Treap t, int k)
{
    if (!t) return -1;
    push(t);

    int idx = sz(t->l);

    if (idx >= k) return find(t->l, k);
    else if (idx < k - 1) return find(t->r, k - idx - 1);
    else return t;
}

Treap merge(Treap a, Treap b)
{
    push(a), push(b);

    if (!a || !b)
        return a ? a : b;

    if (a->y > b->y) {
        a->r = merge(push(a->r), b);
        return fix(a);
    }
    else {
        b->l = merge(a, push(b->l));
        return fix(b);
    }
}

ptt split(Treap t, int k)
{
    if (!t) return make_pair(nullptr, nullptr);
    push(t);

    int idx = sz(t->l);

    if (idx >= k) {
        ptt p = split(push(t->l), k);
        t->l = p.second;
        return make_pair(p.first, fix(t));
    }
    else {
        ptt p = split(push(t->r), k - idx - 1);
        t->r = p.first;
        return make_pair(fix(t), p.second);
    }
}

Treap insert(Treap t, int k, int x)
{
    ptt p = split(t, k);
    return merge(p.first, merge(new Node(x), p.second));
}

Treap erase(Treap t, int k)
{
    ptt p = split(t, k - 1);
    ptt q = split(p.second, 1);
    return merge(p.first, q.second);
}
