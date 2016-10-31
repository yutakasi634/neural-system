unset key
set xrange [0:5]
set yrange [0:2]
plot for [i=2:25] "test0.dat" using 1:i w lp

pause -1