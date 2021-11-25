//header file for movies
#ifndef MOVIES_H
#define MOVIES_H
#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class Movies : public Media
{
 public:
  //define functions
  Movies();
  bool add();
  void display();
  void setDirector(char* newDirector);
  void setDuration(float newDuration);
  void setRating(float newRating);
  char* getDirector();
  float getDuration();
  float getRating();
  ~Movies();
  
 private:
  //variables
  char director[100];
  float duration;
  float rating;
  
};

#endif
