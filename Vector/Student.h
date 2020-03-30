#pragma once
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

struct Student
{
  int examResult = 0;
  std::vector<int> homeworkResults;
  std::string name, surname;
  float getAverage();
  float getMedian();

  // Calculate final mark using either median or average of homework results as first parameter.
  float getFinal(float homeworkResult, float examResult);
};

std::istream& operator >> (std::istream& in, Student& student);
std::istringstream& operator >> (std::istringstream& input, Student& student);
std::ofstream& operator << (std::ofstream& out, Student& student);



