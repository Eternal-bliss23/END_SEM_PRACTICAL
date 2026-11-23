# Q14 - Infix to Prefix
# Purpose: Reverse infix, swap brackets, make postfix, then reverse again.

def precedence(op):
    if op == '+' or op == '-':
        return 1
    if op == '*' or op == '/':
        return 2
    return 0

# Pop only HIGHER precedence operators (needed after reversing infix).
def to_postfix(expr):
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
            while stack and precedence(stack[-1]) > precedence(ch):
                out.append(stack.pop())
            stack.append(ch)
    while stack:
        out.append(stack.pop())
    return ''.join(out)

def main():
    infix = input("Enter infix expression: ").replace(" ", "")

    reversed_expr = infix[::-1]
    swapped = ""
    for ch in reversed_expr:
        if ch == '(':
            swapped += ')'
        elif ch == ')':
            swapped += '('
        else:
            swapped += ch

    prefix = to_postfix(swapped)[::-1]

    print("Infix:  ", infix)
    print("Prefix: ", prefix)

if __name__ == "__main__":
    main()
