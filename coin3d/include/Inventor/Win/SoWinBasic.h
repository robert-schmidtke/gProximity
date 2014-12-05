/* src/Inventor/Win/SoWinBasic.h.  Generated automatically by configure.  */
/**************************************************************************
 *
 *  This file is part of the Coin GUI binding libraries.
 *  Copyright (C) 2000 by Systems in Motion.  All rights reserved.
 *
 *  The libraries this file is part of is free software; you can
 *  redistribute them and/or modify them under the terms of the GNU
 *  Lesser General Public License version 2.1 as published by the
 *  Free Software Foundation.  See the file LICENSE.LGPL at the root
 *  directory of the distribution for all the details.
 *
 *  If you want to use the Coin GUI binding libraries for applications
 *  not compatible with the LGPL, contact SIM about acquiring a
 *  Professional Edition License.
 *
 *  Systems in Motion, Prof Brochs gate 6, N-7030 Trondheim, NORWAY
 *  http://www.sim.no/ support@sim.no Voice: +47 22114160 Fax: +47 22207097
 *
 **************************************************************************/

// Generated automatically from SoGuiBasic.h.in by configure.
// $Id: SoWinBasic.h,v 1.1 2008/09/30 19:09:56 zlj Exp $

#ifndef SOWIN_BASIC_H
#define SOWIN_BASIC_H

// *************************************************************************

/* For the Doxygen tool. */
/* FIXME: these Doxygen "tags" should be moved to an internal
   headerfile. 20010810 mortene. */

/*! \defgroup devices Win Device Classes */
/*! \defgroup components Win Components */
/*! \defgroup viewers Win Viewer Components */
/*! \defgroup editors Win Editor Components */
/*! \defgroup slidersets Win Slider Set Components */
/*! \defgroup misc Miscellaneous Classes */
/*! \defgroup common Common Code */

// *************************************************************************

/* Some useful inline template functions (instead of macros):
 *   SoWinMin(Val1, Val2)       - returns minimum value
 *   SoWinMax(Val1, Val2)       - returns maximum value
 *   SoWinClamp(Val, Min, Max)  - returns clamped value
 *   SoWinSwap(Val1, Val2)      - swaps the two values (no return value)
 *
 * FIXME: write Doxygen doc for these methods. 20010810 mortene.
 */

template <class Type>
inline Type SoWinMin(Type a, Type b)
{
	return (b < a) ? b : a;
}

template <class Type>
inline Type SoWinMax(Type a, Type b)
{
	return (b > a) ? b : a;
}

template <class Type>
inline Type SoWinClamp(Type val, Type min, Type max)
{
	return SoWinMax(min, SoWinMin(max, val));
}

template <class Type>
inline void SoWinSwap(Type & a, Type & b)
{
	Type t = a;
	a = b;
	b = t;
}

// *************************************************************************

#define __COIN_SOWIN__

#if ! defined(SOWIN_MAJOR_VERSION)
#define SOWIN_MAJOR_VERSION 0
#endif /* ! SOWIN_MAJOR_VERSION */
#if ! defined(SOWIN_MINOR_VERSION)
#define SOWIN_MINOR_VERSION 9
#endif /* ! SOWIN_MINOR_VERSION */
#if ! defined(SOWIN_MICRO_VERSION)
#define SOWIN_MICRO_VERSION 99
#endif /* ! SOWIN_MICRO_VERSION */
#if ! defined(SOWIN_VERSION)
#define SOWIN_VERSION "0.9.99"
#endif /* ! SOWIN_VERSION */

// *************************************************************************

/* Precaution to avoid an error easily made by the application programmer. */
#ifdef SOWIN_DLL_API
# error Leave the internal SOWIN_DLL_API define alone.
#endif /* SOWIN_DLL_API */

/*
  On MSWindows platforms, one of these defines must always be set when
  building application programs:

   - "SOWIN_DLL", when the application programmer is using the
     library in the form of a dynamic link library (DLL)

   - "SOWIN_NOT_DLL", when the application programmer is using the
     library in the form of a static object library (LIB)

  Note that either SOWIN_DLL or SOWIN_NOT_DLL _must_ be defined by
  the application programmer on MSWindows platforms, or else the
  #error statement will hit. Set up one or the other of these two
  defines in your compiler environment according to how the library
  was built -- as a DLL (use "SOWIN_DLL") or as a LIB (use
  "SOWIN_NOT_DLL").

  (Setting up defines for the compiler is typically done by either
  adding something like "/DSOWIN_DLL" to the compiler's argument
  line (for command-line build processes), or by adding the define to
  the list of preprocessor symbols in your IDE GUI (in the MSVC IDE,
  this is done from the "Project"->"Settings" menu, choose the "C/C++"
  tab, then "Preprocessor" from the dropdown box and add the
  appropriate define)).

  It is extremely important that the application programmer uses the
  correct define, as using "SOWIN_NOT_DLL" when "SOWIN_DLL" is
  correct is likely to cause mysterious crashes.
 */
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
# ifdef SOWIN_INTERNAL
#  ifdef SOWIN_MAKE_DLL
#   define SOWIN_DLL_API __declspec(dllexport)
#  endif /* SOWIN_MAKE_DLL */
# else /* !SOWIN_INTERNAL */
#  ifdef SOWIN_DLL
#   define SOWIN_DLL_API __declspec(dllimport)
#  else /* !SOWIN_DLL */
#   ifndef SOWIN_NOT_DLL
#    error Define either SOWIN_DLL or SOWIN_NOT_DLL as appropriate for your linkage! See Inventor/Win/SoWinBasic.h for further instructions.
#   endif /* SOWIN_NOT_DLL */
#  endif /* !SOWIN_DLL */
# endif /* !SOWIN_MAKE_DLL */
#endif /* Microsoft Windows */

/* Empty define to avoid errors when _not_ compiling an MSWindows DLL. */
#ifndef SOWIN_DLL_API
# define SOWIN_DLL_API
#endif /* !SOWIN_DLL_API */

#endif // ! SOWIN_BASIC_H
