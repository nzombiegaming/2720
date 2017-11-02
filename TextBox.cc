//
// CS 2720 Assignment 1 Solution
//
/// \author Howard Cheng
/// \date Sep 13, 2017
///
///
/// The TextBox class is an abstraction of a rectangular box containing
/// a text string that can be drawn on a Screen.
///

#include "TextBox.h"

// constructs a TextBox
//
// \param[in] row the row of the first character
// \param[in] column the column of the first character
// \param[in] ch the drawing character for the box
// \param[in] str the string
TextBox::TextBox(int row, int column, char ch, const string &str)
  : Text{row, column, str}, 
    Box{row-1, column-1,
	row+1, column+static_cast<int>(str.length()), ch}
{
}

// draws the TextBox on the given Screen
//
// \param[in,out] screen the screen to draw in
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
void TextBox::read(istream &is)
{
  char ch;
  is >> m_row >> m_col >> ch >> m_text;
  while (is.peek() != '\n') {
    // eats until the end of line
    is.ignore(1);
  }
  is.ignore();
  constructLines(m_row-1, m_col-1, m_row+1, m_col + m_text.length(), ch);
}

