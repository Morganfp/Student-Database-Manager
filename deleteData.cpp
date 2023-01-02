// Include the libraries needed
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <mysql/jdbc.h>


// Function to delete a student from the tables
void deleteFunc(sql::Connection* conn)
{
    // Prompt the user for a student
    std::string last_name;
    std::string first_name;
    std::cout << "Enter the students last name followed by first name: ";
    std::cin >> last_name >> first_name;

    // Initialize a SQL prepared statement variable, pstmt, to hold the prepared statement to delete a student from the Students table for the current connection
    // Pass the query to delete a student/row from the Students table as the prepareStatement argument
    sql::PreparedStatement* pstmt = conn->prepareStatement("DELETE FROM Students_T WHERE last_name = (?) AND first_name = (?); ");
    // Set the values for the query
    pstmt->setString(1, last_name);
    pstmt->setString(2, first_name);
    pstmt->execute();

    // Update the SQL prepared statement variable, pstmt by passing the query to delete the student/row from the Completed Courses table as the prepareStatement argument
    pstmt = conn->prepareStatement("DELETE FROM Completed_Courses_T WHERE last_name = (?) AND first_name = (?); ");
    // Set the values for the query
    pstmt->setString(1, last_name);
    pstmt->setString(2, first_name);
    pstmt->execute();
    std::cout << "Done!" << std::endl;
}