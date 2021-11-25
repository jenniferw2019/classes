//hearder file for music 
#ifndef MUSIC_H
#define MUSIC_H
#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class Music : public Media
{

 public:
  //define functions
  Music();
  bool add();
  void display();
  void setArtist(char* newArtist);
  void setDuration(float newDuration);
  void setPublisher(char* newPublisher);
  char* getArtist();
  float getDuration();
  char* getPublisher();
  ~Music();
  
 private:
  //variables
  char artist[100];
  float duration;
  char publisher[100];
  
};

#endif
