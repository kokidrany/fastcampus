#!/bin/sh
/bin/awk '\
	BEGIN {FS=","; print "address book"}\
	{idx=$1} {name=$2} {phone=$3} {mobile=$4} {city=$5} \
	{n += 1}\
	{print "< (" idx ")" name ">"}\
	{print " Phone Number: " phone }\
	{print " Mobile Number : " mobile }\
	{print " City : " city }\
	END {print "Total " n "address" } \
	' information.txt
	
