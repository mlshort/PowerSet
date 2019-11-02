/**
* @file       PowerSet_Main.cpp
* @brief      Main source file for the PowerSet assignment
* @mainpage
* @author     Mark L.Short
* @date       January 26, 2017
*
* <b>Course:</b>     CSCE 5370 Theory of Computation
*
* <b>Instructor : </b> Dr. Steven Minsker
*
* <b>Assignment : </b>
*
*   Write a computer program in the language of your choice which reads in a single
*   non-negative integer N as input and produces as output the power set of
*   {I, 2, 3, ... , N}, written one subset per output line.
*
* <b> Implementation : </b>
*
* I think we can agree that there are C( n, k ) number of k-subsets of an n-element set,
*
* Where:
*
*     a k-subset of X is a subset of X consisting of k number of elements; and,
*     C( n, k ) = n!/ ( ( n - k )! * k!)
*
* Suppose <b>N</b> is a positive integer and <b>S</b> is a set of integers { 1, 2, ..., N },
* I assert that the Power Set of <b>S</b> is actually the set of all of the k-subsets of <b>S</b> for k = 0 to N;
*
* Suppose that <b>N</b> = 5, the Power Set of <b>S</b> is:
*
*   P( S ) = { { 0-subsets }, { 1-subsets }, { 2-subsets }, { 3-subsets }, { 4-subsets }, { 5-subsets } };
*
* Where:
*
*       0-subsets = { O }
*
*       1-subsets = { { 1 }, { 2 }, { 3 }, { 4 }, { 5 } }
*
*       2-subsets = { { 1, 2 }, { 1, 3 }, { 1, 4 }, { 1, 5 }, { 2, 3 }, { 2, 4 },
*                     { 2, 5 }, { 3, 4 }, { 3, 5 }, { 4, 5 } }
*
*       3-subsets = { { 1, 2, 3 }, { 1, 2, 4 }, { 1, 2, 5 }, { 1, 3, 4 }, { 1, 3, 5 },
*                     { 1, 4, 5 }, { 2, 3, 4 }, { 2, 3, 5 }, { 2, 4, 5 }, { 3, 4, 5 } }
*
*       4-subsets = { { 1, 2, 3, 4 }, { 1, 2, 3, 5 }, { 1, 2, 4,  5 }, { 2, 3, 4, 5 } }
*
*       5-subsets = { { 1, 2, 3, 4, 5 } }
*/


#include "stdafx.h"
#include <stdlib.h>
#include <fstream>
#include "PowerSet.h"


int _tmain( int argc, TCHAR *argv[] )
{
    unsigned int iArgv = 0;

    if ( argc <= 1 )
    {
        tcout << _T("Please enter size of the target Set") << std::endl;
        tcout << _T("> ");
        tcin  >> iArgv;
        tcin.get();  // discard the remaining newline.
    }
    else
    {
        iArgv = static_cast<unsigned int>( _ttoi64( argv[1] ));
    }

    if (iArgv != 0)
    {

#ifdef USE_CONSOLE
        ComputeAndPrintPowerSet( tcout, iArgv );

       tcout << _T("Press any key to exit") << std::endl;
       tcin.get();
#else
       tofstream of( _T( ".\\..\\Data\\PowerSet_Output.txt" ) );

       if (of)
       {
           ComputeAndPrintPowerSet( of, iArgv );
           tcout << _T("PowerSet successfully generated and outputted to target file!!") << std::endl;
       }
       else
       {
           tcout << _T("Unable to open output file!") << std::endl;
       }

       of.close();

       tcout << _T("Press any key to exit") << std::endl;
       tcin.get();
#endif

    }

    return 0;
}

