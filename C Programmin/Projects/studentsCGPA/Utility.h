#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>

#ifndef UTILITY_H_
#define UTILITY_H_

struct studentInfo
{
    char id[15];
    float cgpa;
};

float generateCGPA(float marks);
void DisplayCGPA(struct studentInfo *s, int size);
char* subjectCode(int i);
void saveDocument(struct studentInfo *s, int size);

#endif // UTILITY_H_
