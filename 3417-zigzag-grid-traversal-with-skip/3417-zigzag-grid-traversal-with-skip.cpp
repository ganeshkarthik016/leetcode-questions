class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        bool temp1 = false, temp2 = false;
        vector<int> ans;
        for(int i = 0; i < grid.size(); i++){
            if(temp1 == false){
                for(int j = 0; j < grid[0].size(); j++){
                    if(temp2 == false){
                        ans.push_back(grid[i][j]);
                        temp2 = true;
                    }
                    else{
                        temp2 = false;
                    }
                }
                temp1 = true;
            }
            else{
                for(int j = grid[0].size()-1; j >= 0; j--){
                    if(temp2 == false){
                        ans.push_back(grid[i][j]);
                        temp2 = true;
                    }
                    else{
                        temp2 = false;
                    }
                }
                temp1 = false;
            }
        }
        return ans;
    }
};