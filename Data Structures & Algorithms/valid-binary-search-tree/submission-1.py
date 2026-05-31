# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        
        def checkValidNode(curr, maximum, minimum):
            #handle null case
            if not curr:
                return True

            if curr.val > minimum and curr.val < maximum:
                #valid root
                return checkValidNode(curr.left, curr.val, minimum) and checkValidNode(curr.right, maximum, curr.val)
            else:
                return False

        return checkValidNode(root, float('inf'), float('-inf'))