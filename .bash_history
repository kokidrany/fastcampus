ifconfig 
shutdown -P
shutdown -c
init 5
sudo init 5
su - root
vi hello.c
gcc hello.c -o hello
ls -l
hello
./hello
gcc -v
clear
ls -l
cpp hello.c > hello.i
ls -l
vi hello.i
ls -t
cpp hello.c > hello1.i
ls -ltr
gcc -S hello.i
ls -ltr
vi hello.s
gcc -S hello1.i 
ls -ltr
vi hello1.s
diff hello.s hello1.s 
cat hello.i
ls -tr
cat hello.s
clear
ls
as -o hello.o hello.s
ls
cat hello.o
PuTTYPuTTYPuTTYclear
clear
ls -ltr
as -o hello1.o hello1.s
ls -l
diff hello.o hello1.o
readelf -h hello.o
readelf -h hello1.o
clear
gcc -v -save-temp -o hello hello.c
gcc -v --save-temp -o hello hello.c
ls
ls -l
gcc -Wall hello.c -o hello
gcc --Wall hello.c -o hello
gcc -Wall -E hello.c > hello.i
ls -ltr
gcc -S hello.c > hello.s
ls -ltr
gcc -C hello.c
ls -ltr
./a.out
mkdir c
cp hello.c c
cd c
ls -ltr
gcc --save-temp hello.c
ls -ltr
./a.out
gcc -Wall hello.c -o hello -lpthread
ls -ltr
./hello
gcc -Wall -v hello.c -o hello
ls -ltr
vi hello.c
gcc -Wall -funsigned-char hello.c -o hello
./hello
gcc -Wall hello.c -o hello
./hello
vi hello.c
gcc -Wall -DMY_MACRO hello.c -o hello
./hello
vi opt_file
ls -l
gcc hello.c @opt_file
ls -ltr
date
clear
ls
gcc -g hello.c -o hello
./hello
ls -l
ulimit
ulimit -a
ulimit -c 0
ulimit -a
ulimit -c unlimited
ulimit -a
ulimit -c
ulimit -a
ulimit -c 100
ls
cd ..
ls
vi gdb_test1.c
ls
clear
ls -ltr
gcc -g gdb_test1.c -o gdb_test1
ls -ltr
vi gdb_test1.c 
ls -ltr
gcc -g gdb_test1.c -o gdb_test1
vi gdb_test1.c 
gcc -g gdb_test1.c -o gdb_test1
ls -ltr
./gdb_test1
ls /var/crash/
ulimit -a
ulimit -c 100
sudo ulimit -c 100
ulimit -a
id
ls -l
clear
vi main.c
vi func1.c
cp func1.c func2.c
vi func2.c
gcc -g main.c func1.c func2.c -o gdb_test2
ls -ltr
./gdb_test2
gdb gdb_test2
id
ls
clear
pwd
ls
vi backtrace_example.c
clear
ls -ltr | tail 2
ls -ltr | tail -2
gcc -g backtrace_example.c  -o backtrace_example -rdynamic
vi backtrace_example.c 
clear
gcc -g backtrace_example.c  -o backtrace_example -rdynamic
ls -ltr | tail -5
./backtrace_example 
vi test.c
clear
gcc -g -rdynamic test.c -o test
vi test.c
gcc -g -rdynamic test.c -o test
ls -ltr | tail -5
./test
clear
gdb test
addr2line
which addr2line
addr2line -e backtrace_example 0x400942
addr2line -e backtrace_example 0x4008bf
make
exit
ls
vi shtest5.sh
clear
vi mem_usage.sh
ls
cd c
ls -l
vi  create_example.c
ls -ltr
clear
ls
gcc -c create_example.c -o create_example
ls -ltr
./create_example
gcc -g create_example.c -o create_example
ls -l
./create_example 
ls -ltr
chmod +x shtest5.sh
./shtest5.sh
./shtest5.sh 1
./shtest5.sh fork
./shtest5.sh knife
./shtest5.sh knif
./shtest5.sh kni
./shtest5.sh
./shtest5.sh fork
clear
ls -ltr
cat shtest5.sh
./shtest5.sh
./shtest5.sh fork
./shtest5.sh kinife
./shtest5.sh knife
clear
ls -ltr
./shtest5.sh
clear
./shtest5.sh
clear
./shtest5.sh
clear
./shtest5.sh
clear
./shtest5.sh
clear
./shtest5.sh
clear
./shtest5.sh
clear
ls
vi information.txt
cat information.txt 
vi awk_test.sh
clear
ls 
chmod +x *.sh
ls -ltr
./awk_test.sh 
vlear
clear
vi users_home.sh
chmod +x *.sh
ls
./users_home.sh 
ls -l /etc/passwd
clear
cat users_home.sh 
vi users_home.sh 
./users_home.sh 
vi users_home.sh 
./users_home.sh 
vi users_home.sh 
./users_home.sh 
vi ./users_home.sh 
./users_home.sh 
clear
awk -F: {print $1 "home at" $6 } /etc/passwd
awk -F: '{print $1 "home at" $6 }' /etc/passwd
clear
awk -F, '{print $2 "\t" $4}' information.txt 
awk '{++cnt} END {print "Count= " cnt}' information.txt 
awk '{++cnt} END {print "Count=", cnt}' information.txt 
awk '{++cnt} END {print "Count=" cnt}' information.txt 
awk '{++cnt} END {print "Count=", cnt}' information.txt 
clear
cat information.txt 
sed 's/Won/Woo/g' information.txt 
sed 's/Won/Woo/' information.txt 
sed 's/051/052/1' information.txt 
sed 's/23/052/1' information.txt 
sed '2d' information.txt 
sed '/Won/d' information.txt 
sed '2i\2,New,00-000-0000,000-000-000,Korea'
sed '2i\2,New,00-000-0000,000-000-000,Korea' information.txt 
sed '2i 2,New,00-000-0000,000-000-000,Korea' information.txt 
sed '2i/ 2,New,00-000-0000,000-000-000,Korea' information.txt 
ls -ltr
chmod +x *.sh
./mem_usage.sh 
head -10 /proc/meminfo 
./mem_usage.sh 
clear
ls
cd c
ls
vi create_example.c 
cd /tmp
ls -ltr
clear
cd 
ls
cd c
ls
clear
vi aeecss_example.c
clear
ls
mv aeecss_example.c access_example.c
ls
gcc -g access_example.c -o access_example
ls -ltr
./access_example 
exit
cd c
vi stat_example.c
ls -ltr
vi stat_example.c 
vi chmod_example.c
vi chown_example.c
exit
cd c
ls -ltr | heat -2
ls -ltr | heat 2
ls -ltr | head -2
ls -ltr | tail -2
gcc -g stat_example.c -o stat_example
ls -ltr | tail -5
./stat
./stat_example 
./stat_example access_example
gcc -g stat_example.c -o stat_example
./stat_example access_example
gcc -g stat_example.c -o stat_example
./stat_example access_example
gcc -g stat_example.c -o stat_example
./stat_example access_example
gcc -g stat_example.c -o stat_example
./stat_example access_example
gcc -g stat_example.c -o stat_example
./stat_example access_example
gcc -g stat_example.c -o stat_example
./stat_example access_example
gcc -g stat_example.c -o stat_example
./stat_example access_example
gcc -g stat_example.c -o stat_example
./stat_example access_example
gcc -g stat_example.c -o stat_example
./stat_example access_example
clear
gcc -g stat_example.c -o stat_example
./stat_example access_example
./stat_example .
man chmod
man 2 chmod
man 3 chmod
clear
ls ltr
ll
ls -ltr | tail
gcc -g chmod_example.c -o chmod_example
clear
gcc -g chmod_example.c -o chmod_example
ls -ltr
./chmod_example 
ls -tlr
gcc -g chmod_example.c -o chmod_example
i
gcc -g chmod_example.c -o chmod_example
./chmod_example 
ls -ltr
gcc -g chmod_example.c -o chmod_example
./chmod_example 
ls -ltr a.out
clear
ls -ltr | tail -3
gcc -g chown_example.c -o chown_example
clear
gcc -g chown_example.c -o chown_example
ls -ltr a.out
./chown_example 
su - root
exit
