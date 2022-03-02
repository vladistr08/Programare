pLenght = int(input("Introduceti lungimea lui p: "))
qLenght = int(input("Introduceti lungimea lui q: "))
rLenght = qLenght
k = int(input("Introduceti puterea pentru expresia pq^k=r^kp: "))

print(
    "\nSimbolurile cuvintelor p,q,r vor fi reprezentate cu numere din multimea {1...n}, unde n este lungimea maxima dintre cuvinte.\n")

r = "".join("a" + str(i) for i in range(1, rLenght + 1))

catRLenght = int(pLenght / rLenght)
modRLenght = pLenght % rLenght

p = "r^{}".format(catRLenght) + "_" + "".join("a" + str(i)
                                              for i in range(1, modRLenght + 1))

q = [0 for i in range(0, qLenght)]
i = modRLenght + 1
counter = 0
while i <= qLenght and counter < qLenght:
    q[counter] = str(i)
    i += 1
    counter += 1
i = 1
while counter < qLenght:
    q[counter] = str(i)
    i += 1
    counter += 1
q = "".join("a" + q[i] for i in range(0, len(q)))

print("p is: {}".format(p) + " and the size {}".format(pLenght))
print("q is: {}".format(q) + " and the size {}".format(qLenght))
print("r is: {}".format(r) + " and the size {}".format(rLenght))
