import Data.List

func :: String -> String
func s
    | length s <= 10 = s
    | otherwise = [head s] ++ show (length s - 2) ++ [last s]


main :: IO ()
main = do
    contents <- getContents
    let inp = words contents
        a = tail inp
    putStrLn $ intercalate "\n" $ map func a

