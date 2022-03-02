def cmmdc(a, b):
    while b != 0:
        r = a % b
        a = b
        b = r
    return a


def func(x):
    x = int(x)
    if x == 1:
        return 1
    for d in range(2, x):
        power = 0
        while x % d == 0:
            power += 1
            x /= d
        if power != 0:
            return (d ** power - d ** (power - 1)) * func(x)


x = int(input("introduceti baza x: "))
p = int(input("introduceti exponentul p: "))
n = int(input("introduceti modulo n: "))

print("Indicatorul lui Euler este: {}".format(int(func(n))))

div = int(cmmdc(x, n))
x /= div
n /= div

rest = div * (x ** (p % int(func(n))) % n)
print("Restul este: {}".format(int(rest)))
# 2^2021 % 1000 -> 400 si 150 si ceva
