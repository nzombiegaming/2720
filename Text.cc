//
// CS 2720 Assignment 2 Solution
//
/// \author Howard Cheng
/// \date October 18, 2017
///
///
/// The Text class is an abstraction of a text string that can be 
/// drawn on a Screen.
///

#include "Text.h"
#include <string>
#include <sstream>

using namespace std;

// constructs a text object
//
// \param[in] row the row of the first character
// \param[in] column the column of the first character
// \param[in] str the string
Text::Text(int row, int column, const string &str) noexcept
  : m_row(row), m_col(column), m_text(str)
{
}

// draws the Text on the given Screen
//
// \param[in,out] screen the screen to draw in
// \throw invalid_coordinates_error if the object does not fit on the screen
void Text::draw(Screen &screen)
{
  for (unsigned int i = 0; i < m_text.length(); i++) {
    screen.set(m_row, m_col + i, m_text[i]);
  }
}

// reads a description of the Text from input stream.  The row and
// column of the first character, as well as the text string
// are specified on one line of input separated by spaces.
//
// \param[in,out] is the input stream to read from
// \throw input_format_error if the user input does not satisfy the correct format
void Text::read(istream &is)
{
  string input_line;
  getline(is, input_line);

  istringstream iss(input_line);
  if (!(iss >> m_row >> m_col >> m_text)) {
    throw input_format_error("Invalid input format for Text.");
  }
  
  // check for trailing stuff
  string s;
  if (iss >> s) {
    throw input_format_error("Invalid input format for Text.");
  }
}

