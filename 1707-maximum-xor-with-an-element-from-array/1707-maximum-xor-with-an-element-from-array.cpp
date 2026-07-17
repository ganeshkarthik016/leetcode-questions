class trienode {
public:
    trienode* children[2];

    trienode() {
        children[0] = children[1] = nullptr;
    }
};

class trie {
public:
    trienode* root;

    trie() {
        root = new trienode();
    }

    void insert(int num) {
        trienode* curr = root;

        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if (curr->children[bit] == nullptr)
                curr->children[bit] = new trienode();

            curr = curr->children[bit];
        }
    }
};

class Solution {
public:
    int maxxor(int num, trie* root) {
        trienode* cur = root->root;
        int ans = 0;

        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if (cur->children[1 - bit]) {
                ans += (1 << i);
                cur = cur->children[1 - bit];
            } else {
                cur = cur->children[bit];
            }
        }

        return ans;
    }

    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& q) {

        int n = nums.size();
        int m = q.size();

        vector<int> ans(m, -1);

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > qc;

        for (int i = 0; i < m; i++) {
            int x = q[i][0];
            int limit = q[i][1];
            qc.push({limit, x, i});
        }

        sort(nums.begin(), nums.end());

        trie* root = new trie();

        int z = 0;

        while (!qc.empty()) {

            auto temp = qc.top();
            qc.pop();

            int limit = temp[0];
            int x = temp[1];
            int idx = temp[2];

            while (z < n && nums[z] <= limit) {
                root->insert(nums[z]);
                z++;
            }

            if (z == 0) {
                ans[idx] = -1;
                continue;
            }

            ans[idx] = maxxor(x, root);
        }

        return ans;
    }
};