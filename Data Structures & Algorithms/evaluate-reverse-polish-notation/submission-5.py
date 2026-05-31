class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        
        tokenStack = []
        
        for token in tokens:
            if token in ("+", "-", "*", "/"):
                # Convert strings to integers
                operand2 = int(tokenStack.pop())
                operand1 = int(tokenStack.pop())
                
                if token == "+":
                    result = operand1 + operand2
                elif token == "-":
                    result = operand1 - operand2
                elif token == "*":
                    result = operand1 * operand2
                elif token == "/":
                    # Truncate towards zero
                    result = int(operand1 / operand2)
                
                tokenStack.append(str(result))
            else:
                tokenStack.append(token)
        
        return int(tokenStack[0])
