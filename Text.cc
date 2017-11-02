//
// CS 2720 Assignment 1 Solution
//
/// \author Howard Cheng
/// \date September 13, 2017
///
///
/// The Text class is an abstraction of a text string that can be 
/// drawn on a Screen.
///

#include "Text.h"

using namespace std;

// constructs a text object
//
// \param[in] row the row of the first character
// \param[in] column the column of the first character
// \param[in] str the string
Text::Text(int row, int column, const string &str)
  : m_row{row}, m_col{column}, m_text{str}
{
}

// draws the Text on the given Screen
//
// \param[in,out] screen the screen to draw in
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
void Text::read(istream &is)
{
  is >> m_row >> m_col >> m_text;
  while (is.peek() != '\n') {
    // eats until the end of line
    is.ignore(1);
  }
  is.ignore();
}

