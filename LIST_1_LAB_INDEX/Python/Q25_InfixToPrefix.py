PRECEDENCE = {"+": 1, "-": 1, "*": 2, "/": 2, "^": 3}


def precedence(operator):
    return PRECEDENCE.get(operator, 0)


def to_postfix(expression):
    output = []
    stack = []
    for ch in expression:
        if ch.isspace():
            continue
        if ch.isalnum():
            output.append(ch)
        elif ch == "(":
            stack.append(ch)
        elif ch == ")":
            while stack and stack[-1] != "(":
                output.append(stack.pop())
            if not stack:
                return None
            stack.pop()
        elif ch in PRECEDENCE:
            while stack and stack[-1] != "(" and precedence(stack[-1]) >= precedence(ch):
                output.append(stack.pop())
            stack.append(ch)
        else:
            return None
    while stack:
        operator = stack.pop()
        if operator == "(":
            return None
        output.append(operator)
    return "".join(output)


def infix_to_prefix(expression):
    if not expression.strip():
        print("Empty expression.")
        return None
    reversed_expression = expression.strip()[::-1]
    swapped = "".join("(" if ch == ")" else ")" if ch == "(" else ch
                      for ch in reversed_expression)
    postfix = to_postfix(swapped)
    if postfix is None:
        print("Invalid expression or unbalanced parentheses.")
        return None
    return postfix[::-1]


def main():
    while True:
        print("\n1. Convert infix to prefix\n2. Exit")
        choice = input("Enter choice: ").strip()
        if choice == "2":
            break
        if choice != "1":
            print("Invalid choice.")
            continue
        expression = input("Enter infix expression (single-character operands): ")
        result = infix_to_prefix(expression)
        if result is not None:
            print("Prefix:", result)


if __name__ == "__main__":
    main()
