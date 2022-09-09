/// \file defines.h
/// \brief Header file for OS dependent things.

#pragma once

#if defined(_MSC_VER) //Microsoft Visual Studio 
  #define WIN32_LEAN_AND_MEAN
  #pragma warning(disable : 4996) //disable annoying security warnings for stdio functions
#endif
