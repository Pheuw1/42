cat /etc/passwd | grep -v '#' | awk 'NR%2==0' | awk '{print $1}' FS=:| rev | sort -r | awk "NR>=$FT_LINE1 && NR<=$FT_LINE2" | tr '\n' ' ' | sed 's/ $/./' | sed 's/ /, /g' | tr -d '\n'
