#ifndef VIDEOGAME_H
#define VIDEOGAME_H
#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class Videogame : public Media
{

 public:
  Videogame();
  void setPublisher(char* newPublisher);
  void setRating(int newRating);
  char* getPublisher();
  int getRating();
  ~Videogame();
  
 private:
  char publisher[100];
  int rating;
};

#endif
