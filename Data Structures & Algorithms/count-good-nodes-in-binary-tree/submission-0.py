class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        
        def findGood(curr, maxVal):
            # Base case: if we hit a null child, it contributes 0 good nodes
            if not curr:
                return 0
            
            # Determine if the current node is "good"
            res = 1 if curr.val >= maxVal else 0
            
            # Update the max value seen so far for this path
            maxVal = max(maxVal, curr.val)
            
            # Recursively add good nodes from left and right subtrees
            res += findGood(curr.left, maxVal)
            res += findGood(curr.right, maxVal)
            
            return res

        # Start recursion with the root's value as the initial maximum
        return findGood(root, root.val)