//
// CS 2720 Assignment 2 Solution
//
/// \author Howard Cheng
/// \date October 17, 2017
///
///
/// The ScreenElement class is an abstraction of any element that can
/// appear on a Screen.
///

#ifndef SCREENELEMENT_H
#define SCREENELEMENT_H

#include "Screen.h"
#include "Exceptions.h"
#include <iostream>
using namespace std;

/// The ScreenElement class is an abstraction of any element that can
/// appear on a Screen.  It provides functions to draw itself on a Screen
/// as well as reading a description of itself from an input stream.
class ScreenElement {

public:
  /// destroys the object
  virtual ~ScreenElement() noexcept { };

  /// draws the element on the given Screen
  //
  /// \param[in,out] screen the screen to draw in
  /// \throw invalid_coordinates_error if the object does not fit on the screen
  virtual void draw(Screen &screen) = 0;

  /// reads a description of the element from input stream
  //
  /// \param[in,out] is the input stream to read from
  /// \throw input_format_error if the user input does not satisfy the correct format
  virtual void read(istream &is) = 0;
};


#endif
