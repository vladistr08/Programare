import time
from typing import Counter
start_time = time.time()


def StringCompare(a, b):
    counter = 0
    # we check if a and b have same length or not
    if len(a) == len(b):
      # we go over each letter in a, and check if that letter equals the letter in b
        for i in range(len(a)):
            if a[i] == b[i]:
                counter += 1
        if counter == len(a):
            return True
    return False


# set a to the string "abcde" repeated 100.000 times
a = 100000 * "abcde"
# set b to the string "abcxde" repeated 100.000 times
b = 100000 * "abcde"
print(StringCompare(a, b))
print("This compuation took %s seconds" % (time.time() - start_time))
