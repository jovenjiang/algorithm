//Given a binary tree, imagine yourself standing
// on the right side of it, return the values of the nodes 
//you can see ordered from top to bottom.

//For example:
//Given the following binary tree,
//     1            <---
//   /   \
//  2     3         <---
//   \     \
//    5     4       <---
//You should return [1, 3, 4].


class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> res;
        if(!root)
            return res;
        q.push(root);
        
        while(!q.empty()){
            res.push_back(q.back()->val);
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode *p=q.front();
                q.pop();
                if(p->left)
                    q.push(p->left);
                if(p->right)
                    q.push(p->right);
                
            }
            
        }
        return res;
    }
};
