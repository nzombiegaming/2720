//
// CS 2720 Assignment 2 Solution
//
/// \author Howard Cheng
/// \date October 17, 2017
///
///
/// The TextBox class is an abstraction of a rectangular box containing
/// a text string that can be drawn on a Screen.
///

#include "TextBox.h"
#include "Exceptions.h"
#include <sstream>

using namespace std;

// constructs a TextBox
//
// \param[in] row the row of the first character
// \param[in] column the column of the first character
// \param[in] ch the drawing character for the box
// \param[in] str the string
TextBox::TextBox(int row, int column, char ch, const string &str) noexcept
  : Text(row, column, str), 
    Box(row-1, column-1, row+1, column+str.length(), ch)
{
}

// draws the TextBox on the given Screen
//
// \param[in,out] screen the screen to draw in
// \throw invalid_coordinates_error if the object does not fit on the screen
void TextBox::draw(Screen &screen)
{
  Text::draw(screen);
  Box::draw(screen);
}

// reads a description of the TextBox from input stream.  The row
// and column of the first character, the drawing character of the
// box, as well as the string are specified on one line of input
// separated by spaces.
//
// \param[in,out] is the input stream to read from
// \throw input_format_error if the user input does not satisfy the correct format
void TextBox::read(istream &is)
{
  string input_line;
  getline(is, input_line);
  istringstream iss(input_line);

  char ch;
  if (!(iss >> m_row >> m_col >> ch >> m_text)) {
    throw input_format_error("Invalid input format for TextBox.");
  }

  // check trailing stuff
  string s;
  if (iss >> s) {
    throw input_format_error("Invalid input format for TextBox.");
  }

  constructLines(m_row-1, m_col-1, m_row+1, m_col + m_text.length(), ch);
}

