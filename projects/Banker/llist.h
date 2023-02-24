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
//  FILE:        llist.h
//
//  DESCRIPTION: database header file.
//   
//  REFERENCES:  Lecture.
//    
****************************************************************/

#ifndef LLIST_H
#define LLIST_H

#include <string>
#include <fstream>
#include "record.h"

class llist {
public:
    llist();
    llist(char[]);
    ~llist();
    void addRecord(int, char [],char []);
    int findRecord(int);
    void printAllRecords();
    int deleteRecord(int);
    llist& operator=(const llist&);
    friend std::ostream& operator <<(std::ostream&, const llist&);

private:
    record *    start;
    char        filename[20];
    int         readfile();
    int         writefile();
    void        cleanup();
};

#endif

