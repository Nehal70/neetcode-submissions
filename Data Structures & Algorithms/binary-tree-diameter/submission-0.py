# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.maximum = 0;

        def helpDia(curr):

            if not curr:
                return 0

            leftD = helpDia(curr.left)
            rightD = helpDia(curr.right)

            if (leftD + rightD) > self.maximum:
                self.maximum = leftD + rightD

            return 1 + max(leftD, rightD)

        helpDia(root)

        return self.maximum