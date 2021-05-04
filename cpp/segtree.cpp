#include<vector>
#include<functional>

template <typename T>
struct SegmentTree
{
    using F  = std::function<T(T, T)>;
    int n;
    F f;
    T unit;
    std::vector<T> data;
    SegmentTree(){};
    SegmentTree(F f, T unit):f(f), unit(unit){}
    void init(int n_)
    {
        n = 1;
        while (n < n_) n <<= 1; 
        data.assign(n << 1, unit);
    }

    void build(const std::vector<T> &v)
    {
        init(v.size());
        for(int i=0; i<v.size(); ++i) data[n+i] = v[i];
        for(int i=n-1; i>0; --i) data[i] = f(data[2*i], data[2*i+1]);
    }

    void add(int k, T x)
    {
        data[k+=n] += x;
        while (k >>= 1)
            data[k] = f(data[2 * k], data[2 * k + 1]);
    }

    T query(int a, int b)
    {
        T vl, vr;
        vl = vr = unit;
        for (int l = a+n, r = b+n; l < r; l >>= 1, r >>= 1)
        {
            if (l&1) vl = f(vl, data[l++]);
            if (r&1) vr = f(vr, data[--r]);
        }
        return f(vl, vr);
    }
};


// example
// auto f=[&](int a,int b){return max(a,b);};
// SegmentTree<int> sgtree(f, 0);
// sgtree.build(values); 
