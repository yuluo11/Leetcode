#include<queue>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==nullptr)
            return 0;
        std::queue<std::pair<TreeNode*,int>> q;
        q.push({root,1});
        while(!q.empty()){
            auto [t,i]=q.front();
            q.pop();
            if (t->left == nullptr && t->right == nullptr)
                return i;        
            if(t->left!=nullptr)
                q.push({t->left,i+1});
            if(t->right!=nullptr)
                q.push({t->right,i+1});
        }
        return 0;
    }
};