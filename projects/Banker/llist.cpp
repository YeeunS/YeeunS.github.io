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
//  FILE:        llist.cpp
//
//  DESCRIPTION: C++ program from project1 and developed.
//
//  REFERENCES:
//   programize.com, cppreference.com, tutorialspoint.com, lecture.
//
****************************************************************/

#include "llist.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include <string.h>
#include <stdlib.h>

/*****************************************************************
//
//  Function name:  llist()
//
//  DESCRIPTION:    Constructor of the llist
//
//  Parameters:     none.
//
//  Return values:  none.
//                  
****************************************************************/

llist::llist()
{
#ifdef DEBUGMODE
    std::cout << "\n-Default constructor called-" << std::endl;
#endif

    start = NULL;
    strncpy(filename, "data.txt", 20);
    readfile();
}

/*****************************************************************
//
//  Function name: ~llist
//
//  DESCRIPTION:   Destructor of the llist
//                 
//  Parameters:    none.
//                 
//  Return values: none.
//                  
****************************************************************/

llist::~llist()
{
#ifdef DEBUGMODE
    std::cout << "\n-Destructor called-" << std::endl;
#endif    

    writefile();
    cleanup();
}

/*****************************************************************
//
//  Function name:  llist(char[])
//
//  DESCRIPTION:    Constructor of the llist
//                 
//  Parameters:     filename (char[]) : filename to write
//                 
//  Return values:  none.
//                 
****************************************************************/

llist::llist(char filename[])
{
#ifdef DEBUGMODE
    std::cout << "-Constructor called-" << std::endl;
    std::cout << "-Function name: " << filename << std::endl;
#endif

    start = NULL;
    strncpy(filename, filename, 20);
    readfile();    
}

/*****************************************************************
//
//  Function name: opertor=
//
//  DESCRIPTION:   overloaded operator
//                 
//  Parameters:    List (const llist&) : to copy the data and to overload
//                 
//  Return values: reference.
//                  
****************************************************************/

llist& llist::operator=(const llist& List)
{
    strncpy(filename, List.filename, 20);

    int accountno;
    char name[30];
    char address[60];
    struct record* current = List.start;

    while (current != NULL)
    {
        accountno = current->accountno;
        strncpy(name, current->name, 30);
        strncpy(address, current->address, 60);
        addRecord(accountno, name, address);
        current = current->next;
    }
    return *this;
}

/*****************************************************************
//
//  Function name: addRecord
//
//  DESCRIPTION:   It will add a new record into the correct position, 
//                 such that the list is kept sorted 
//                 in descending order of account numbers.
//                 
//  Parameters:    accountno (int) : account number by the user
//                 name (char[]) : account name by the user
//                 address (char[]) : account address by the user              
//
//  Return values: none
//                 
****************************************************************/

void llist::addRecord(int accountno, char name[], char address[])
{
#ifdef DEBUGMODE
    std::cout << "\n-addRecord function called-" << std::endl;
    std::cout << "\n-Account number to add: " << accountno << std::endl;
    std::cout << "\n-Name to add: " << name << std::endl;
    std::cout << "\n-Address to add: " << address << std::endl;
#endif

    int i, j, value;
    record *temp, *current;
    i = 0;
    j = 0;
    value = 1;

    if (start == NULL)
    {
        this->start = new record;
        this->start->accountno = accountno;
        strcpy(start->name, name);
        strcpy(start->address, address);
        start->next = NULL;
        value = 0;
    }

    else
    {
        current = this->start;

        while (value != -1 && current != NULL)
    {
        if(current->accountno == accountno)
        {
            value = -1;
        }
        else
        {
            current = current -> next;
        }
    }

    if (value == 1)
    {
        current = this->start;
        temp = new record;
        temp->accountno = accountno;
        strcpy(temp->name, name);
        strcpy(temp -> address, address);
        
        if (accountno >= this->start->accountno)
        {
            temp->next = this->start;
            this->start = temp;
            current = temp;
            value = 0;
        }
    }

        if (value == 1)
        {
            while (current != NULL && accountno < current->accountno)
            {
                current = current->next;
                i = i + 1;
            }
            temp->next = current;
            current = this->start;

            while (j != i)
            {
                if (j + 1 == i)
                {
                    current->next = temp;
                }
                j = j + 1;
                current = current->next;
            }
            value = 0;
        }
    }
}

/*****************************************************************
//
//  Function name: findRecord
//
//  DESCRIPTION:   It prints records with a specified account #.
//
//  Parameters:    accountno (int): account number by user to use to find records
//
//  Return values:  1 : returned successfully
//                  0 : fail
//
****************************************************************/

int llist::findRecord(int accountno)
{
    int value = 1;

#ifdef DEBUGMODE
    std::cout << "\n-findRecord funciton called-" << std::endl;
    std::cout << "\n-Finding record: " << accountno << "-" << std::endl;
#endif    
    
    if (this->start == NULL)
    {
        std::cout << "\n-No such records contained-\n";
    }
    record *ptr = this->start;
    
    while (value == 1)
    {   
        if (ptr == NULL)
        {
            std::cout << "\n-Account #" << accountno << "does not exist in database -\n";
            value = -1;
        
        }
        else if (ptr -> accountno == accountno)
        {
            std::cout << "\n-Record found" << std::endl;
            std::cout << "\n-Account number: " << ptr->accountno << std::endl;
            std::cout << "\n-Account name: " << ptr->name << std::endl;
            std::cout << "\n-Account address: " << ptr->address << std::endl;
            value = 0;
        }
        else
        {
            ptr = ptr->next;
        }
    }
    return value;
}

/*****************************************************************
//
//  Function name: printAllRecords
//
//  DESCRIPTION:   It will print the contents of the entire database.
//                
//  Parameters:    none.
//
//  Return values:  none.
//                 
****************************************************************/

void llist::printAllRecords()
{
#ifdef DEBUGMODE
    std::cout << "\n-printAllRecords function Called-" << std::endl;
#endif    
    
    if (this->start == NULL)
    {
        std::cout << "\n-There are no records contained -\n";     
    }
            
    record *ptr = this->start;

    while (ptr != NULL)
    {
        std::cout << "\nAccount number: " << ptr->accountno << std::endl;
        std::cout << "\nAccount name: " << ptr->name << std::endl;
        std::cout << "\nAccount address: " << ptr->address << std::endl;
        ptr = ptr->next;
    }
}

/*****************************************************************
//
//  Function name: deleteRecord
//
//  DESCRIPTION:   It deletes all the records with the specified account number.
//
//  Parameters:    accountno (int) : the account number by user
//
//  Return values:  1 : return successfully.
//                  0 : fail to return
//
****************************************************************/

int llist::deleteRecord(int accountno)
{
#ifdef DEBUGMODE
    std::cout << "\n-deleteRecord function called-" << std::endl;
    std::cout << "\n-Deleting record" << accountno << std::endl;
#endif

    struct record *temp;
    struct record *current;
    int value = 1;
    int status = 0;

    if (this->start == NULL)
   {
        std::cout << "Account number given isn't found in the database." << std::endl;
        value = -1;
   }
   else
   {
        temp = this->start;

        while (value == 1)
        {
            if (temp == NULL)
            {
                value = -1;
            }
            else if (temp->accountno == accountno)
            {
                current = temp->next;
                delete(temp);
                temp = this->start;

                if(status == 0)
                {
                    this->start = current;
                    value = 0;
                }

                while (status - 1 != 0 && value != 0)
                {
                    temp = temp->next;
                    status = status - 1;
                }

                if (value != 0)
                {
                    temp->next = current;
                    value = 0;
                }
            }
            else
            {
                temp = temp->next;
                status = status + 1;
            }
        }
   }
   return value;
}

/*****************************************************************
//
//  Function name: readfile
//
//  DESCRIPTION:   Reads database from text file and add it into a linked list 
//                 of records.
//                 
//  Parameters:    none.
//
//  Return values: 1 : successfully returned
//                 0 : failed
//                 
****************************************************************/

int llist::readfile()
{
#ifdef DEBUGMODE
    std::cout << "\n-readfile function called-" << std::endl;
#endif

    int status = 0;
    int value = 0;
    int accountNum;
    std::string name, address, account, buffer;

    std::ifstream infile;
    infile.open(filename);

    if (infile == NULL)
    {
        value = -1;
    }

    else
    {
        while (status == 0 && infile.peek() != EOF)
        {
            if (infile.peek() == EOF)
            {
                status = 1;
            }
	
	    else
            {
                account.clear();
                name.clear();
                address.clear();

                std::getline(infile, account, '\n');
                accountNum = atoi(account.c_str());
                std::getline(infile, name, '\n');
                std::getline(infile, address, '#');
                if(!infile.eof())
                {
                     getline(infile, buffer, '\n');
                }

                addRecord(accountNum, (char*)(name.c_str()), (char*)(address.c_str()));
            }
        }
    }
    infile.close();
    return value;

}

/*****************************************************************
//
//  Function name: writefile
//
//  DESCRIPTION:   Writes the data of records given to a text file.
//                
//  Parameters:    none.
//
//  Return values:  0 : returned successfully
//                 -1 : failed
//                 
****************************************************************/

int llist::writefile()
{
#ifdef DEBUGMODE
    std::cout << "\n-writefile function called-" << std::endl;
#endif

    int value = 0;
    struct record *ptr;
    ptr = this->start;
    std::ofstream outFile;
    outFile.open(filename);

    if (ptr == NULL)
    {
        value = -1;
    }

    else
    {
        while (value == 0 && ptr != NULL)
        {
            outFile << ptr->accountno << "\n" << ptr->name << "\n" << ptr->address << "\n";
            ptr = ptr->next;
        }
    }    
    outFile.close();
    return value;    
}

/*****************************************************************
//
//  Function name: cleanup
//
//  DESCRIPTION:   deallocates all of the memories. 
//
//  Parameters:    none.
//
//  Return values:  none.
//                 
****************************************************************/

void llist::cleanup()
{
#ifdef DEBUGMODE
    std::cout << "\n-cleanup function called-" << std::endl;
#endif

    struct record *ptr = start;
    struct record *nextptr;

    while (ptr != NULL)
    {
        nextptr = ptr;
        ptr = ptr->next;
        delete nextptr;
    } 
    start = NULL;
}

/*****************************************************************
//
//  Function name: operator
//
//  DESCRIPTION:   overloades the << operator to print the contents of the database
//                 so that it replaces the function call of printAllRecords in the user-interface.       
//                 
//  Parameters:    os (std::ostream&) : write the llist's data.
//                 List (const llist&) : copy the data
//
//  Return values: ostream reference
//                  
//
****************************************************************/

std::ostream& operator << (std::ostream& os, const llist& List)
{
    struct record* current = List.start;
    
    if (current == NULL)
    {
        std::cout << "No records found in database." << std::endl;
    }
    else 
    {
        while (current != NULL)
        {
            std::cout << "Account number: " << current->accountno << std::endl;
            std::cout << "Name: " << current->name << std::endl;
            std::cout << "Address: " << current->address << std::endl;
            current = current->next;
        }
    }
    return os;
}

