// Include the libraries needed
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <mysql/jdbc.h>


// Function to add values to tables within the database
void addFunc(sql::Connection* conn)
{
        // Prompt the user to select the table they want to add values to
        std::string input;
        std::cin >> input;

        // Add a course
        if(input == "c")
        {
            try
            {  
                // Prompt the user for the course values to be added to the Courses_T table
                std::string prefix;
                int course_number;
                std::string course_title;
                int credits;
                std::cout << "Enter the course details: ";
                std::cin >> prefix >> course_number >> course_title >> credits;

                std::cout << "\nInserting values ...";
                std::cout.flush();
                
                // Initialize a SQL prepared statement variable, pstmt, to hold the prepared statement for the current connection
                // Pass the query to insert the values as the prepareStatement argument
                sql::PreparedStatement* pstmt = conn->prepareStatement("INSERT INTO Courses_T VALUES((?), (?), (?), (?));");
                // Set the values for the query
                pstmt->setString(1, prefix);
                pstmt->setInt(2, course_number);
                pstmt->setString(3, course_title);
                pstmt->setInt(4, credits);
                // Execute the query
                pstmt->execute();
                std::cout << "Done" << std::endl;
            }

            // Catch any SQL Exceptions
            catch (sql::SQLException sqle)
            {
                // Display the exception/error which occured
                std::cout << "Exception in SQL: " << sqle.what() << std::endl;
            }
        }

        // Grades
        if(input == "g")
        {
            try
            {  
                // Prompt the user for the grade values to be added to the Grades_T table
                std::string type;
                double point_value;
                std::cout << "Enter the grade: ";
                std::cin >> type >> point_value;

                std::cout << "\nInserting values ...";
                std::cout.flush();
                
                // Initialize a SQL prepared statement variable, pstmt, to hold the prepared statement for the current connection
                // Pass the query to insert the values as the prepareStatement argument
                sql::PreparedStatement* pstmt = conn->prepareStatement("INSERT INTO Grades_T VALUES((?), (?));");
                // Set the values for the query
                pstmt->setString(1, type);
                pstmt->setDouble(2, point_value);
                // Execute the query
                pstmt->execute();
                std::cout << "Done" << std::endl;
            }

            // Catch any SQL Exceptions
            catch (sql::SQLException sqle)
            {
                // Display the exception/error which occured
                std::cout << "Exception in SQL: " << sqle.what() << std::endl;
            }
        }

        // Semesters
        if(input == "m")
        {
            try
            {  
                // Prompt the user for the semester values to be added to the Semesters_T table
                std::string code;
                int year;
                std::string description;
                std::cout << "Enter the semester: ";
                std::cin >> code >> year >> description;

                std::cout << "\nInserting values ...";
                std::cout.flush();
                
                // Initialize a SQL prepared statement variable, pstmt, to hold the prepared statement for the current connection
                // Pass the query to insert the values as the prepareStatement argument
                sql::PreparedStatement* pstmt = conn->prepareStatement("INSERT INTO Semesters_T VALUES((?), (?), (?));");
                // Set the values for the query
                pstmt->setString(1, code);
                pstmt->setInt(2, year);
                pstmt->setString(3, description);
                // Execute the query
                pstmt->execute();
                std::cout << "Done" << std::endl;
            }

            // Catch any SQL Exceptions
            catch (sql::SQLException sqle)
            {
                // Display the exception/error which occured
                std::cout << "Exception in SQL: " << sqle.what() << std::endl;
            }
        }

        // Students
        if(input == "s")
        {
            try
            {  
                // Prompt the user for the student values to be added to the Students_T table
                std::string last_name;
                std::string first_name;
                std::string phone_number;
                std::cout << "Enter the student: ";
                std::cin >> last_name >> first_name >> phone_number;

                std::cout << "\nInserting values ...";
                std::cout.flush();
                
                // Initialize a SQL prepared statement variable, pstmt, to hold the prepared statement for the current connection
                // Pass the query to insert the values as the prepareStatement argument
                sql::PreparedStatement* pstmt = conn->prepareStatement("INSERT INTO Students_T VALUES((?), (?), (?));");
                // Set the values for the query
                pstmt->setString(1, last_name);
                pstmt->setString(2, first_name);
                pstmt->setString(3, phone_number);
                // Execute the query
                pstmt->execute();
                std::cout << "Done" << std::endl;
            }

            // Catch any SQL Exceptions
            catch (sql::SQLException sqle)
            {
                // Display the exception/error which occured
                std::cout << "Exception in SQL: " << sqle.what() << std::endl;
            }
        }

        // Complete courses
        if(input == "t")
        {
            try
            {  
                // Prompt the user for the completed coure values to be added to the Completed_Courses_T table
                std::string last_name;
                std::string first_name;
                std::string course_prefix;
                int course_number;
                std::string course_grade;
                std::string semester;
                std::cout << "Enter the completed course: ";
                std::cin >> last_name >> first_name >> course_prefix >> course_number >> course_grade >> semester;

                std::cout << "\nInserting values ...";
                std::cout.flush();

                // Initialize a SQL prepared statement variable, pstmt, to hold the prepared statement for the current connection
                // Pass the query to insert the values as the prepareStatement argument 
                sql::PreparedStatement* pstmt = conn->prepareStatement("INSERT INTO Completed_Courses_T(last_name, first_name, course_prefix, course_number, grade, semester) SELECT (?), (?), (?), (?), (?), (?) WHERE EXISTS (select * from Students_T, Courses_T, Grades_T, Semesters_T where last_name = (?) and first_name = (?) and prefix = (?) and number = (?) and type = (?) and code = (?));");
                // Set the values for the query
                pstmt->setString(1, last_name);
                pstmt->setString(2, first_name);
                pstmt->setString(3, course_prefix);
                pstmt->setInt(4, course_number);
                pstmt->setString(5, course_grade);
                pstmt->setString(6, semester);
                pstmt->setString(7, last_name);
                pstmt->setString(8, first_name);
                pstmt->setString(9, course_prefix);
                pstmt->setInt(10, course_number);
                pstmt->setString(11, course_grade);
                pstmt->setString(12, semester);
                // Execute the query
                pstmt->execute();
                std::cout << "Done" << std::endl;
            }

            // Catch any SQL Exceptions
            catch (sql::SQLException sqle)
            {
                // Display the exception/error which occured
                std::cout << "Exception in SQL: " << sqle.what() << std::endl;
            }
        }
}