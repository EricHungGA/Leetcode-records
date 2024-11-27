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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>result;
        // edge cases
        if(root == nullptr){
            return result;
        }
        if(root->left == nullptr && root->right == nullptr){
            result.push_back({root->val});
            return result;
        }

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int levelSize = q.size(); // size of CURRENT level
            vector<int>currentLevel; // stores the vals of the nodes in cur level & resets each level

            for(int i = 0; i < levelSize; i++){
                TreeNode* node = q.front();
                q.pop();

                // adding val to currentLevel vect
                currentLevel.push_back(node->val);

                // adding left and right children to q if they exist
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            // outside of the for loop we just need to add the current level ints to our result
            result.push_back(currentLevel);

        }

        return result;
    }
};