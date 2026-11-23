# Q15: Sum of Polynomials Using Structures
# Purpose: Use a Poly class (coefficients + degree) to add two polynomials.


class Poly:
    def __init__(self, coeff, deg):
        self.coeff = coeff
        self.deg = deg

    def display(self, label):
        terms = []
        for power in range(self.deg, -1, -1):
            if self.coeff[power] != 0:
                terms.append(f"{self.coeff[power]}x^{power}")
        print(f"{label}: " + (" + ".join(terms) if terms else "0"))


def read_poly(name):
    deg = int(input(f"Enter degree of {name}: "))
    coeff = []
    for power in range(deg + 1):
        coeff.append(int(input(f"Coefficient of x^{power}: ")))
    return Poly(coeff, deg)


def add(p, q):
    deg = max(p.deg, q.deg)
    coeff = [0] * (deg + 1)
    for i in range(deg + 1):
        if i <= p.deg:
            coeff[i] += p.coeff[i]
        if i <= q.deg:
            coeff[i] += q.coeff[i]
    return Poly(coeff, deg)


def main():
    p = read_poly("first polynomial")
    q = read_poly("second polynomial")
    p.display("First polynomial")
    q.display("Second polynomial")
    add(p, q).display("Sum")


if __name__ == "__main__":
    main()
