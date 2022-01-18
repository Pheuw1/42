ifconfig -a link | grep "ether "| sed -e 's/ether //' | sed -e 's/ //' | cut -c 2- 
