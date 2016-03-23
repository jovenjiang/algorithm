//Given a binary tree containing digits from 0-9 only, 
//each root-to-leaf path could represent a number.

//An example is the root-to-leaf path 
//1->2->3 which represents the number 123.

//Find the total sum of all root-to-leaf numbers.

//For example,

//    1
//   / \
//  2   3
//The root-to-leaf path 1->2 represents the number 12.
//The root-to-leaf path 1->3 represents the number 13.
//Return the sum = 12 + 13 = 25

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        
        int num=0,sum=0;
        stack<TreeNode*> st;
        TreeNode* cur=root;
        TreeNode* last=NULL;
        while(cur || !st.empty()){
            if(cur){
                st.push(cur);
                num=num*10+cur->val;
                cur=cur->left;
            }
            else{
                TreeNode* top=st.top();
                if(!top->left && !top->right){
                    sum+=num;
                    num/=10;
                    last=top;
                    st.pop();
                }
                    
                else if(top->right && top->right!=last)
                    cur=top->right;
                else {
                   num/=10;
                   st.pop();
                   last=top;
                }
            }
        }
        return sum;

    }
};
