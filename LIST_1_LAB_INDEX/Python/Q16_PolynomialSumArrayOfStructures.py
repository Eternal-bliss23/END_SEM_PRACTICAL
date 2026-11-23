# Q16: Polynomial Sum Using an Array of Structures
# Purpose: Store each term as a Term object and add terms with equal exponents.


class Term:
    def __init__(self, coeff, exp):
        self.coeff = coeff
        self.exp = exp


def read_poly(name):
    count = int(input(f"Enter number of terms in {name}: "))
    terms = []
    for i in range(count):
        coeff = int(input("  Coefficient: "))
        exp = int(input("  Exponent: "))
        terms.append(Term(coeff, exp))
    return terms


def add(p, q):
    # Python equivalent of C dynamic memory allocation
    result = []
    for t in p + q:
        for r in result:
            if r.exp == t.exp:
                r.coeff += t.coeff
                break
        else:
            result.append(Term(t.coeff, t.exp))
    result.sort(key=lambda t: -t.exp)
    return result


def display(terms, label):
    parts = [f"{t.coeff}x^{t.exp}" for t in terms]
    print(f"{label}: " + (" + ".join(parts) if parts else "0"))


def main():
    p = read_poly("first polynomial")
    q = read_poly("second polynomial")
    display(p, "First polynomial")
    display(q, "Second polynomial")
    display(add(p, q), "Sum")


if __name__ == "__main__":
    main()
