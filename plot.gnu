# Fitting a plot using the full data set, and a subset.
# set terminal postscript enhanced
set grid
set style line 1 lc rgb "black" lt 1 lw 23	
set arrow from 2.27,-0.4 to 2.27,-2.0 dt '-' nohead

# set terminal eps enhanced
# set output 'quadratic.eps'
set terminal pdf
set output 'graph.pdf'
set xtics out; set mxtics; set ytics out; set mytics
set title ""
set xlabel "x"
set ylabel "u(x)"

# set logscale y 10
# set logscale x 10
# set parametric

# plot "rk45.dat" using 1:4 with lines title "{/Symbol D}{/Symbol t} Plot" 
plot "dataFiles/results_100.dat" using 1:2 with lines title "t=100", \
"dataFiles/results_150.dat" using 1:2 with lines title "t=150", \
"dataFiles/results_200.dat" using 1:2 with lines title "t=200", \
"dataFiles/results_250.dat" using 1:2 with lines title "t=250", \
"dataFiles/results_300.dat" using 1:2 with lines title "t=300", \
"dataFiles/results_350.dat" using 1:2 with lines title "t=350", \
"dataFiles/results_400.dat" using 1:2 with lines title "t=400", \
"dataFiles/results_450.dat" using 1:2 with lines title "t=450", \
"dataFiles/results_500.dat" using 1:2 with lines title "t=500", \
"dataFiles/results_600.dat" using 1:2 with lines title "t=550", \
"dataFiles/results_650.dat" using 1:2 with lines title "t=650", \
"dataFiles/results_700.dat" using 1:2 with lines title "t=700", \
"dataFiles/results_750.dat" using 1:2 with lines title "t=750", \
"dataFiles/results_800.dat" using 1:2 with lines title "t=800", \
"dataFiles/results_850.dat" using 1:2 with lines title "t=850", \
"dataFiles/results_900.dat" using 1:2 with lines title "t=900", \
"dataFiles/results_950.dat" using 1:2 with lines title "t=950", \
"dataFiles/results_1000.dat" using 1:2 with lines title "t=1000", 
