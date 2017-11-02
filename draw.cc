//
// CS 2720 Assignment 2 Solution
//
/// \author Howard Cheng
/// \date October 17, 2017
///
///
/// This is a program that allows the user to draw a number of boxes, text
/// strings, and text boxes (strings surrounded by a box) on a screen.
///

#include <iostream>
#include <vector>
#include <cassert>
#include "Screen.h"
#include "ScreenElement.h"
#include "Line.h"
#include "Box.h"
#include "Text.h"
#include "TextBox.h"
#include "Exceptions.h"

using namespace std;

/// print a menu of commands
void printMenu(void) noexcept;

/// remove all screen elements that are in the system
///
/// \param[in] vec the vector of ScreenElement pointers
void clearVector(vector<ScreenElement *> &vec) noexcept;

/// determine if a screen has been created.  Produce an error message if not.
///
/// \param[in] screen_ptr a pointer to the Screen object, or NULL if it has not been created yet.
/// \throw invalid_screen_error if the screen has not been created.           
void checkScreenReady(Screen *screen_ptr);

/// insert a ScreenElement into the system and draw it on screen
///
/// \param[in] screen the Screen object
/// \param[in] vec the vector of ScreenElement pointers
/// \param[in] element a pointer to the ScreenElement to be added
void insertElement(Screen &screen, vector<ScreenElement *> &vec, 
		   ScreenElement *element) noexcept;

/// redraw the entire screen from scratch based on the given list of ScreenElements
///
/// \param[in] screen the Screen object
/// \param[in] vec the vector of ScreenElement pointers
void redraw(Screen &screen, const vector<ScreenElement *> &vec) noexcept;


int main(void)
{
  Screen *screen = nullptr;
  vector<ScreenElement *> vec;
  char ch;

  while (1) {
    printMenu();
    cin >> ch;
    // eat white space
    while (cin.peek() != '\n') {
      cin.ignore();
    }
    cin.ignore();

    try {
      switch(ch) {
      case 'N': case 'n':
	delete screen;
	screen = new Screen;
	clearVector(vec);
	break;
      case 'B': case 'b':
	{
	  checkScreenReady(screen);
	  Box *box = new Box;
	  insertElement(*screen, vec, box);
	  break;
	}
      case 'T': case 't':
	{
	  checkScreenReady(screen);
	  Text *text = new Text;
	  insertElement(*screen, vec, text);
	  break;
	}
      case 'R': case 'r':
	{
	  checkScreenReady(screen);
	  TextBox *textbox = new TextBox;
	  insertElement(*screen, vec, textbox);
	  break;
	}
      case 'D': case 'd':
	checkScreenReady(screen);
	cout << *screen << endl;
	break;
      case 'K': case 'k':
	if (vec.size() == 0) {
	  cerr << "Nothing to remove" << endl;
	} else {
	  // if vector has size > 0 then the screen must be ready, better
	  // still check just in case
	  try {
	    checkScreenReady(screen);
	  }
	  catch (invalid_screen_error &) {
	    cerr << "Programming error: screen is not created yet." << endl;
	    assert(false);
	  }
	  delete vec[vec.size()-1];
	  vec.pop_back();
	  redraw(*screen, vec);
	}
	break;
      case 'Q': case 'q':
	delete screen;
	clearVector(vec);
	return 0;
      }
    }
    catch (invalid_screen_error &) {
      cerr << "Screen is not created yet, ignoring request." << endl;
    }
  }
  
  
  return 0;
}

// print a menu of commands
void printMenu(void) noexcept
{
  cout << endl;
  cout << "          Menu         " << endl << endl;
  cout << "N: creates a new screen" << endl;
  cout << "B: creates a Box object" << endl;
  cout << "T: creates a Text object" << endl;
  cout << "R: creates a TextBox object" << endl;
  cout << "D: draws the screen" << endl;
  cout << "K: removes most recently added ScreenElement" << endl;
  cout << "Q: quit the program" << endl;
  cout << endl;
  cout << "> ";
}

// remove all screen elements that are in the system
//
// \param[in] vec the vector of ScreenElement pointers
void clearVector(vector<ScreenElement *> &vec) noexcept
{
  for (unsigned int i = 0; i < vec.size(); i++) {
    delete vec[i];
  }
  vec.clear();
}

// determine if a screen has been created.  Produce an error message if not.
//
// \param[in] screen_ptr a pointer to the Screen object, or NULL if it has not been created yet.
// \return whether the screen has been created.           
void checkScreenReady(Screen *screen_ptr) 
{
  if (screen_ptr == nullptr) {
    throw invalid_screen_error("Screen not created.");
  }
}

// insert a ScreenElement into the system and draw it on screen
//
// \param[in] screen the Screen object
// \param[in] vec the vector of ScreenElement pointers
// \param[in] element a pointer to the ScreenElement to be added
void insertElement(Screen &screen, vector<ScreenElement *> &vec, 
		   ScreenElement *element) noexcept
{
  try {
    element->read(cin);
  }
  catch (input_format_error &e) {
    cerr << e.what() << endl;
    cerr << "Please retry." << endl;
    return;
  }

  vec.push_back(element);
  try {
    element->draw(screen);
  }
  catch (invalid_coordinates_error &e) {
    cerr << e.what() << endl;
    cerr << "Removing screen element.  Please retry." << endl;
    vec.pop_back();
    delete element;
    // need to redraw because the element may be partially drawn
    redraw(screen, vec); 
  }
}

// redraw the entire screen from scratch based on the given list of ScreenElements
//
// \param[in] screen the Screen object
// \param[in] vec the vector of ScreenElement pointers
void redraw(Screen &screen, const vector<ScreenElement *> &vec) noexcept
{
  screen.clear();
  try {
    for (unsigned int i = 0; i < vec.size(); i++) {
      vec[i]->draw(screen);
    }
  }
  catch (invalid_coordinates_error &) {
    // we should never get to here because the objects on the vectors should
    // have valid coordinates already.
    cerr << "Programming error: invalid coordinates for ScreenElements in redraw()." << endl;
    assert(false);
  }
}
