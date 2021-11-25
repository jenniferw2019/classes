// .cpp file for all media (parent class)
#include "media.h" 
#include <iostream>
#include <cstring>

using namespace std;

Media::Media() {}


bool Media::add()
{
  //prompts user to enter title and year
  cout << "Type title" << endl;
  cin.get(title, 100);
  cin.get();

  cout << "Type year" << endl;
  cin >> year;
  if (cin.fail())
    {
      cout << "Error, input must be a int value" << endl;
      return false;
    }
  cin.get();

  return true;
}

// display media title and year
void Media::display()
{
  cout << "TITLE: " << title << ", ";
  cout << "YEAR: " << year << ", ";
}
void Media::setTitle(char* newTitle)
{
  strcpy(title, newTitle);
}

void Media::setYear(int newYear)
{
  year = newYear;
}

char* Media::getTitle()
{
  return title;
}

int Media::getYear()
{
  return year;
}

Media::~Media() {}



