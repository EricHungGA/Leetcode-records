/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return result;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){

            int levelSize = q.size();
            vector<int> current_level;

            for(int i = 0; i < levelSize; i++){
                TreeNode* curr = q.front();
                q.pop();

                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
                current_level.push_back(curr->val);
            }
            result.push_back(current_level);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};