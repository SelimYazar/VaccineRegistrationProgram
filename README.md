# VaccineRegistrationProgram


This project is a C++ console application that allows users to register for vaccination, log in to view and update their information, and track their vaccination progress. The program reads and writes data to a file for persistent storage.

Features

Login and Registration: Users can register by providing their personal information and log in using their unique ID to access their details.
Vaccination Tracking: Users can track their vaccination status, including the number of doses taken and the type of vaccine (X or Y).
Information Update: Users can update their personal details (name, surname, age, city) if necessary.
Data Persistence: The program saves user data to a file (database.txt) and allows loading of data on program startup.
Age-based Vaccination Rules: Users under 18 years old cannot register for vaccination, and users who have already received two doses cannot register for more.
Technologies Used

C++: The primary programming language used for the application logic.
File Handling: The program uses file handling to read and write user data to database.txt.
Standard Library: The application uses standard C++ libraries such as <iostream>, <fstream>, and <vector> for input/output operations and data storage.
How It Works

Menu Options:

Login: Users can log in using their unique ID to view or update their information.
Register: New users can create an account by providing their personal details (ID, name, surname, age, city).
Save and Exit: Saves all user data to database.txt and exits the program.
Key Functions:

ReadFile: Reads the user data from database.txt and loads it into memory.
Login: Allows users to log in using their ID, and displays their personal information.
Register: Allows new users to register by entering their personal details.
DisplayInfo: Displays user information and provides options to update it or register for vaccination.
Save: Saves all user data back to the database.txt file before exiting the program.
Vaccination Logic:

Users over the age of 18 can choose either "X" or "Y" vaccine type.
Users are allowed a maximum of two doses. If they have already received two doses, they cannot receive more.
Users can update their vaccination details as needed.
