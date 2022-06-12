data Tree a = EmptyTree | Node {
    value :: a,
    left :: Tree a,
    right :: Tree a
} deriving (Show,Read)

treeWords :: (Tree Char) -> [[Char]]
treeWords EmptyTree = []
treeWords (Node v EmptyTree EmptyTree) = [[v]]
treeWords (Node v l r) = map (v:) (wl ++ wr)
    where wl = treeWords l 
          wr = treeWords r

tree1 = (Node 'a' (Node 'b' EmptyTree EmptyTree) (Node 'c' EmptyTree EmptyTree))

-- main = print (treeWords tree1)

quickSort [] = []

quickSort (x:xs) = (quickSort lesser) ++ [x] ++ (quickSort greater)
    where
        lesser = filter (\e -> e  < x) xs
        greater = filter (\e -> e > x) xs

main = print (quickSort [3, 1, 20, 6, 13])