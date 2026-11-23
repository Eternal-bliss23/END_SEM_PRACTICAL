# Q15 - Infix to Postfix
# Purpose: Convert an infix expression to postfix using a stack.

def precedence(op):
    if op == '+' or op == '-':
        return 1
    if op == '*' or op == '/':
        return 2
    return 0

def infix_to_postfix(expr):
    out = []
    stack = []
    for ch in expr:
        if ch.isalnum():
            out.append(ch)
        elif ch == '(':
            stack.append(ch)
        elif ch == ')':
            while stack and stack[-1] != '(':
                out.append(stack.pop())
            stack.pop()
        else:
            while stack and precedence(stack[-1]) >= precedence(ch):
                out.append(stack.pop())
            stack.append(ch)
    while stack:
        out.append(stack.pop())
    return ''.join(out)

def main():
    infix = input("Enter infix expression: ").replace(" ", "")
    postfix = infix_to_postfix(infix)
    print("Infix:   ", infix)
    print("Postfix: ", postfix)

if __name__ == "__main__":
    main()
