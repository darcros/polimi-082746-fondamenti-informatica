#!/bin/bash

# sposta la workdir nella cartella dove sta questo script e compila il programma
cd "$(dirname "$0")"
make build

# array dei numeri da provare per misurare il tempo
numeri=(
     100000
    1000000
    5000000
   10000000
   25000000
   50000000
  100000000
  200000000
  300000000
)

for n in ${numeri[@]}; do
  output=$(./build/out $n)
  tempo=$(echo "$output" | grep "tempo totale" | cut -f 2 -d ":")
  coppie=$(echo "$output" | grep "coppie trovate")
  printf "%10s: %20s %20s\n" "$n" "$coppie" "$tempo"
done

# Con il mio PC con Intel Core i3-3240T CPU @ 2.90GHz
#
#    100000:    13 coppie trovate     0.006612 secondi
#   1000000:    40 coppie trovate     0.159447 secondi
#   5000000:    71 coppie trovate     1.263099 secondi
#  10000000:   100 coppie trovate     2.776030 secondi
#  25000000:   148 coppie trovate     8.614013 secondi
#  50000000:   189 coppie trovate    16.452210 secondi
# 100000000:   231 coppie trovate    32.957926 secondi
# 200000000:   300 coppie trovate    81.357181 secondi
# 300000000:   352 coppie trovate   113.590962 secondi
