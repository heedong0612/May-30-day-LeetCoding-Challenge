from queue import Queue
from typing import List

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def bstFromPreorder(self, preorder: List[int]) -> TreeNode:
    '''
    Super slow solution (runtime was triple the average)
    But hey it works 
    '''
    def buildSub(arr: Queue):
        '''
        Build sub helper method
        '''
        # base case
        if arr.empty():
            return TreeNode()

        # recursive case
        root = TreeNode(arr.get())
        qLeft, qRight = Queue(), Queue()
        while not arr.empty():
            val = arr.get()
            if val < root.val:
                qLeft.put(val)
            else:
                qRight.put(val)
        root.left = buildSub(qLeft)
        root.right = buildSub(qRight)
        
        return root

    if len(preorder) == 0:
        return TreeNode()

    # init root    
    root = TreeNode(val = preorder[0])

    # init left and right queue
    qLeft, qRight = Queue(), Queue()

    # build init left and right queues
    for i in range(1, len(preorder)):
        if preorder[i] < root.val:
            qLeft.put(preorder[i])
        else:
            qRight.put(preorder[i])
    root.left = buildSub(qLeft)
    root.right = buildSub(qRight)
    
    return root    
        

