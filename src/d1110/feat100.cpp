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
class Solution{
public:
    bool isSameTree(TreeNode *p,TreeNode *q){
        std::vector<std::pair<TreeNode*,TreeNode*>>st;
        st.push_back({p,q});
        while(!st.empty()){
            auto [p,q]=st.back();
            st.pop_back();
            if(p==nullptr && q==nullptr)
                continue;
            if(p==nullptr || q==nullptr)
                return false;
            if(p->val!=q->val)
                return false;
        }
        return true;
    }
};