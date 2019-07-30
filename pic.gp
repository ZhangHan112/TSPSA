reset
set term png enhanced font 'Verdana,10'
set output "runtime.png"
set xlabel "Iteration"
set ylabel "Best"
set title "TSPSA"
plot [0:100000][250:1000]'output1.dat' using 1:2  with line lw 1.5 title "" ,\
'output2.dat' using 1:2 with line lw 1.5 title "" , 