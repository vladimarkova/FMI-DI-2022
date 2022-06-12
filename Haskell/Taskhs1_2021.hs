-- minFst t1 t2 = if ((fst t1) < (fst t2)) then t1 else t2
-- getSlope ((d1, h1), (d2, h2)) = abs ((h2 - h1) / (d2 - d1))

argMin :: ([(Integer, Integer)] -> Double) -> [[(Integer, Integer)]] -> [(Integer, Integer)]
argMin f l = fst $ foldl (\t1 t2 -> if ((snd t1) < (snd t2)) then t1 else t2) ([], maximum (map f l) + 1) $ map (\e -> (e, f e)) l

maxSlope :: [(Integer, Integer)] -> Double
maxSlope track = maximum (map (\((d1, h1), (d2, h2)) -> abs ((fromIntegral (h2 - h1)) / (fromIntegral (d2 - d1)))) (zip track (tail track)))

tracks1 = [[(0, 900), (100, 910), (200, 925), (300, 905), (600, 950)], [(0, 1300), (100, 1305), (500, 1340), (800, 1360), (1000, 1320)], [(0, 800), (200, 830), (300, 845), (600, 880), (800, 830)]]

easiestTrackUnder :: Integer -> [[(Integer, Integer)]] -> [(Integer, Integer)]
easiestTrackUnder maxLen tracks = argMin maxSlope (filter (\t -> (fst (last t) - fst (head t)) < maxLen) tracks)

main = print (easiestTrackUnder 800 tracks1)
