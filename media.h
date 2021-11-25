//header for media
#ifndef MEDIA_H
#define MEDIA_H
#include <iostream>
#include <cstring>

using namespace std;


class Media
{
public:
  // define functions
  Media();
  virtual bool add();
  virtual void display();
  void setTitle(char* newTitle);
  void setYear(int newYear);
  char* getTitle();
  int getYear();
  ~Media();
  
protected:
  //variables
  char title[100];
  int year;
};

#endif
