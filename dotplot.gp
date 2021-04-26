set terminal png notransparent interlace truecolor enhanced nocrop font "arial,18" size 1600,1200

set title "Dotplot"
set xlabel "Séquence 1"
set ylabel "Séquence 2"
set output "dotplot.png"
plot "dotplot.dat"