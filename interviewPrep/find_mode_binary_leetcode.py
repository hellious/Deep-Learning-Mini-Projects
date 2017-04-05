
"""
Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
For example:
Given BST [1,null,2,2],

 1
    \
     2
    /
   2
return [2].

"""
# inorder travesal gives sorted and therefore add them serially in list and find most repeasted elemenst

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def __init__(self):
        self.dict_count = []
        self.max_val = -1
        self.result = []
    def dfs(self,root):
        if root == None:
            return []
        if root.left != None:
            self.dfs(root.left)# check for element in dict and raise count by one
        self.dict_count.append(root.val)
        count = self.dict_count.count(root.val)
        if count > self.max_val:
                self.result = []
                self.max_val = count
                self.result.append(root.val)
        elif count == self.max_val:
                self.result.append(root.val)
                
        if root.right != None:
            self.dfs(root.right)
            
    def findMode(self, root):
        self.dfs(root)
        if len(self.dict_count) == 0:
            return [];
        return self.result
        