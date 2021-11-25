/*
This program creates a database that includes videogames, music, and movies. User can add, search, and delete videogames/music/movies. 
A "QUIT" command stops the program.
When they add a digital media, they will be prompted to enter different fields (like title and year for example).
There is one parent class, three child classes, and one main .cpp file.
Author: Jennifer Wang
11/23/21
 */

//main.cpp
#include <iostream>
#include <cstring>
#include "media.h"
#include "videogame.h"
#include "music.h"
#include "movies.h"
#include <vector>

using namespace std;

//declare functions
bool addMedia(Media* pMedia, vector<Media*>* pVector);
void searchMedia(vector<Media*> pMediaSearch);
void deleteMedia(vector<Media*>* pMediaDelete);

int main()
{
  bool runProgram = true;
  char input[10];
  //char inSearch[100];

  vector<Media*> vecMediaList;
  vector<Media*>* ptrVecMedia;
  ptrVecMedia = &vecMediaList;

  while (runProgram == true)
    {
      char enter[20];

      cout << "Type ADD or SEARCH or DELETE or QUIT" << endl;
      cin.get(input,10);
      cin.get();

      // if ADD is typed, asks what digial media user wants to add. user can add each kind of media including all information in each field
      if (strcmp(input, "ADD") == 0)
	{
	  cout << "Do you want to enter a Videogame, Music, or Movie? Please enter 'VIDEOGAME' or 'MUSIC' or 'MOVIES'" << endl;
	  cin >> enter;
	  cin.get();

	  // if MUSIC is typed, creates a new entry for music
	  if (strcmp(enter, "MUSIC") == 0)
	    {
	      Music* myMusic = new Music();
	     runProgram =  addMedia(myMusic, ptrVecMedia);
	      
	    }
	  // if VIDEOGAME is typed, creates a new entey for videogame
	  else if (strcmp(enter, "VIDEOGAME") == 0)
	    {
	      Videogame* myVideogame = new Videogame();
	      runProgram = addMedia(myVideogame, ptrVecMedia);
	    }
	  // if MOVIES is typed, creates a new entry for movies
	  else if (strcmp(enter, "MOVIES") == 0)
	    {
	      Movies* myMovies = new Movies();
	      runProgram = addMedia(myMovies, ptrVecMedia);
	    }
	}

      // if SEARCH is typed, prompts user to search for a digial media currently in the media data base by title or year.
      //if multiple objects match, all are listed
      if (strcmp(input, "SEARCH") == 0)
	{
	  searchMedia(vecMediaList); 
	}

      // if DELETE is tyoed, prompts user to search for what they want to delete and then asks for confirmation
      if (strcmp(input, "DELETE") == 0)
	{
	  deleteMedia(ptrVecMedia);
	}

      // if QUIT is typed, the program stops
      if (strcmp(input, "QUIT") == 0)
	{
	  runProgram = false;
	}
  
    }

  return 0;

}

// add function
bool addMedia(Media* pMedia, vector<Media*>* pVector)
{

  bool correct;
  correct = pMedia->add();

  // adds the media type to vector of media
  pVector->push_back(pMedia);

  return correct;
  
}

//search for a specific media function
void searchMedia(vector<Media*> pVecMedia)
{
  char inSearchTitle[100];
  int inSearchYear = 0;
  char search;
  
  cout << "Search by Title or Year? Enter 'T' for Title or 'Y' for Year" << endl;
  cin >> search;
  cin.get();
  
  //search by title
  if (search == 'T')
    {
      cout << "Enter Title" << endl;
      cin.get(inSearchTitle,100);
      cin.get();
      
      
      for (vector<Media*>::iterator it = pVecMedia.begin(); it != pVecMedia.end(); it++)
	{
	  if (strcmp(inSearchTitle, (*it)->getTitle()) == 0)
	    {
	      (*it)->display();
	    }
	}
      
    }
  
  
  else if (search == 'Y')
    {
      cout << "Enter Year" << endl;
      cin >> inSearchYear;
      if(cin.fail())
	{
	  cin.clear();
	  cin.ignore(numeric_limits<streamsize>::max(), '\n');
	  cout << "Year must be int value" << endl;
	  
	}
      else
	{

	  cin.get();
	  
	  for (vector<Media*>::iterator it = pVecMedia.begin(); it != pVecMedia.end(); it++)
	    {
	      if (inSearchYear == (*it)->getYear())
		{
		  (*it)->display();
		}
	    }
	}
      
    }

}

//delete media function
void deleteMedia(vector<Media*>* pDeleteMedia)
{

  char inDeleteTitle[100];
  int inDeleteYear = 0;
  char search;
  char yesno;
  int count = 0;
  // int index = 0;

  cout << "Delete by Title or Year? Enter 'T' for Title or 'Y' for Year" << endl;
  cin >> search;
  cin.get();

  //search by title
  if (search == 'T')
    {
      cout << "Enter Title" << endl;
      cin.get(inDeleteTitle,100);
      cin.get();
      
      for (vector<Media*>::iterator it = pDeleteMedia->begin(); it != pDeleteMedia->end(); it++)
	{
	  if (strcmp(inDeleteTitle, (*it)->getTitle()) == 0)
	    {
	      (*it)->display();
	      count++;
	    }
	 
	}

      if (count > 0)
	{
	  //ask if user wants to delete
	  cout << "Are you sure you want to delete these? Type 'y' for yes or 'n' for no" << endl;
	  cin >> yesno;
	  cin.get();
	  
	  if (yesno == 'y')
	    {
	      // cout << yesno << endl;
	      //cout << count << endl;
	      //if yes, deletes all media with the same title
	      while(count != 0)
		{
		  int index = 0;
		  for (vector<Media*>:: iterator it = pDeleteMedia->begin(); it != pDeleteMedia->end(); it++)
		    {
		      
		      if (strcmp(inDeleteTitle, (*it)->getTitle()) == 0)
			{
			  delete *(pDeleteMedia->begin()+ index);
			  pDeleteMedia->erase(pDeleteMedia->begin()+ index);
			  count = count - 1;
			  break;
			}
		      else
			{
			  index++;
			}
		    }
		}
	      
	    }
	  // if no, doesn't delete
	  else
	    {
	      cout << "Ok, no delete" << endl;
	    }
	}
      else
	{
	  cout << "No media found" << endl;
	}
    }
  

  // search by year
 else if (search == 'Y')
    {
      cout << "Enter Year" << endl;
      cin >> inDeleteYear;

      if(cin.fail())
	{
	  cin.clear();
	  cin.ignore(numeric_limits<streamsize>::max(), '\n');
	  cout << "Year must be int value" << endl;
	}
      else
	{
	  cin.get();
	  
	  for (vector<Media*>::iterator it = pDeleteMedia->begin(); it != pDeleteMedia->end(); it++)
	    {
	      if (inDeleteYear == (*it)->getYear())
		{
		  (*it)->display();
		  count++;
		}
	    }
	
	  if (count > 0)
	    {
	      //asks user if they want to delete
	      cout << "Are you sure you want to delete these? Type 'y' for yes or 'n' for no" << endl;
	      cin >> yesno;
	      cin.get();
	      
	      if (yesno == 'y')
		{
		  //if yes, then delete all media with the same year
		  while(count != 0)
		    {
		      int index = 0;
		      for (vector<Media*>:: iterator it = pDeleteMedia->begin(); it != pDeleteMedia->end(); it++)
			{
			  
			  if (inDeleteYear == (*it)->getYear())
			    {
			      delete *(pDeleteMedia->begin()+ index);
			      pDeleteMedia->erase(pDeleteMedia->begin()+ index);
			      count = count - 1;
			      break;
			    }
			  else
			    {
			      index++;
			    }
			}
		    }
		  
		}
	      else
		//if no, doesn't delete
		{
		  cout << "Ok, no delete" << endl;
		}
	    }
	  else
	    {
	      cout << "No media found" << endl;
	    }
	}
      
    }
}

