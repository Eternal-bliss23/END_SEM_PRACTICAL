# Q17 - Evaluate Postfix Expression
# Purpose: Evaluate a space-separated postfix expression from left to right.

def apply_operator(op, a, b):
    if op == '+':
        return a + b
    if op == '-':
        return a - b
    if op == '*':
        return a * b
    if op == '/':
        return a // b

def main():
    expr = input("Enter postfix expression (e.g. 3 2 4 * +): ")
    tokens = expr.split()
    stack = []

    for tok in tokens:
        if tok in ('+', '-', '*', '/'):
            b = stack.pop()
            a = stack.pop()
            stack.append(apply_operator(tok, a, b))
        else:
            stack.append(int(tok))

    print("Postfix:", expr)
    print("Result:", stack[0])

if __name__ == "__main__":
    main()
