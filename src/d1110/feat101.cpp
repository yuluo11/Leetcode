//遍历版，递归版见go_version
#include<utility>
#include<vector>

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
    bool isSymmetric(TreeNode* root) {
        if(root != nullptr&&root->left==nullptr&&root->right == nullptr)
            return true;
        if(root==nullptr)
            return true;
        std::vector<std::pair<TreeNode*,TreeNode*>>st;
        st.push_back({root->left,root->right});
        while(!st.empty()){
            auto [p,q]=st.back();
            st.pop_back();
            if(p==nullptr&&q==nullptr)
                continue;
            if(p==nullptr || q==nullptr)
                return false;
            if(p->val!=q->val)
                return false;
            st.push_back({p->left,q->right});
            st.push_back({p->right,q->left});
        }
        return true;
    }
};