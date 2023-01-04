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
        std::cout << "\n";

        // Add a course
        if(input == "c")
        {
            try
            {  
                // Prompt the user for the course values to be added to the Courses_T table
                std::string prefix;
                std::cout << "Enter the course prefix (e.g. CSC): ";
                std::cin >> prefix;

                int course_number;
                std::cout << "Enter the course number (e.g. 30500): ";
                std::cin >> course_number;

                std::string course_title;
                std::cout << "Enter the course title (e.g. Database Systems): ";
                std::cin >> course_title;
                
                int credits;
                std::cout << "Enter the course credits: ";
                std::cin >> credits;

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
                std::cout << "Done\n\n";
            }

            // Catch any SQL Exceptions
            catch (sql::SQLException sqle)
            {
                // Display the exception/error which occured
                std::cout << "Exception in SQL: " << sqle.what() << std::endl;
            }
        }

        // Add a grade
        if(input == "g")
        {
            try
            {  
                // Prompt the user for the grade values to be added to the Grades_T table
                std::string type;
                std::cout << "Enter the grade type (e.g. B+): ";
                std::cin >> type;

                double point_value;
                std::cout << "Enter the point value (e.g. 3.5): ";
                std::cin >> point_value;

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
                std::cout << "Done\n\n";
            }

            // Catch any SQL Exceptions
            catch (sql::SQLException sqle)
            {
                // Display the exception/error which occured
                std::cout << "Exception in SQL: " << sqle.what() << std::endl;
            }
        }

        // Add a semester
        if(input == "m")
        {
            try
            {  
                // Prompt the user for the semester values to be added to the Semesters_T table
                std::string code;
                std::cout << "Enter the semester code (e.g. SP19): ";
                std::cin >> code;

                int year;
                std::cout << "Enter the year (e.g. 2019): ";
                std::cin >> year;

                std::string description;
                std::cout << "Enter the season (e.g. Spring): ";
                std::cin >> description;

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
                std::cout << "Done\n\n";
            }

            // Catch any SQL Exceptions
            catch (sql::SQLException sqle)
            {
                // Display the exception/error which occured
                std::cout << "Exception in SQL: " << sqle.what() << std::endl;
            }
        }

        // Add a student
        if(input == "s")
        {
            try
            {  
                // Prompt the user for the student values to be added to the Students_T table
                std::string last_name;
                std::cout << "Enter the last name: ";
                std::cin >> last_name;

                std::string first_name;
                std::cout << "Enter the first name: ";
                std::cin >> first_name;

                std::string phone_number;
                std::cout << "Enter the phone number: ";
                std::cin >> phone_number;

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
                std::cout << "Done\n\n";
            }

            // Catch any SQL Exceptions
            catch (sql::SQLException sqle)
            {
                // Display the exception/error which occured
                std::cout << "Exception in SQL: " << sqle.what() << std::endl;
            }
        }

        // Add a course
        if(input == "t")
        {
            try
            {  
                // Prompt the user for the completed coure values to be added to the Completed_Courses_T table
                std::string last_name;
                std::cout << "Enter the last name: ";
                std::cin >> last_name;

                std::string first_name;
                std::cout << "Enter the first name: ";
                std::cin >> first_name;

                std::string course_prefix;
                std::cout << "Enter the course prefix (e.g. CSC): ";
                std::cin >> course_prefix;

                int course_number;
                std::cout << "Enter the course number (e.g. 30500): ";
                std::cin >> course_number;

                std::string course_grade;
                std::cout << "Enter the grade earned (e.g. B): ";
                std::cin >> course_grade;

                std::string semester;
                std::cout << "Enter the semester code (e.g. SP19): ";
                std::cin >> semester;

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
                std::cout << "Done\n\n";
            }

            // Catch any SQL Exceptions
            catch (sql::SQLException sqle)
            {
                // Display the exception/error which occured
                std::cout << "Exception in SQL: " << sqle.what() << std::endl;
            }
        }
}
