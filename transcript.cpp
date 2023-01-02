// Include the libraries needed
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <mysql/jdbc.h>


// Function to display a students transcript
void transcriptFunc(sql::Connection* conn)
{
    // Prompt the user for a student 
    std::string last_name;
    std::string first_name;
    std::cout << "Enter the students last name followed by first name: ";
    std::cin >> last_name >> first_name;

    try
        {   
            // Initialize a SQL prepared statement variable, pstmt, to hold the prepared statement for the current connection
            // Pass the query to return a transcript for the desired student as the prepareStatement argument
            sql::PreparedStatement* pstmt = conn->prepareStatement("SELECT course_prefix, course_number, grade, semester FROM Completed_Courses_T, Semesters_T WHERE last_name = (?) AND first_name = (?) AND Semesters_T.code = Completed_Courses_T.semester ORDER BY year; ");
            // Set the values for the query
            pstmt->setString(1, last_name);
            pstmt->setString(2, first_name);
            // Initialize a ResultSet variable, res, to hold the executed query
            sql::ResultSet* res = pstmt->executeQuery();

            // Print the returned values
            std::cout << "\n\nTranscript for " << last_name << ", " << first_name << "\n"; 
            // While res has a next value
            while(res->next())
            {
                // Get the value and print it to the screen
                std::cout << res->getString(1) << "\t";
                std::cout << res->getString(2) << "\t";
                std::cout << res->getString(3) << "\t";
                std::cout << res->getString(4) << "\t";
                std::cout << "\n";
            }

            // Update the SQL prepared statement variable, pstmt by passing the query to return the number of credits taken by the student as the prepareStatement argument
            pstmt = conn->prepareStatement("SELECT SUM(credits) FROM Courses_T, Completed_Courses_T WHERE last_name = (?) AND first_name = (?) AND Courses_T.prefix = Completed_Courses_T.course_prefix AND Courses_T.number = Completed_Courses_T.course_number; ");
            // Set the values for the query
            pstmt->setString(1, last_name);
            pstmt->setString(2, first_name);
            // Update the ResultSet variable, res, to hold the executed query
            res = pstmt->executeQuery();

            // Declare a variable to hold the number of credits taken
            double creds_taken;
            // While res has a next value
            while(res->next())
            {
                // Initialize the variable to hold the number of credits taken by the student
                creds_taken = res->getDouble(1);
            }

            // Update the SQL prepared statement variable, pstmt by passing the query to return the number of grade points for the student as the prepareStatement argument
            pstmt = conn->prepareStatement("SELECT SUM(Courses_T.credits * Grades_T.point_value) FROM Courses_T, Completed_Courses_T, Grades_T WHERE last_name = (?) AND first_name = (?) AND Completed_Courses_T.grade = Grades_T.type AND Completed_Courses_T.course_prefix = Courses_T.prefix AND Completed_Courses_T.course_number = Courses_T.number; ");
            // Set the values for the query
            pstmt->setString(1, last_name);
            pstmt->setString(2, first_name);
            // Update the ResultSet variable, res, to hold the executed query
            res = pstmt->executeQuery();

            // Declare a variable to hold the number of grade points
            double grade_points;
            // While res has a next value
            while(res->next())
            {
                // Initialize the variable to hold the number of grade points for the student
                grade_points = res->getDouble(1);
            }

            // Output the total number of credits taken and the GPA (to two decimal places) for the student
            std::cout << "\nTotal number of credits taken: " << creds_taken;
            printf("\nGPA: " "%.2f\n", grade_points/creds_taken);
            std::cout << "\n" << std::endl;
        }

        // Catch any SQL Exceptions
        catch (sql::SQLException sqle)
        {
            // Display the exception/error which occured
            std::cout << "Exception in SQL: " << sqle.what() << std::endl;
        }
}