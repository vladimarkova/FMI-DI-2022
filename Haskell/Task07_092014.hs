lis = [11, 12, 13]
dLis = [x * 2 | x <- lis]

mySum x y = x + y

removeOne e [] = []
removeOne e (x:xs) = if x == e
                        then xs
                        else x:(removeOne e xs)

permutations [] = [[]]
permutations l = concat [[y:p | p <- permutations (removeOne y l)] | y <- l]

main = print (mySum 2 3)