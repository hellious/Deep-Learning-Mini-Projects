


"""
Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.
   1
    \
     3
    /
   2

Output:
1
Explanation:
The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).


"""


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution(object):
    """
    :type root: TreeNode
    :rtype: int
    """
    """
    In-order traversal of BST yields sorted sequence. So, we just need to subtract the previous element from the current one, and keep track of the minimum. 
    """
    def __init__(self):
        self.min_diff = 10000000
        self.val = -1
    def getMinimumDifference(self, root):
        self.getMinDiff(root)
        return self.min_diff
    def getMinDiff(self,root):
        # traverse throgh the left nodes 
        # calculate the mi diff for current node by subtracting 
        # go for checking any element in right node with previous root value
        if root.left != None:
            self.getMinDiff(root.left)
        if self.val >= 0: # checking diff with previous root value stored in val
            self.min_diff = min(self.min_diff, root.val- self.val)
        self.val = root.val
        if root.right != None:
            self.getMinDiff(root.right)