#ifndef MEDIA_H
#define MEDIA_H
#include <iostream>
#include <cstring>

using namespace std;


class Media
{
public:
  Media();
  void setTitle(char* newTitle);
  void setYear(int newYear);
  char* getTitle();
  int getYear();
  ~Media();
  
private:
  char title[100];
  int year;
};

#endif
