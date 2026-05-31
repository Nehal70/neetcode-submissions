# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:

        if not root:
            return True

        def calcHeight(curr):

            if not curr:
                return -1;

            return 1 + max(calcHeight(curr.right), calcHeight(curr.left))

        return (abs(calcHeight(root.left) - calcHeight(root.right)) <= 1) and (self.isBalanced(root.left) and self.isBalanced(root.right))
        