#!/bin/sh
total=`cat /proc/meminfo | grep MemTotal | /bin/awk '{print $2}'`
echo $total
free=`cat /proc/meminfo | grep MemFree | /bin/awk '{print $2}'`
echo $free
use=`expr $total - $free`
echo $use
echo "Mem Usage: $((use *100 / total)) %"
