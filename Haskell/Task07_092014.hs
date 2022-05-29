lis = [11, 12, 13]
dLis = [x * 2 | x <- lis]

removeOne e [] = []
removeOne e (x:xs) = if x == e
                        then xs
                        else x:(removeOne e xs)

permutations [] = [[]]
permutations l = concat [[y:p | p <- permutations (removeOne y l)] | y <- l]

main = print (permutations [1, 2, 3])