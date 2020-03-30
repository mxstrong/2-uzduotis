#include <algorithm>
#include <iostream>
#include <filesystem>
#include "Student.h"
#include "Random.h"
#include "PrintResults.h"
#include "GenerateFile.h"
#include "ReadData.h"

using namespace std::chrono;

int main()
{
  auto start = steady_clock::now();
  std::vector<Student> students;
  std::string choice = chooseInputSource();

  if (choice == "skaityti")
  {
    readDataFromFile(students);
  } 
  else if (choice == "generuoti")
  {
    generateData(students);
    bool choice = chooseToCalculate(students);
    if (!choice)
    {
      return 0;
    }
  }
  else
  {
    readDataFromInput(students);
  }
  std::vector<Student> badStudents;

  std::string final = chooseFinal();
  
  divideStudents(students, badStudents, final);

  sortStudents(students);

  printResultsToFile(students, "pazangus.txt", final);
  printResultsToFile(badStudents, "nepazangus.txt", final);
  auto end = steady_clock::now();
  duration<double> diff = end - start;
  std::cout << "Visos programos veikimo laikas: " << diff.count() << std::endl;

  system("pause");

  return 0;
}