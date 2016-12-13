unset key
set xrange [*:*]
set yrange [*:*]
splot "test0.dat" using 2:3:4 w l
replot "test0.dat" using 5:6:($7+100) w l
pause -1