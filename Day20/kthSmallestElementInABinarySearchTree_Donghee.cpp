/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Donghee Lee
// 5/19/2020

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        // since it is a BST,
        // we can put it into a in-order list,
        // and get the k-th element
        
        /* try printing in-order here */
        // left, root, right
        int cc = 1;
        int foundNum = -1;
        inorder(root, cc, k, foundNum);
        return foundNum;
    }
    
    void inorder(TreeNode* root, int& cc, int k, int& foundNum) {
        if (root == nullptr) {
            return;
        }
        
        inorder(root->left, cc, k, foundNum);
        if (cc == k) 
            foundNum = root->val;
          
        inorder(root->right, ++cc, k, foundNum);
    }
   
};

// would work for any general tree
// class Solution {
// public:
//     int kthSmallest(TreeNode* root, int k) {
//         // put all element in a sorted set
//         set<int> s;
//         putAllElements(root, s);
//         // picke k-th element

//         set<int>::iterator sit = s.begin();
//         for(int i = 1; i < k; i++) sit++;
        
//         return *sit;
//     }
    
//     void putAllElements(TreeNode* root, set<int>& s) {
//         if (root == nullptr) return;
        
//         s.insert(root->val);
//         putAllElements(root->left, s);
//         putAllElements(root->right, s);
//     }
// };