//
// CS 2720 Assignment 1 Solution
//
/// \author Howard Cheng
/// \date Sep 13, 2017
///
///
/// The Screen class is an abstraction of a 2D character array.
///

#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
using namespace std;

/// The Screen class is an abstraction of a 2D character array.
/// The coordinates of each location is specified by the row and column.
/// Rows are numbered from 0 from the top, and columns are numbered
/// from 0 from the left.
class Screen {
private:
  /// the character array
  char **m_array;

  /// the height of the array
  int m_height;
  
  /// the width of the array
  int m_width;

public:
  /// constructs a Screen object from the given dimensions
  //
  /// \param[in] height the height of the array, default to 24
  /// \param[in] width the width of the array, default to 80
  Screen(int height = 24, int width = 80);

  /// destroys the object
  ~Screen();

  /// returns the number of rows in the array
  //
  /// \return the number of rows in the array
  int getRows() const {
    return m_height;
  }

  /// returns the number of columns in the array
  //
  /// \return the number of columns in the array
  int getColumns() const {
    return m_width;
  }

  /// resets the entire array to spaces
  void clear();

  /// sets the character at the given location to the given
  /// character.  The request is ignored if the location is invalid.
  //
  /// \param[in] row row of the location
  /// \param[in] col column of the location
  /// \param[in] ch the character to put into the location
  void set(int row, int col, char ch);

  /// output the given Screen object to the output stream
  //
  /// \param[in] os output stream
  /// \param[in] screen the Screen object
  /// \return the output stream
  friend ostream &operator<<(ostream &os, const Screen &screen);
};


#endif
