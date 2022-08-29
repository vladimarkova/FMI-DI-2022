-- (\l -> (fromIntegral (foldl (+) 0 l)) / (fromIntegral (length l))) [10, 20, 30, 40]

-- avg l = (foldl (+) 0 l) / (length l)

-- \(x, y, z) -> y

recommender pl = \(pA, pT, pD) ->
    let avgDuration artist = (\l -> (fromIntegral (foldl (+) 0 l)) / (fromIntegral (length l))) (map (\(a, t, d) -> d) (filter (\(a, t, d) -> a == artist)  pl))
        option1 = filter (\(a, t, d) -> a == pA && d > pD) pl
        option2 = filter (\(a, t, d) -> avgDuration a < avgDuration pA) pl
    in if not (null option1) then ((\(x, y, z) -> y) $ head option1)
        else if not (null option2) then ((\(x, y, z) -> y) $ last option2)
            else if not (null (filter (\(a, t, d) -> d > pD) pl)) 
                    then ((\(x, y, z) -> y) $ head (filter (\(a, t, d) -> d > pD) pl))
                    else pT

rf = recommender [("Mozart","The Marriage of Figaro Overture",270), 
    ("Gershwin","Summertime", 300), 
    ("Queen","Bohemian Rhapsody",355), 
    ("Gershwin","Rhapsody in Blue",1100)]

main = print (rf ("Mozart","The Marriage of Figaro Overture",270))

-- rf ("Gershwin", "Summertime", 300)
-- rf ("Gershwin", "Rhapsody in Blue", 1100)
