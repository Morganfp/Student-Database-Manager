/*
Author: Morgan Purcell
Date: November 22nd 2022
Purpose: A program written in C++ that uses a MySQL connector to create tables and run queries in a MySQL database. 
          It stores student data such as courses, grades, semesters, and transcript information.
*/

// Include the libraries needed
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <mysql/jdbc.h>

// Include the modules needed
#include "deleteData.cpp"
#include "transcript.cpp"
#include "listData.cpp"
#include "addData.cpp"
#include "createTables.cpp"


int main()
{
    // Declare variables to store user credentials and mysql server info
    std::string db_host;
    std::string db_port;
    std::string db_user;
    std::string db_password;
    std::string db_name;

    // Get user credentials and mysql server info
    std::cout << "Enter MySQL database hostname (or IP adress) (press enter for default):";
    getline(std::cin, db_host);
    std::cout << "Enter MySQL database port number (press enter for default):";
    getline(std::cin, db_port);
    if (db_port.length() > 0)
        db_host += ":" + db_port;
    std::cout << "Enter MySQL database name:";
    std::cin >> db_name;
    std::cout << "Enter MySQL database username:";
    std::cin >> db_user;
    std::cout << "Enter MySQL database password:";
    std::cin >> db_password;

    // Set up the client (this machine) to use mysql
    std::cout << "initializing client DB subsystem ..."; 
    std::cout.flush();
    sql::Driver * driver = sql::mysql::get_driver_instance();
    std::cout << "Done!" << std::endl;

    // Connect to the MySQL database
    try
    {
        std::cout << "Connecting to remote DB ..."; 
        std::cout.flush();
        sql::Connection* conn = driver->connect(db_host, db_user, db_password);
        conn->setSchema(db_name);

        // Call the createTables function to create the neccessary tables within the database
        createTables(conn);

        // Display a welcome screen using ANSI escape sequences for colored text
        std::cout << "\n\n\n\033[100mWelcome to the Student Data Management program! Here is a list of available commands:\033[0m\n\n" << "\033[92ma (add)\033[0m\n c: course\n g: grade\n m: semester\n s: student\n t: completed course\n\n" << "\033[92ml (list)\033[0m\n c: courses\n g: grades\n m: semesters\n s: students\n t: completed courses\n\n" << "\033[92mt (student transcript)\033[0m\n\n"  << "\033[93md (delete student)\033[0m\n\n" << "\033[91mq (quit the program)\033[0m\n\n";

        // Prompt the user to select a function or quit the program using 'q'
        std::string input;
        while(input != "q")
        {
            // Prompt for user input
            std::cout << ">>> ";
            std::cin >> input;

            // If/else blocks to call the desired function
            if(input == "a")
            {
                addFunc(conn);
            }

            else if(input ==  "l")
            {
                listFunc(conn);
            }

            else if(input == "t")
            {
                transcriptFunc(conn);
            }

            else if(input == "d")
            {
                deleteFunc(conn);
            }
        }

        // Close the MySQL connection at the end of the program
        conn->close();
    }

    // Catch and display any errors
    catch(sql::SQLException sqle)
    {
        std::cout << "Exception in SQL: " << sqle.what() << std::endl;
    }

    return 0;
}
