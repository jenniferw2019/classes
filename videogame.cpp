// .cpp file for videogame (child class)
#include "videogame.h"
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

Videogame::Videogame() {}

bool Videogame::add()
{
  bool input;
  input = Media::add();
  //prompts user to type publisher and rating
  if (input == true)
    {
      cout << "Type publisher" << endl;
      cin.get(publisher, 100);
      cin.get();

      cout << "Give rating from 1 (bad) to 5 (great)" << endl;
      cin >> rating;
      if (cin.fail())
	{
	  cout << "Error, input must be a float value" << endl;
	  return false;
	}
      cin.get();

      return true;
    }
  else
    {
      return input;
    }
}

//display videogame information
void Videogame::display()
{
  Media::display();
  cout << "PUBLISHER: " << publisher << ", ";
  cout << fixed << setprecision(2) << "RATING: " << rating << endl;
}
void Videogame::setPublisher(char* newPublisher)
{
  strcpy (publisher, newPublisher);
}

void Videogame::setRating(float newRating)
{
  rating = newRating;
}

char* Videogame:: getPublisher()
{
  return publisher;
}

float Videogame::getRating()
{
  return rating;
}

Videogame::~Videogame() {}
