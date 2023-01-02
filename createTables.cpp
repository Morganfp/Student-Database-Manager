// Include the libraries needed
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <mysql/jdbc.h>


// Function to create tables within the MySQL database
void createTables(sql::Connection* conn)
{
    try
    {   
        std::cout << "Creating tables ...";
        std::cout.flush();

        // Initialize strings to hold the MySQL queries that create tables and assign primary keys
        std::string courses =
        "CREATE TABLE IF NOT EXISTS Courses_T (prefix varchar(10), number int, title varchar(20), credits int, PRIMARY KEY (number, title)); ";

        std::string grades =
        "CREATE TABLE IF NOT EXISTS Grades_T (type varchar(5), point_value double, PRIMARY KEY (type)); ";

        std::string semesters =
        "CREATE TABLE IF NOT EXISTS Semesters_T (code varchar(5), year int, description varchar(10), PRIMARY KEY (code)); ";

        std::string students =
        "CREATE TABLE IF NOT EXISTS Students_T (last_name varchar(20), first_name varchar(20), phone varchar(20), PRIMARY KEY (last_name, first_name)); ";

        std::string taken =
        "CREATE TABLE IF NOT EXISTS Completed_Courses_T (last_name varchar(20), first_name varchar(20), course_prefix varchar(5), course_number int, grade varchar(5), semester varchar(5), PRIMARY KEY (last_name, first_name, course_number, semester)); ";

        // Call the createStatement function on the current connection and save the result to a sql statement variable stmt
        sql::Statement* stmt = conn->createStatement();
        // Execute the queries
        stmt->execute(courses);
        stmt->execute(grades);
        stmt->execute(semesters);
        stmt->execute(students);
        stmt->execute(taken);

        std::cout << "Done!" << std::endl;
    }

    // Catch any SQL Exceptions
    catch (sql::SQLException sqle)
    {
        // Display the exception/error which occured
        std::cout << "Exception in SQL: " << sqle.what() << std::endl;
    }
}