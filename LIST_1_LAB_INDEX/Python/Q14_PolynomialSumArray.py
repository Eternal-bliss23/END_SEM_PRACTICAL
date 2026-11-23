# Q14: Sum of Polynomials Using Arrays
# Purpose: Keep coefficients indexed by power in lists, then add two lists.


def read_poly(name):
    deg = int(input(f"Enter degree of {name}: "))
    coeff = [0] * (deg + 1)
    for power in range(deg + 1):
        coeff[power] = int(input(f"Coefficient of x^{power}: "))
    return coeff


def display(coeff, label):
    terms = []
    for power in range(len(coeff) - 1, -1, -1):
        if coeff[power] != 0:
            terms.append(f"{coeff[power]}x^{power}")
    print(f"{label}: " + (" + ".join(terms) if terms else "0"))


def main():
    p = read_poly("first polynomial")
    q = read_poly("second polynomial")

    size = max(len(p), len(q))
    result = [0] * size
    for i in range(size):
        if i < len(p):
            result[i] += p[i]
        if i < len(q):
            result[i] += q[i]

    display(p, "First polynomial")
    display(q, "Second polynomial")
    display(result, "Sum")


if __name__ == "__main__":
    main()
