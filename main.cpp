#include <iostream>
#include <cstring>
#include "media.h"
#include "videogame.h"

using namespace std;

int main()
{
  /*
  char inTitle[100];
  int inYear;
  Media* myMedia = new Media();
  
  cout << "Type title" << endl;
  cin >> inTitle;
  cin.get();

  myMedia->setTitle(inTitle);

  cout << "Type year" << endl;
  cin >> inYear;
  cin.get();

  myMedia->setYear(inYear);
  
  cout << myMedia->getTitle() << " " << myMedia->getYear() << endl;
  */

  char inTitle[100];
  char inPublisher[100];
  int inYear;
  int inRating;
  Videogame* myVideogame = new Videogame();

  cout << "Type title" << endl;
  cin >> inTitle;
  cin.get();
  myVideogame->setTitle(inTitle);

  cout << "Type year" << endl;
  cin >> inYear;
  cin.get();
  myVideogame->setYear(inYear);

  cout << "Type publisher" << endl;
  cin >> inPublisher;
  cin.get();
  myVideogame->setPublisher(inPublisher);

  cout << "Type rating" << endl;
  cin >> inRating;
  cin.get();
  myVideogame->setRating(inRating);

  cout << myVideogame->getTitle() << " ";
  cout << myVideogame->getYear() << " ";
  cout << myVideogame->getPublisher() << " ";
  cout << myVideogame->getRating()<< endl;
  
  return 0;

}
