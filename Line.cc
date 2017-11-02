//
// CS 2720 Assignment 2 Solution
//
/// \author Howard Cheng
/// \date October 17, 2017
///
///
/// The Line class is an abstraction of a vertical or horizontal line that
/// can be drawn on a Screen.
///

#include "Line.h"
#include <iostream>
#include <cassert>
#include <utility>
#include <string>
#include <sstream>

using namespace std;

// constructs a line
//
// \param[in] row1 the row of the first end point
// \param[in] column1 the column of the first end point
// \param[in] row2 the row of the second end point
// \param[in] column2 the column of the second end point
// \param[in] ch the drawing character
// \throw invalid_line_error if the line is not horizontal or vertical
Line::Line(int row1, int column1, int row2, int column2, char ch) 
  : m_row1(row1), m_col1(column1), m_row2(row2), m_col2(column2), m_ch(ch)
{  
  if (!(m_row1 == m_row2 || m_col1 == m_col2)) {
    throw invalid_line_error("The line is not horizontal or vertical.");
  }
}

// draws the line on the given Screen
//
// \param[in,out] screen the screen to draw in
// \throw invalid_coordinates_error if the object does not fit on the screen
void Line::draw(Screen &screen)
{
  if (m_row1 == m_row2) {
    // horizontal line
    for (int col = min(m_col1, m_col2); col <= max(m_col1, m_col2); col++) {
      screen.set(m_row1, col, m_ch);
    }
  } else {
    // vertical line
    for (int row = min(m_row1, m_row2); row <= max(m_row1, m_row2); row++) {
      screen.set(row, m_col1, m_ch);
    }
  }
}

// reads a description of the line from input stream.  The row and
// columns of the two end points, as well as the drawing character
// are specified on one line of input separated by spaces.
//
// \param[in,out] is the input stream to read from
// \throw input_format_error if the user input does not satisfy the correct format
void Line::read(istream &is)
{
  string input_line;
  getline(is, input_line);

  istringstream iss(input_line);
  
  if (!(iss >> m_row1 >> m_col1 >> m_row2 >> m_col2 >> m_ch)) {
    throw input_format_error("Invalid input format for Line.");
  }

  // check to see if there is any trailing stuff
  string s;
  if (iss >> s) {
    throw input_format_error("Invalid input format for Line.");
  }

  if (!(m_row1 == m_row2 || m_col1 == m_col2)) {
    throw invalid_line_error("The line is not horizontal or vertical.");
  }
}

