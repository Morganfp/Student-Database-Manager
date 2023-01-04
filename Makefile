run: main.o
	g++ -o run -L ~/MYSQL/mysql-connector-c++-8.0.31-macos12-x86-64bit/lib64  main.o -l mysqlcppconn-static -lssl -lcrypto -lresolv

main.o: main.cpp deleteData.cpp transcript.cpp listData.cpp addData.cpp createTables.cpp
	g++ -c -Wall -ansi -pedantic -std=c++20 -I ~/MYSQL/mysql-connector-c++-8.0.31-macos12-x86-64bit/include main.cpp

deleteData.o: deleteData.cpp
	g++ -c -Wall -ansi -pedantic -std=c++20 -I ~/MYSQL/mysql-connector-c++-8.0.31-macos12-x86-64bit/include deleteData.cpp

transcript.o: transcript.cpp
	g++ -c -Wall -ansi -pedantic -std=c++20 -I ~/MYSQL/mysql-connector-c++-8.0.31-macos12-x86-64bit/include transcript.cpp

listData.o: listData.cpp
	g++ -c -Wall -ansi -pedantic -std=c++20 -I ~/MYSQL/mysql-connector-c++-8.0.31-macos12-x86-64bit/include listData.cpp

addData.o: addData.cpp
	g++ -c -Wall -ansi -pedantic -std=c++20 -I ~/MYSQL/mysql-connector-c++-8.0.31-macos12-x86-64bit/include addData.cpp

createTables.o: createTables.cpp
	g++ -c -Wall -ansi -pedantic -std=c++20 -I ~/MYSQL/mysql-connector-c++-8.0.31-macos12-x86-64bit/include createTables.cpp
