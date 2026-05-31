class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        sortedCandidates = sorted(candidates)
        res = []
        def dfs(i, curr, total):
            if total == target:
                res.append(curr.copy())
                return
            #gone to shit
            if total > target:
                return
            if i == len(candidates):
                return
            #actually good, so stop
            
            #include candidate i
            curr.append(sortedCandidates[i])
            dfs(i + 1, curr, total + sortedCandidates[i])
            curr.pop()

            #don't include candidate i
            while i + 1 < len(candidates) and sortedCandidates[i] == sortedCandidates[i + 1]:
                i += 1
            dfs(i + 1, curr, total)
        
        dfs(0, [], 0)
        return res

            
