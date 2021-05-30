#!/bin/sh
echo "argument number is $#"
echo "the argument is $*"
echo "the PID $$"
top &
echo "background pid $!"
ls
echo "result $?"

