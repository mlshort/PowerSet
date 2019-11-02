/**
* @file       PowerSet.h
* @brief      ComputeAndPrintPowerSet implementation
* @author     Mark L.Short
* @date       January 26, 2017
*
* <b>Course:</b>     CSCE 5370 Theory of Computation
* <b>Instructor : </b> Dr. Steven Minsker
*
*/
#include "stdafx.h"
#include "PowerSet.h"

tostream& ComputeAndPrintPowerSet( tostream& os, size_t nNumElements )
{
    // Instantiate and Initialize Target Set
    std::vector<unsigned short> rgTargetSet( nNumElements );

    unsigned short wCtr = 0;
    for ( auto &j : rgTargetSet )
        j = wCtr++;

    os << _T("The Power Set of: ") << std::endl;
    PrintSet( os, rgTargetSet ) << _T(" is:") << std::endl;
    os << _T("----------------------------------------") << std::endl;

    // Calculate and Output
    for ( int i = static_cast<int>(nNumElements); i > 0; i-- )
    {
        std::vector<unsigned short> rgSubSet( i );

        // initialize the 1st k-SubSet combination
        unsigned short wCtr2 = 0;
        for ( auto &k : rgSubSet )
            k = wCtr2++;

        // Generate and Output the subsequent k-element SubSets
        bool bNextCombination = true;
        while ( bNextCombination )
        {
            PrintSet ( os, rgSubSet ) << std::endl;
            bNextCombination = NextCombination( rgSubSet, nNumElements );
        }
    }

// Output the empty set
    os << " { } " << std::endl;

    return os;
}