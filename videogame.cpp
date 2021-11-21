#include "videogame.h"
#include <iostream>
#include <cstring>

using namespace std;

Videogame::Videogame() {}

void Videogame::add()
{
  Media::add();
  cout << "Type publisher" << endl;
  cin.get(publisher, 100);
  cin.get();

  cout << "Give rating from 1 (bad) to 5 (great)" << endl;
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
