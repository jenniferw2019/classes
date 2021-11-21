#include <iostream>
#include <cstring>
#include "media.h"
#include "videogame.h"
#include <vector>

using namespace std;

void addMedia(Media* pMedia, vector<Media*>* pVector);
void printMedia(vector<Media*> pMediaPrint);
void searchMedia(vector<Media*> pMediaSearch);

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
      cout << "Type ADD or SEARCH or QUIT" << endl;
      cin.get(input,10);
      cin.get();

      if (strcmp(input, "ADD") == 0)
	{
	  Videogame* myVideogame = new Videogame();
	  addMedia(myVideogame, ptrVecMedia);
      
	}

      if (strcmp(input, "SEARCH") == 0)
	{

	  searchMedia(vecMediaList);
	  
	  /*
	  cout << "Type Title" << endl;
	  cin.get(inSearch,100);
	  cin.get();

	  for (vector<Media*>::iterator it = vecMediaList.begin(); it != vecMediaList.end(); it++)
	    {
	      if (strcmp(inSearch, (*it)->getTitle()) == 0)
		{
		  (*it)->display();
		}
	    }
	  */


	}
      if (strcmp(input, "QUIT") == 0)
	{
	  printMedia(vecMediaList);
	  runProgram = false;
	}
  
    }

  return 0;

}

void addMedia(Media* pMedia, vector<Media*>* pVector)
{

  pMedia->add();
  // pMedia->display();
  pVector->push_back(pMedia);
  
  /*
  Media* myMedia = new Media();
  myMedia = myVideogame;
  myMedia->display();
  */
}

void printMedia(vector<Media*> pVecMedia)
{
  for (vector<Media*>::iterator it = pVecMedia.begin(); it != pVecMedia.end(); it++)
    {
      (*it)->display();
    }
}

void searchMedia(vector<Media*> pVecMedia)
{
  char inSearchTitle[100];
  int inSearchYear = 0;
  char search;

  cout << "Search by Title or Year? Enter 'T' for Title or 'Y' for Year" << endl;
  cin >> search;
  cin.get();
  cout << search << endl;
  
  
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
