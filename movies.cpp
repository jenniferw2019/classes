// .cpp file for movies (child class)
#include "movies.h"
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

Movies::Movies() {}

bool Movies::add()
{
  bool input;
  input = Media::add();
  //prompts user to enter director, movie duration, and rating
  if (input == true)
    {
      cout << "Type director" << endl;
      cin.get(director, 100);
      cin.get();

      cout << "How many hours is the movie?" << endl;
      cin >> duration;
      if (cin.fail())
	{
	  cout << "Error, input must be a float value" << endl;
	  return false;
	}
      else
	{
	  cin.get();
	}
      
      cout << "Give rating from 1(bad) to 5 (great)" << endl;
      cin >> rating;
      if (cin.fail())
	{
	  cout << "Error, input must be a float value" << endl;
	  return false;
	}
      else
	{
	  cin.get();
	  return true;
	}
    }
  else
    {
      return input;
    }
}

//display movies information
void Movies::display()
{
  Media::display();
  cout << "DIRECTOR: " << director << ", ";
  cout << fixed << setprecision(2) <<  "DURATION: " << duration << ", ";
  cout << fixed << setprecision(2) << "RATING: " << rating << endl;
}

void Movies::setDirector(char* newDirector)
{
  strcpy(director, newDirector);
}

void Movies::setDuration(float  newDuration)
{
  duration = newDuration;
}

void Movies:: setRating(float newRating)
{
  rating = newRating;
}

char* Movies:: getDirector()
{
  return director;
}

float Movies:: getDuration()
{
  return duration;
}

float Movies:: getRating()
{
  return rating;
}

Movies::~Movies(){}
