#pragma once
#include <vector>
#include "Student.h"
#include <string>

bool isFirst(Student first, Student second);
std::string chooseFinal();
void divideStudents(std::vector<Student>& students, std::vector<Student>& goodStudents, std::vector<Student>& badStudents, std::string final);
void sortStudents(std::vector<Student>& students);
void printResultsToFile(std::vector<Student>& students, std::string fileName, std::string final);
