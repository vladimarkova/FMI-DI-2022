sum1 l = if length l == 0
            then 0 
            else (head l) + sum1 (tail l) 

sum2 l 
    | length l == 0 = 0
    | otherwise = (head l) + sum2 (tail l)

sum3 [] = 0
sum3 (x:xs) = x + sum3 xs

main = print (sum3 [11, 12, 13])