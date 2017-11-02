//
// CS 2720 Assignment 2 Solution
//
/// \author Howard Cheng
/// \date October 17, 2017
///
///
/// The Box class is an abstraction of a rectangular box that can be 
/// drawn on a Screen.
///

#ifndef BOX_H
#define BOX_H

#include "ScreenElement.h"
#include "Line.h"
#include "Exceptions.h"

#include <iostream>
using namespace std;

/// The Box class is an abstraction of a retangular box that can be
/// drawn on a Screen.  It is specified internally by two
/// corners---upper left and bottom right, as well as a character to
/// draw the box with.  It provides functions to draw itself on a
/// Screen as well as reading a description of itself from an input
/// stream.

class Box: virtual public ScreenElement {
protected:
  /// the four Lines that make up a box
  Line m_line[4];

  /// helper to construct the box with the four corners and the drawing
  /// character.
  ///
  /// \param[in] ul_row the row of the upper left corner
  /// \param[in] ul_column the column of the upper left corner
  /// \param[in] br_row the row of the bottom right corner
  /// \param[in] br_column the column of the bottom right corner
  /// \param[in] ch the drawing character
  void constructLines(int ul_row, int ul_column, int br_row, int br_column,
		      char ch) noexcept;

public:
  /// constructs a box
  ///
  /// \param[in] ul_row the row of the upper left corner
  /// \param[in] ul_column the column of the upper left corner
  /// \param[in] br_row the row of the bottom right corner
  /// \param[in] br_column the column of the bottom right corner
  /// \param[in] ch the drawing character
  Box(int ul_row = 0, int ul_column = 0, int br_row = 0, int br_column = 0, 
      char ch = ' ') noexcept;

  /// destroys the object
  virtual ~Box() noexcept {};

  /// draws the Box on the given Screen
  //
  /// \param[in,out] screen the screen to draw in
  /// \throw invalid_coordinates_error if the object does not fit on the screen
  virtual void draw(Screen &screen);

  /// reads a description of the box from input stream.  The row and
  /// columns of the two corners, as well as the drawing character
  /// are specified on one line of input separated by spaces.
  //
  /// \param[in,out] is the input stream to read from
  /// \throw input_format_error if the user input does not satisfy the correct format
  virtual void read(istream &is);
};


#endif
