// Include the libraries needed
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <mysql/jdbc.h>


// Function to display tables within the database
void listFunc(sql::Connection* conn)
{
    // Prompt the user to select the table they want to print
    std::string input;
    std::cin >> input;

    // List courses
    if(input == "c")
    {
        try
        {  
            // Initialize a SQL prepared statement variable, pstmt, to hold the prepared statement for the current connection
            // Pass the query to print the table contents as the prepareStatement argument
            sql::PreparedStatement* pstmt = conn->prepareStatement("SELECT * FROM Courses_T; ");
            // Initialize a ResultSet variable, res, to hold the executed query
            sql::ResultSet* res = pstmt->executeQuery();

            // Print the table values
            std::cout << "\nCourses Table\n";
            // While res has a next value
            while(res->next())
            {
                // Get the value and print it to the screen
                std::cout << res->getString(1) << "\t";
                std::cout << res->getInt(2) << "\t";
                std::cout << res->getString(3) << "\t";
                std::cout << res->getInt(4) << "\t";
                std::cout << "\n";
            }
            std::cout << "\n";
        }

        // Catch any SQL Exceptions
        catch (sql::SQLException sqle)
        {
            // Display the exception/error which occured
            std::cout << "Exception in SQL: " << sqle.what() << std::endl;
        }
    }

    // List grades
    if(input == "g")
    {
        try
        {   
            // Initialize a SQL prepared statement variable, pstmt, to hold the prepared statement for the current connection
            // Pass the query to print the table contents as the prepareStatement argument
            sql::PreparedStatement* pstmt = conn->prepareStatement("SELECT * FROM Grades_T; ");
            // Initialize a ResultSet variable, res, to hold the executed query
            sql::ResultSet* res = pstmt->executeQuery();

            // Print the table values
            std::cout << "\nGrades Table\n";
            // While res has a next value
            while(res->next())
            {
                // Get the value and print it to the screen
                std::cout << res->getString(1) << "\t";
                std::cout << res->getDouble(2) << "\t";
                std::cout << "\n";
            }
            std::cout << "\n";
        }

        // Catch any SQL Exceptions
        catch (sql::SQLException sqle)
        {
            // Display the exception/error which occured
            std::cout << "Exception in SQL: " << sqle.what() << std::endl;
        }
    }

    // List semesters
    if(input == "m")
    {
        try
        {   
            // Initialize a SQL prepared statement variable, pstmt, to hold the prepared statement for the current connection
            // Pass the query to print the table contents as the prepareStatement argument
            sql::PreparedStatement* pstmt = conn->prepareStatement("SELECT * FROM Semesters_T; ");
            // Initialize a ResultSet variable, res, to hold the executed query
            sql::ResultSet* res = pstmt->executeQuery();

            // Print the table values
            std::cout << "\nSemesters Table\n";
            // While res has a next value
            while(res->next())
            {
                // Get the value and print it to the screen
                std::cout << res->getString(1) << "\t";
                std::cout << res->getInt(2) << "\t";
                std::cout << res->getString(3) << "\t";
                std::cout << "\n";
            }

            std::cout << "\n";
        }

        // Catch any SQL Exceptions
        catch (sql::SQLException sqle)
        {
            // Display the exception/error which occured
            std::cout << "Exception in SQL: " << sqle.what() << std::endl;
        }
    }

    // List students
    if(input == "s")
    {
        try
        {   
            // Initialize a SQL prepared statement variable, pstmt, to hold the prepared statement for the current connection
            // Pass the query to print the table contents as the prepareStatement argument
            sql::PreparedStatement* pstmt = conn->prepareStatement("SELECT * FROM Students_T; ");
            // Initialize a ResultSet variable, res, to hold the executed query
            sql::ResultSet* res = pstmt->executeQuery();

            // Print the table values
            std::cout << "\nStudents Table\n";
            // While res has a next value
            while(res->next())
            {
                // Get the value and print it to the screen
                std::cout << res->getString(1) << "\t";
                std::cout << res->getString(2) << "\t";
                std::cout << res->getString(3) << "\t";
                std::cout << "\n";
            }

            std::cout << "\n";
        }

        // Catch any SQL Exceptions
        catch (sql::SQLException sqle)
        {
            // Display the exception/error which occured
            std::cout << "Exception in SQL: " << sqle.what() << std::endl;
        }
    }

    // List completed courses
    if(input == "t")
    {
        try
        {   
            // Initialize a SQL prepared statement variable, pstmt, to hold the prepared statement for the current connection
            // Pass the query to print the table contents as the prepareStatement argument
            sql::PreparedStatement* pstmt = conn->prepareStatement("SELECT * FROM Completed_Courses_T; ");
            // Initialize a ResultSet variable, res, to hold the executed query
            sql::ResultSet* res = pstmt->executeQuery();

            // Print the table values
            std::cout << "\nCompleted Courses Table\n";
            // While res has a next value
            while(res->next())
            {
                // Get the value and print it to the screen
                std::cout << res->getString(1) << "\t";
                std::cout << res->getString(2) << "\t";
                std::cout << res->getString(3) << "\t";
                std::cout << res->getInt(4) << "\t";
                std::cout << res->getString(5) << "\t";
                std::cout << res->getString(6) << "\t";
                std::cout << "\n";
            }

            std::cout << "\n";
        }

        // Catch any SQL Exceptions
        catch (sql::SQLException sqle)
        {
            // Display the exception/error which occured
            std::cout << "Exception in SQL: " << sqle.what() << std::endl;
        }
    }
}