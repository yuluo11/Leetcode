#include<vector>
#include<queue>
#include<algorithm>

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
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
        std::queue<TreeNode *> q;
        bool isreverse=false;
        if(root==nullptr)
            return {};
        q.push(root);
        std::vector<std::vector<int>>result;
        while(!q.empty()){
            int levelsize=q.size();
            std::vector<int> nv;
            for(int i=0;i<levelsize;i++){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left!=nullptr)
                    q.push(temp->left);
                if(temp->right!=nullptr)
                    q.push(temp->right);
                nv.push_back(temp->val);
            }
            if(isreverse)
                std::reverse(nv.begin(),nv.end());
            result.push_back(nv);
            isreverse=!isreverse;
        }
        return result;
    }
};