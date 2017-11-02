//
// CS 2720 Assignment 1 Solution
//
/// \author Howard Cheng
/// \date Sep 13, 2017
///
///
/// The Box class is an abstraction of a rectangular box that can be 
/// drawn on a Screen.
///

#include "Box.h"
#include <iostream>
using namespace std;

// helper to construct the box with the four corners and the drawing
// character.
//
// \param[in] ul_row the row of the upper left corner
// \param[in] ul_column the column of the upper left corner
// \param[in] br_row the row of the bottom right corner
// \param[in] br_column the column of the bottom right corner
// \param[in] ch the drawing character
void Box::constructLines(int ul_row, int ul_column, int br_row, int br_column,
			 char ch)
{
  m_line[0] = Line(ul_row, ul_column, ul_row, br_column, ch);
  m_line[1] = Line(br_row, ul_column, br_row, br_column, ch);
  m_line[2] = Line(ul_row, ul_column, br_row, ul_column, ch);
  m_line[3] = Line(ul_row, br_column, br_row, br_column, ch);
}

// constructs a box
//
// \param[in] ul_row the row of the upper left corner
// \param[in] ul_column the column of the upper left corner
// \param[in] br_row the row of the bottom right corner
// \param[in] br_column the column of the bottom right corner
// \param[in] ch the drawing character
Box::Box(int ul_row, int ul_column, int br_row, int br_column, char ch)
{
  constructLines(ul_row, ul_column, br_row, br_column, ch);
}

// draws the Box on the given Screen
//
// \param[in,out] screen the screen to draw in
void Box::draw(Screen &screen)
{
  for (int i = 0; i < 4; i++) {
    m_line[i].draw(screen);
  }
}


// reads a description of the box from input stream.  The row and
// columns of the two corners, as well as the drawing character
// are specified on one line of input separated by spaces.
//
// \param[in,out] is the input stream to read from
void Box::read(istream &is)
{
  int ul_row, ul_column, br_row, br_column;
  char ch;
  is >> ul_row >> ul_column >> br_row >> br_column >> ch;
  while (is.peek() != '\n') {
    // eats until the end of line
    is.ignore(1);
  }
  is.ignore();
  constructLines(ul_row, ul_column, br_row, br_column, ch);
}

