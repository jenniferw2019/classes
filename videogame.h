// header file for videogame
#ifndef VIDEOGAME_H
#define VIDEOGAME_H
#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class Videogame : public Media
{
  //define functions
 public:
  Videogame();
  bool add();
  void display();
  void setPublisher(char* newPublisher);
  void setRating(float newRating);
  char* getPublisher();
  float getRating();
  ~Videogame();
  
 private:
  //variables
  char publisher[100];
  float rating;
};

#endif
