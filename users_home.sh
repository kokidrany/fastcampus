#!/bin/sh
/bin/awk ' \
BEGIN {FS=":"} \
{print $1 " home at " $6 }' \
/etc/passwd
