# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isCousins(self, root: TreeNode, x: int, y: int) -> bool:
        '''
        Definition of being cousins:
        1. Same level
        2. Different parent

        Assumption:
        1. The number of nodes in the tree will be between 2 and 100.
        2. Each node has a unique integer value from 1 to 100.
        3. Node is guaranteed to be there??
        '''
        xLevel = self.getLevel(root, x, 0)
        yLevel = self.getLevel(root, y, 0)
        
        xParent = self.getParent(root, -1, x)
        yParent = self.getParent(root, -1, y)
        
        sameLevel = xLevel == yLevel
        print(f'sameLevel : {sameLevel}')
        
        sameParents = xParent == yParent
        print(f'sameParents : {sameParents}')
        
        return xLevel == yLevel and xParent != yParent
        
        
    def getLevel(self, root: TreeNode, target: int, ans: int) -> int:
        '''
        Get level of the target (.val)

        Parameter:
        - root: TreeNode    -> root of current subtree
        - target: int       -> the value of the node we're looking for
        - ans: int          -> the level that's going to get incremented in
                                each recursive call

        Returns:
        - 0, if root is None
        - the ans if found
        '''

        # if root is None return 0
        if root == None:
            return 0
        
        # return ans if .val == target
        if root.val == target:
            return ans
        
        level = self.getLevel(root.left, target, ans + 1)

        # if 0, then it's not on the left, move on to right
        if level != 0:
            return level
        
        return self.getLevel(root.right, target, ans + 1) 
    
    def getParent(self, child: TreeNode, parent: int, target: int) -> int:
        '''
        NGL got this from geeksforgeeks :(
        Get the parent's val for the target node

        Parameters:
        - child: TreeNode   -> current Node we're looking at
        - parent: int       -> the child's parent.val value
        - target: int       -> the wanted node.val

        Returns:
        - -1, when child is None (when target doesn't exist in subtree)
        - returns the max value of leftSubtree and rightSubtree
        '''
        if child == None:
            return -1
        
        if child.val == target:
            return parent
        else:
            left = self.getParent(child.left, child.val, target)
            right = self.getParent(child.right, child.val, target)
            return max(left, right)
            