# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def inorder(self, root, leaf_list):
        if not root:
            return
        elif not root.left and not root.right:
            leaf_list.append(root.val)
            return
        
        self.inorder(root.left, leaf_list)
        self.inorder(root.right, leaf_list)
    
    def leafSimilar(self, root1, root2):
        """
        :type root1: TreeNode
        :type root2: TreeNode
        :rtype: bool
        """
        
        leaf_list1 = list()
        leaf_list2 = list()
        
        self.inorder(root1, leaf_list1)
        self.inorder(root2, leaf_list2)
        
        return leaf_list1 == leaf_list2
        
