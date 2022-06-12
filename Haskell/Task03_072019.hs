recommended basket bestFit products = 
    filter 
    (\product -> findPrice product <= basketCost)
    (map bestFit basket)
        where 
            findPrice product = snd $ head $ filter (\(code, price) -> code == product) products
            basketCost = sum $ map findPrice basket