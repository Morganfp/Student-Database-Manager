run: main.o
	g++ -o run -L ~/MYSQL/mysql-connector-c++-8.0.31-macos12-x86-64bit/lib64  main.o -l mysqlcppconn-static -lssl -lcrypto -lresolv

main.o: main.cpp
	g++ -c -Wall -ansi -pedantic -std=c++20 -I ~/MYSQL/mysql-connector-c++-8.0.31-macos12-x86-64bit/include main.cpp   