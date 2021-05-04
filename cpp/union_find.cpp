#include<vector>

struct UnionFind
{
    int n;
    std::vector<int> parent;
    std::vector<int> rank;
    UnionFind(int _n) :n(_n)
    {
        parent.assign(n, -1);
        rank.assign(n, 1);
    }

    int find(int i)
    {
        if (parent[i] == -1)
            return i;
        else
            return parent[i] = find(parent[i]);
    }

    void unite(int i, int j)
    {
        i = find(i);
        j = find(j);

        if (i == j) return;

        if (rank[i] == rank[j])
        {
            parent[j] = i;
            ++rank[i];
        }
        else
        {
            if (rank[i] < rank[j]) std::swap(i, j);
            parent[j] = i;
        }
    }

    bool is_same(int i, int j)
    {
        return find(i) == find(j);
    }
};
