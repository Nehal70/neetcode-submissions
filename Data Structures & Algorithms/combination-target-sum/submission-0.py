class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        res = []

        """
        - i determines which candidates we're still allowed to choose
        - total for that current combination
        - cur is the list we've added so far to the current combination
        """
        def dfs(i, cur, total):
            if total == target:
                #succesful combination
                res.append(cur.copy())
                return
            if i >= len(nums) or total > target:
                #violating restrictions
                return
            #decision 1, include this candidate
            cur.append(nums[i])
            dfs(i, cur, total + nums[i])
            cur.pop()
            #decision 2, don't include this candidate
            dfs(i + 1, cur, total)
        
        dfs(0, [], 0)

        return res

