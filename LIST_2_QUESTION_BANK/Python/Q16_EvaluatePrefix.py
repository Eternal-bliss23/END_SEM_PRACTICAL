# Q16 - Evaluate Prefix Expression
# Purpose: Evaluate a space-separated prefix expression from right to left.

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
    expr = input("Enter prefix expression (e.g. + 3 * 2 4): ")
    tokens = expr.split()
    stack = []

    for tok in reversed(tokens):
        if tok in ('+', '-', '*', '/'):
            a = stack.pop()
            b = stack.pop()
            stack.append(apply_operator(tok, a, b))
        else:
            stack.append(int(tok))

    print("Prefix:", expr)
    print("Result:", stack[0])

if __name__ == "__main__":
    main()
