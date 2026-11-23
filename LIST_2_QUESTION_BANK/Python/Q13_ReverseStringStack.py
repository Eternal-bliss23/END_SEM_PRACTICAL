# Q13 - Reverse a String using a Stack
# Purpose: Push each character onto a stack, then pop to print it reversed.

def main():
    text = input("Enter a string: ")

    stack = []
    for ch in text:
        stack.append(ch)
    print("Stack (bottom to top):", stack)

    reversed_text = ""
    while len(stack) > 0:
        reversed_text += stack.pop()

    print("Original string:", text)
    print("Reversed string:", reversed_text)

if __name__ == "__main__":
    main()
