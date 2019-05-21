//BFS in bst with stl queue

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> node_q;
        if(root==NULL){
            return result;
        }
        node_q.push(root);
        result.push_back({root->val});
        int q_size;
        while(!node_q.empty()){
            q_size=node_q.size();
            vector<int> curLevel;
            for(size_t i=0;i<q_size;++i){
                TreeNode* cur=node_q.front();
                if(cur->left){
                    node_q.push(cur->left);
                    curLevel.push_back(cur->left->val);
                }
                if(cur->right){
                    node_q.push(cur->right);
                    curLevel.push_back(cur->right->val);
                }
                node_q.pop();
            }
            if(curLevel.size()>0)
                result.push_back(curLevel);
        }
        return result;
    }
}