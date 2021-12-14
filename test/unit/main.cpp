/*****************************************************************************

      main.cpp
      Copyright (c) 2020 Raphael DINGE

*Tab=3***********************************************************************/



/*\\\ INCLUDE FILES \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

#include "TestAnimation.h"
#include "TestDebounce.h"
#include "TestSdramPtr.h"

#include <iostream>



/*\\\ FUNCTIONS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

/*
==============================================================================
Name : main
==============================================================================
*/

int main ()
{
   std::cout << "Running Unit Tests" << std::endl;

   std::cout << "   Running TestDebounce..." << std::endl;
   { TestDebounce test; test.run (); }

   std::cout << "   Running TestAnimation..." << std::endl;
   { TestAnimation test; test.run (); }

   std::cout << "   Running TestSdramPtr..." << std::endl;
   { TestSdramPtr test; test.run (); }

   std::cout << "OK" << std::endl;
}



/*\\\ EOF \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
