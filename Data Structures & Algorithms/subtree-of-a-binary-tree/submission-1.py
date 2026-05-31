# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:   
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:

        def isEqual(curr, sub):
            
            if not curr and sub:
                return False
            elif not sub and curr:
                return False
            elif not sub and not curr:
                return True
            else:
                if sub.val == curr.val:
                    return isEqual(curr.left, sub.left) and isEqual(curr.right, sub.right)
                else:
                    return False;
        
        if not root:
            #traversed entire tree but couldn't find Root
            return False
        elif root.val == subRoot.val:
            #could be a potential subTree root
            if isEqual(root, subRoot):
                return True
            else:
                return self.isSubtree(root.left, subRoot) or self.isSubtree(root.right, subRoot)
        else:
            #node exists but cant be subTree root
            return self.isSubtree(root.left, subRoot) or self.isSubtree(root.right, subRoot)