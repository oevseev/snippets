int parent[MAXN], size[MAXN];

void init(int i)
{
    parent[i] = i;
    size[i] = 1;
}

int get_parent(int i)
{
    if (i == parent[i]) return i;
    parent[i] = get_parent(parent[i]);
    return parent[i];
}

int get_size(int i)
{
    return size[get_parent(i)];
}

void set_union(int i, int j)
{
    i = get_parent(i);
    j = get_parent(j);

    if (i != j) {
        if (size[i] < size[j])
            swap(i, j);

        parent[j] = i;
        size[i] += size[j];
    }
}
