f(x) = x
set grid
set logscale x 2
#set logscale y 10
set xlabel 'n'
set ylabel 'time/n [s]'
set format x "2^{%L}"
#set format y "10^{%L}"
set style data linespoints
set key top left box
set title "Finden des gewichteten q-Perzentils (Integer)"
set output "random.png"
set term png size 1200,600
plot [2**8:] \
     'random.data' using 1:($2/f($1)) title 'Durch Sortieren' , \
     'random.data' using 1:($3/f($1)) title 'Ihr Algorithmus' 
