/*****************************************************************
//
//  NAME:        Yeeun Shin
//
//  HOMEWORK:    project 2
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        November 28, 2022
//
//  FILE:        user_interface.cpp
//
//  DESCRIPTION:  It calls the functions from the database.
//
//  REFERENCES:
//   programize.com, cppreference.com, tutorialspoint.com, lecture. 
//
****************************************************************/

#include <iostream>
#include <iomanip>
#include <cstring>
#include "llist.h"

void getAddress(std::string&);
int getaccnum();
llist Mylist;

/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   It shows and gives the possible choices that 
//                 user can input. 
//
//  Parameters:    argc (int) : The number of elements in argv
//                 argv (char*[]) : An array of arguments passed
//                                  to the program.
//
//  Return values:  0 : program ended. 
//
****************************************************************/

int main(int argc, char *argv[])
{
    #ifdef DEBUGMODE
        std::cout << "\n-- DEBUGMODE--\n" << std::endl;
        std::cout << "-main function called.-" << std::endl;
    #endif

    int running = 0;
    int accnum;
    int usrInp;
    std::string input;

    std::string blank = "\n";
    const char *blankptr = blank.c_str();    

    std::string add = "add";
    const char *addptr = add.c_str();

    std::string prnt = "printall";
    const char *prntptr = prnt.c_str();

    std::string find = "find";
    const char *findptr = find.c_str();

    std::string dlt = "delete";
    const char *dltptr = dlt.c_str();

    std::string quit = "quit";
    const char *quitptr = quit.c_str();

    while (running != 1)
    {
        std::cout << "\nPlease type the name of the option: \n" << std::endl;
        std::cout << "add: Add a new record in the database\n" << std::endl;
        std::cout << "printall: Print the contenst of the entire database\n" << std::endl;
        std::cout << "find: Find and print record with a specified account #\n" << std::endl;
        std::cout << "delete: Delete existing record with the specified account number\n" << std::endl;
        std::cout << "quit: Quit the program\n" << std::endl;
        std:: cout << "Which option would you like to choose?\n" << std::endl;

        std::getline(std::cin, input);
        usrInp = input.size();
        const char* usrptr = input.c_str();
        
        if (strncmp(usrptr, blankptr, usrInp) == 0)
        {
            std::cout << "-Invalid input. Please try again.-" << std::endl;
        }

        else if (strncmp(usrptr, addptr, usrInp) == 0)
        {
            accnum = getaccnum();
            
            std::string NameTemp, AddressTemp, temp;
            NameTemp.clear();
            AddressTemp.clear();

            std::cout << "\nPut your name: " << std::endl;
            std::getline(std::cin, NameTemp, '\n');

            std::cout << "\nPut your address by # in the end." << std::endl;
            std::getline(std::cin, AddressTemp, '#');
            if (!std::cin.eof())
            {
                std::getline(std::cin, temp, '\n');
            }
            Mylist.addRecord(accnum, (char*)(NameTemp.c_str()), (char*)(AddressTemp.c_str()));
        }

        else if (strncmp(usrptr, prntptr, usrInp) == 0)
        {
            Mylist.printAllRecords();
        }

        else if (strncmp(usrptr, findptr, usrInp) == 0)
        {
            accnum = getaccnum();
            Mylist.findRecord(accnum);
        }

        else if (strncmp(usrptr, dltptr, usrInp) == 0)
        {
            accnum = getaccnum();
            Mylist.deleteRecord(accnum);
        }

        else if (strncmp(usrptr, quitptr, usrInp) == 0)
        {
            running = 1;
        }

        else
        {
            std::cout << "\n-Invalid input. Please try again.-" << std::endl;
        }
    }
    return 0;
}

/*****************************************************************
//
//  Function name: getaccnum()
//
//  DESCRIPTION:   Prompts the user for a valid account number,
//                 validates input.
//
//  Return values: int : valid address given by user.
//
****************************************************************/

int getaccnum()
{
    int input = 0;
    bool valid = false;

    while (!valid)
    {
        std::cout << "\n-Please input account number: " << std::endl;
        std::cin >> input;
 
    

    if (input > 0)
    {
        valid = true;
    }

    else 
    {
        std::cout << "Invalid input. Please enter again." << std::endl;
    }
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    }
    
    return input;
}

