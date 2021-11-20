#include "videogame.h"
#include <iostream>
#include <cstring>

using namespace std;

Videogame::Videogame() {}

void Videogame::setPublisher(char* newPublisher)
{
  strcpy (publisher, newPublisher);
}

void Videogame::setRating(int newRating)
{
  rating = newRating;
}

char* Videogame:: getPublisher()
{
  return publisher;
}

int Videogame::getRating()
{
  return rating;
}

Videogame::~Videogame() {}
