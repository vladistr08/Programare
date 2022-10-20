lucky :: (Integral a) => a -> String
lucky 7 = "Lucky number!"
lucky x = "Out of luck!"

factorial :: (Integral a) => a -> a
factorial 0 = 1
factorial n = n * factorial(n - 1)