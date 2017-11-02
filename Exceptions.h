//
// CS 2720 Assignment 2 Solution
//
/// \author Howard Cheng
/// \date October 17, 2017
///
///
/// This file contains a number of exception classes for the drawing program.
///

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>

using namespace std;

///
/// This is an exception to be thrown when coordinates are out of bounds.
///
class invalid_coordinates_error : public runtime_error
{
public:
  /// constructs the exception
  ///
  /// \param[in] arg a string containing a message
  invalid_coordinates_error(const string &arg)
    : runtime_error(arg) {}
};

///
/// This is an exception to be thrown when the user input for the
/// ScreenElement class does not satisfy the correct format
///
class input_format_error : public runtime_error
{
public:
  /// constructs the exception
  ///
  /// \param[in] arg a string containing a message
  input_format_error(const string &arg)
    : runtime_error(arg) {}
};

///
/// This is an exception to be thrown when a line that is neither
/// vertical nor horizontal is constructed
///
class invalid_line_error : public runtime_error
{
public:
  /// constructs the exception
  ///
  /// \param[in] arg a string containing a message
  invalid_line_error(const string &arg)
    : runtime_error(arg) {}
};

///
/// This is an exception to be thrown when a screen is needed but not
/// yet created.
///
class invalid_screen_error : public runtime_error
{
public:
  /// constructs the exception
  ///
  /// \param[in] arg a string containing a message
  invalid_screen_error(const string &arg)
    : runtime_error(arg) {}
};


#endif
