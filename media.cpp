#include "media.h" 
#include <iostream>
#include <cstring>

using namespace std;

Media::Media() {}


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



