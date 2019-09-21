# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def kthSmallest(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: int
        """
        self.res = []
        def inorder(root):
            if not root:
                return
            inorder(root.left)
            self.res.append(root.val)
            print(root.val)
            inorder(root.right)
        inorder(root)
        sorted(self.res)
        return self.res[k-1]