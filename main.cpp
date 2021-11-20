#include <iostream>
#include <cstring>
#include "media.h"
#include "videogame.h"
#include <vector>

using namespace std;

void addMedia(Media* pMedia, vector<Media*>* pVector);
void printMedia(vector<Media*> pMediaPrint);

int main()
{
  bool runProgram = true;
  char input[10];

  vector<Media*> vecMediaList;
  vector<Media*>* ptrVecMedia;
  ptrVecMedia = &vecMediaList;

  while (runProgram == true)
    {
      cout << "Type ADD or QUIT" << endl;
      cin.get(input,10);
      cin.get();

      if (strcmp(input, "ADD") == 0)
	{
	  Videogame* myVideogame = new Videogame();
	  addMedia(myVideogame, ptrVecMedia);
      
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
