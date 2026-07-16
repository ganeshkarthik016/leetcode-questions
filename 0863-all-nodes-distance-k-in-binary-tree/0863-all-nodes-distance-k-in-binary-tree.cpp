/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root,TreeNode* parent,unordered_map<int,TreeNode*>& map){
        if(!root){
            return ;
        }
        map[root -> val] = parent;
        dfs(root -> left,root,map);
        dfs(root -> right,root,map);
        return ;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        unordered_map<int,TreeNode*>map;
        dfs(root,nullptr,map);
        int level = 0;
        queue<TreeNode* >q;
        q.push(target);
        unordered_set<TreeNode*>set;
        set.insert(target);
        while(level < k){
            int size = q.size();
            while(size-- > 0){
                TreeNode* top = q.front();
                q.pop();
                if(top -> left && !set.count(top -> left)){
                    q.push(top -> left);
                    set.insert(top -> left);
                }
                if(top -> right && !set.count(top -> right)){
                    q.push(top -> right);
                    set.insert(top -> right);
                }
                if(map[top -> val] != nullptr && !set.count(map[top -> val])){
                    q.push(map[top -> val]);
                    set.insert(map[top -> val]);
                }
            }
            level++;
        }
        vector<int>res;
        while(!q.empty()){
            res.push_back(q.front() -> val);
            q.pop();
        }
        return res;
    }
};