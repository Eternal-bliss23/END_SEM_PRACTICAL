# Q18: Sparse Matrix Using Triplets
# Purpose: Store non-zero terms as (row, col, value) and show triplet/dense form.


def main():
    rows = int(input("Enter rows: "))
    cols = int(input("Enter columns: "))
    count = int(input("Enter number of non-zero terms: "))

    # Python equivalent of C dynamic memory allocation
    terms = []
    for i in range(count):
        print(f"Term {i + 1}:")
        r = int(input("  Row: "))
        c = int(input("  Column: "))
        v = int(input("  Value: "))
        if 0 <= r < rows and 0 <= c < cols:
            terms.append((r, c, v))
        else:
            print("  Out of range, skipped.")

    while True:
        print("\n1. Display triplets  2. Display dense matrix  0. Exit")
        choice = input("Enter choice: ").strip()
        if choice == "1":
            print("\nRow  Col  Value")
            for r, c, v in terms:
                print(f"{r:4d} {c:4d} {v:6d}")
        elif choice == "2":
            print("\nDense matrix:")
            dense = [[0] * cols for _ in range(rows)]
            for r, c, v in terms:
                dense[r][c] = v
            for row in dense:
                for value in row:
                    print(f"{value:5d}", end="")
                print()
        elif choice == "0":
            break
        else:
            print("Invalid choice.")


if __name__ == "__main__":
    main()
