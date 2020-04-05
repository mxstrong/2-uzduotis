#include <chrono>
#include <fstream>
#include <filesystem>
#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include "Student.h"
#include "Random.h"

using namespace std::chrono;

int calculateHomeworkCount(const std::string& input)
{
  int homeworkCount = 0;
  const size_t step = 2;
  size_t position = 0;
  while ((position = input.find("ND", position)) != std::string::npos) {
    position += step;
    ++homeworkCount;
  }

  return homeworkCount;
}

// Read data from console input
void readDataFromInput(std::list<Student>& students)
{
  int n;
  std::cout << "Iveskite studentu kieki: " << std::endl;
  std::cin >> n;
  for (int i = 0; i < n; i++)
  {
    Student student;
    std::cin >> student;
    students.push_back(student);
  }
}

// Read data from file
void readDataFromFile(std::list<Student>& students)
{
  bool fileExists = false;
  std::string fileName;
  do {
    fileExists = true;
    std::cout << "Iveskite failo varda: " << std::endl;
    std::cin >> fileName;
    try
    {
      std::filesystem::exists(fileName);
    }
    catch (std::filesystem::filesystem_error & e)
    {
      fileExists = false;
      throw "File cannot be opened";
    }
  } while (!fileExists);
  auto start = steady_clock::now();
  std::ifstream f(fileName.c_str());
  std::string input;

  std::stringstream buffer;
  buffer << f.rdbuf();
  f.close();
  std::getline(buffer, input);
  if (input.empty())
  {
    return;
  }
  int homeworkCount = calculateHomeworkCount(input);

  while (buffer)
  {
    if (!buffer.eof())
    {
      std::getline(buffer, input);
      Student student;
      std::istringstream inputStream(input);
      inputStream >> student;
      students.push_back(student);
    }
    else
    {
      break;
    }
  }
  f.close();
  auto end = steady_clock::now();
  duration<double> diff = end - start;
  std::cout << "Duomenu nuskaitymas is failo uztruko: " << diff.count() << std::endl;
}

void generateData(std::list<Student>& students)
{
  auto start = steady_clock::now();
  int n;
  std::cin >> n;
  if (n < 1) {
    return;
  }
  int homeworkCount = generateRandomInt(1, 20);
  std::list<std::string> names{ "Vardenis", "Vardas", "Vardukas", "Vardiklis", "Vardonis", "Vardanas", "Vardauskas" };
  std::list<std::string> surnames{ "Pavardenis", "Pavarde", "Pavardukas", "Pavardiklis", "Pavardonis", "Pavardanas", "Pavardauskas" };
  for (int i = 0; i < n; i++)
  {
    Student student;
    int random = generateRandomInt(0, 6);
    auto namesIterator = names.begin();
    std::advance(namesIterator, random);
    student.name = *namesIterator;

    random = generateRandomInt(0, 6);
    auto surnamesIterator = surnames.begin();
    std::advance(surnamesIterator, random);
    student.surname = *surnamesIterator;

    for (int j = 0; j < homeworkCount; j++)
    {
      int result = generateRandomInt(0, 10);
      student.homeworkResults.push_back(result);
    }

    student.examResult = generateRandomInt(0, 10);
    students.push_back(student);
  }
  auto end = steady_clock::now();
  duration<double> diff = end - start;
  std::cout << "Studentu generavimas uztruko: " << diff.count() << std::endl;
}