struct DSU{
    vector<int> f,sz;

    DSU(int n){
        f.resize(n + 1);
        sz.resize(n + 1);
        for(int i = 1;i <= n;i++) f[i] = i,sz[i] = 1;
    }

    int find(int x){
        if(x != f[x]) return f[x] = find(f[x]);
        return f[x]; 
    }

    bool same(int a,int b) {
        return find(a) == find(b);
    }

    bool merge(int a,int b){
        int fa = find(a),fb = find(b);
        if(fa == fb) return false;
        if(sz[fa] < sz[fb]) swap(fa,fb);
        sz[fa] += sz[fb];
        f[fb] = fa;
        return true;
    }

    int size(int x){
        return sz[find(x)];
    }
};