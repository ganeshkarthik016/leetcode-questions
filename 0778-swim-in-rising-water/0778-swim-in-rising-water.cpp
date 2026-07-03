class disjoint {
public:
    vector<int> parent, size;

    disjoint(int n) {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findUPar(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);

        if (pu == pv)
            return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size();

        vector<vector<int>> cells;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cells.push_back({grid[i][j], i, j});
            }
        }

        sort(cells.begin(), cells.end());

        disjoint ds(n * n);

        vector<vector<int>> vis(n, vector<int>(n, 0));

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        auto id = [&](int r, int c) {
            return r * n + c;
        };

        for (auto &v : cells) {

            int h = v[0];
            int r = v[1];
            int c = v[2];

            vis[r][c] = 1;

            for (int k = 0; k < 4; k++) {

                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr < 0 || nr >= n || nc < 0 || nc >= n)
                    continue;

                if (!vis[nr][nc])
                    continue;

                ds.unionBySize(id(r, c), id(nr, nc));
            }

            if (ds.findUPar(0) == ds.findUPar(n * n - 1))
                return h;
        }

        return -1;
    }
};