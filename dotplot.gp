set terminal png notransparent interlace truecolor enhanced nocrop font "arial,18" size 1600,1200

set title "Dotplot"
unset key
set xrange [-1:]
set yrange [-1:]
set xlabel "Séquence 1"
set ylabel "Séquence 2"
set output "dotplot.png"
set title "Dotplot"
plot "dotplot.dat" with points lt 8 pt 5 ps 2.5
