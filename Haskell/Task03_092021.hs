-- (foldl1 (&&) [False, False ..]) // infinite evaluation
-- (foldr1 (&&) [False, False ..]) // False
-- (foldr1 (&&) [True, True ..]) // infinite evaluation
-- (foldl1 (&&) [True, True ..]) // infinite evaluation
-- (filter (`elem`[10..20]) [1,5,10,100,20,15]) // [10, 20, 15]
-- (filter (\x -> elem x [10..20]) [1,5,10,100,20,15]) // [10, 20, 15]
-- (negate $ max 10 20) <----> (negate (max 10 20)) // -20
-- (take 4 [1,3..]) // [1, 3, 5, 7]
-- (:[]) [] // [[]]
-- (map ($ 0) (map (+) [1..5])) // [1, 2, 3, 4, 5]

-- g :: [[Num]] -> [[Num]]

import Data.Typeable;

f1 x = 2 * x

f l = [ x+y | x <- l, y <- l]

-- g :: [[(a :: Num)]] -> [[(a :: Num)]]

g :: Num a => [[a]] -> [[a]]
g ([]:_) = []
g x = (map head x) : g (map tail x)

main = print (typeOf g)