class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:

        rows = [{} for i in range(9)]
        columns = [{} for i in range(9)]
        squares = [[{} for i in range(3)] for j in range(3)]

        for i in range(9):
            row = board[i]
            for j in range(9):
                value = row[j]
                if value in rows[i]:
                    #the set of that row contains the number already
                    return False
                elif value in columns[j]:
                    #the set of that column contains the number already
                    return False
                elif value in squares[i // 3][j // 3]:
                    return False
                else:
                    if value == ".":
                        continue
                    else:
                        rows[i][value] = True
                        columns[j][value] = True
                        squares[i // 3][j // 3][value] = True
                
        return True
                















        """
        rows = {i : set() for i in range(9)}
        cols = {j : set() for j in range(9)}
        squares = {(i, j) : set() for i in range(3) for j in range(3)}

        for i in range(9):
            for j in range(9):

                #if not a value then continue
                if board[i][j] == ".":
                    continue

                #if value already present
                if (board[i][j] in rows[i] 
                    or board[i][j] in cols[j] 
                    or board[i][j] in squares[(i // 3, j // 3)]):
                    return False

                #if not in board
                rows[i].add(board[i][j])
                cols[j].add(board[i][j])
                squares[(i // 3, j // 3)].add(board[i][j])

        return True
        """


        