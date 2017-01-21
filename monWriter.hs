import Control.Monad.Writer


type Shopping = Writer ((Sum Integer, [String])) ()

purchase :: String -> Integer -> Shopping
purchase item cost = tell (Sum cost, [item])
shopping1 :: Shopping
shopping1 = do
  purchase "Jeans"   19200
  purchase "Water"     180
  purchase "Lettuce"   328


total :: Shopping -> Integer
total = getSum . fst . execWriter

items :: Shopping -> [String]
items = snd . execWriter

evenOnly :: [a] -> [a]
evenOnly = foldl  (\xs x -> x : (tail xs)) []
