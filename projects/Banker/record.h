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
//  FILE:        record.h
//
//  DESCRIPTION: The header file.
//
//  REFERENCES: none.
//
****************************************************************/

struct record
{
    int                accountno;
    char               name[30];
    char               address[60];
    struct record*     next;
};
