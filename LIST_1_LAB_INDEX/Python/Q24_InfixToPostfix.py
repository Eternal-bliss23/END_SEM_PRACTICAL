PRECEDENCE = {"+": 1, "-": 1, "*": 2, "/": 2, "^": 3}


def precedence(operator):
    return PRECEDENCE.get(operator, 0)


def infix_to_postfix(expression):
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
                print("Unmatched parenthesis.")
                return None
            stack.pop()
        elif ch in PRECEDENCE:
            while stack and stack[-1] != "(":
                top = stack[-1]
                if precedence(top) > precedence(ch) or (
                    precedence(top) == precedence(ch) and ch != "^"
                ):
                    output.append(stack.pop())
                else:
                    break
            stack.append(ch)
        else:
            print("Invalid character:", ch)
            return None
    while stack:
        operator = stack.pop()
        if operator == "(":
            print("Unmatched parenthesis.")
            return None
        output.append(operator)
    return "".join(output)


def main():
    while True:
        print("\n1. Convert infix to postfix\n2. Exit")
        choice = input("Enter choice: ").strip()
        if choice == "2":
            break
        if choice != "1":
            print("Invalid choice.")
            continue
        expression = input("Enter infix expression (single-character operands): ")
        result = infix_to_postfix(expression)
        if result is not None:
            print("Postfix:", result)


if __name__ == "__main__":
    main()
