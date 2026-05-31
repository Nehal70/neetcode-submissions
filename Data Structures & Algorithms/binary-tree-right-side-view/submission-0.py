# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        queue = collections.deque()
        queue.append(root)
        result = []
        while len(queue) != 0:  
            qLen = len(queue)
            #addup the children
            # queue.append(queue[0].left)
            # queue.append(queue[0].right)
            # #pop yourself
            # queue.popleft()
            for i in range(qLen):
                node = queue.popleft()
                if node:
                    if node.left:
                        queue.append(node.left)
                    if node.right:
                        queue.append(node.right)
                    if i == qLen - 1:
                        result.append(node.val)

        return result
                
