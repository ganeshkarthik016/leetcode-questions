class TrieNode{
    public:
    vector<TrieNode*>child;
    TrieNode()
    {
        child = vector<TrieNode*>(2,nullptr);
    }
};

class Solution {
public:
TrieNode* root;

    void insert(int n)
    {
        TrieNode* tempRoot = root;
        bitset<32>b(n);
        for(int i=31;i>=0;i--)
        {
            if(!tempRoot->child[b[i]])tempRoot->child[b[i]] = new TrieNode();
        tempRoot = tempRoot->child[b[i]];
        }
    }

    int findMaximumXOR(vector<int>& nums) {
        int ans=0;
        root = new TrieNode();
        for(auto val : nums)
        {
            insert(val);
        }

        for(auto val : nums)
        {
            ans=max(ans,findMax(val));
        }
    return ans;
    }

    int findMax(int n)
    {
        int curAns=0;
        bitset<32>b(n);
        TrieNode* tempRoot = root;
        for(int i=31;i>=0;i--)
        {
            int opp = 1 - b[i];
            if(tempRoot->child[opp])
            {
                curAns = curAns + (1<<i);
            tempRoot = tempRoot->child[opp];
            }    
            else tempRoot = tempRoot->child[b[i]];
        }
    return curAns;
    }
};