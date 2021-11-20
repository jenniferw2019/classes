#ifndef MEDIA_H
#define MEDIA_H
#include <iostream>
#include <cstring>

using namespace std;


class Media
{
public:
  Media();
  virtual void add();
  virtual void display();
  void setTitle(char* newTitle);
  void setYear(int newYear);
  char* getTitle();
  int getYear();
  ~Media();
  
protected:
  char title[100];
  int year;
};

#endif
