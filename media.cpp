#include "media.h" 
#include <iostream>
#include <cstring>

using namespace std;

Media::Media() {}


void Media::add()
{
  cout << "Type title" << endl;
  cin.get(title, 100);
  cin.get();

  cout << "Type year" << endl;
  cin >> year;
  cin.get();
}

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



