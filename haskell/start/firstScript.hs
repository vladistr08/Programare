doubleMe :: Num a => a -> a
doubleMe x = x + x

doubleUs :: Num a => a -> a -> a
doubleUs x y = doubleMe x + doubleMe y

doubleSmallNumber :: (Ord a, Num a) => a -> a
doubleSmallNumber x = if x >= 100 then x else doubleMe x

concatList :: [a] -> [a] -> [a]
concatList a b = a ++ b

pushFront :: a -> [a] -> [a]
pushFront x a = x : a

pushBack :: a -> [a] -> [a]
pushBack x a = a ++ [x]

getValue :: [a] -> Int -> a
getValue a x = a !! x

replaceValue :: Integral a => [a] -> [a]
replaceValue a = [if even x then x else x * 2 | x <- a]

returnFirst :: (a, b) -> a
returnFirst (a, b) = a

factorial :: (Integral a) => a -> a
factorial 0 = 1
factorial x = x * factorial (x - 1)

addVectors :: (Num a) => (a, a) -> (a, a) -> (a, a)
addVectors a b = (fst a + fst b, snd a + snd b)

sumPair :: (Num a) => [(a, a)] -> [a]
sumPair xs = [a + b | (a, b) <- xs]