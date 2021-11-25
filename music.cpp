// .cpp file for music (child class)
#include "music.h"
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

Music::Music() {}

bool Music::add()
{
  bool input;
  input = Media::add();
  //prompts user to enter artist, the duration of the song, and the publisher
  if (input == true)
    {
      cout << "Type artist" << endl;
      cin.get(artist, 100);
      cin.get();
      
      cout << "How many minutes is the song?" << endl;
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
      
      cout << "Type publisher" << endl;
      cin.get(publisher, 100);
      cin.get();
      return true;
    }
  else
    {
      return input;
    }
}

//display music information
void Music::display()
{
  Media::display();
  cout << "ARTIST: " << artist << ", ";
  cout << fixed << setprecision(2) << "DURATION: " << duration << ", ";
  cout << "PUBLISHER: " << publisher << endl;
}

void Music::setArtist(char* newArtist)
{
  strcpy(artist, newArtist);
}

void Music::setDuration(float newDuration)
{
  duration = newDuration;
}

void Music::setPublisher(char* newPublisher)
{
  strcpy(publisher, newPublisher);
}

char* Music::getArtist()
{
  return artist;
}

float Music::getDuration()
{
  return duration;
}

char* Music:: getPublisher()
{
  return publisher;
}

Music::~Music(){}


