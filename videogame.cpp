#include "videogame.h"
#include <iostream>
#include <cstring>

using namespace std;

Videogame::Videogame() {}

void Videogame::add()
{
  Media::add();
  cout << "Type publisher" << endl;
  cin >> publisher;
  cin.get();

  cout << "Type rating" << endl;
  cin >> rating;
  cin.get();
}

void Videogame::display()
{
  Media::display();
  cout << "PUBLISHER: " << publisher << ", ";
  cout << "RATING: " << rating << endl;
}
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
