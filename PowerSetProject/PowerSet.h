/**
* @file       PowerSet.h
* @brief      ComputeAndPrintPowerSet API interface
* @author     Mark L.Short
* @date       January 26, 2017
*
* <b>Course:</b>     CSCE 5370 Theory of Computation
* <b>Instructor : </b> Dr. Steven Minsker
*
*/

#pragma once

#if !defined(__POWER_SET_H__)
#define __POWER_SET_H__

#ifndef _IOSTREAM_
    #include <iostream>
#endif
#ifndef _VECTOR_
    #include <vector>
#endif

#ifndef __TCOUT_DEFINED__
#define __TCOUT_DEFINED__
    #if defined(UNICODE) || defined(_UNICODE)
        #define tcout     std::wcout
        #define tcin      std::wcin
        #define tostream  std::wostream
        #define tofstream std::wofstream
    #else
        #define tcout     std::cout
        #define tcin      std::cin
        #define tostream  std::ostream
        #define tofstream std::ofstream
    #endif
#endif


/**
 *  @brief Generates a sequence of numbers using a combinatoric operation
 *
 *  The following function iteratively generates the next combinatoric (lexicographically)
 *  sequence subset from the current sequence using a combinatoric operation.
 *
 *  Basically, it generates an R-element Subset from the set of N Objects in the form of
 *  the sequence(0, 1, 2, ... , nNumObjects - 1).
 *
 *  It is also described as one combination of N objects taken R at a time, where:
 *      N = nNumObjects; and,
 *      R = vSubSet.size()
 *
 *  @param [in,out] vSubSet     reference to vector containing the current sequence subset to
 *                              be used as the source and destination in generating the next
 *                              combinatoric sequence
 *  @param [in] nNumObjects     the number of Objects
 *
 *  @retval true                if there are more combinations
 *  @retval false               if there are no more combinations
 */
template< class _Type >
bool NextCombination( std::vector<_Type>& vSubSet, size_t nNumObjects)
{
    if ( vSubSet.size() < nNumObjects )
    {
        for ( int i = vSubSet.size(); --i >= 0;)
        {
            if ( ++vSubSet[i] <= nNumObjects - ( vSubSet.size() - i ) )
            {
                while ( static_cast<size_t>(++i) < vSubSet.size() )
                    vSubSet[i] = static_cast<_Type>(vSubSet[i - 1] + 1);
                return true;
            }
        }
    }
    return false;
}


/**
 *  @brief Formats and outputs the contents of an std::vector
 *
 *  @param [in,out] os    reference to the destination output stream
 *  @param [in] vSet      reference to the vector to format and output
 *
 *  @retval tostream&     reference to the resultant output stream
 */
template < class _Type >
tostream& PrintSet( tostream& os, const std::vector<_Type>& vSet )
{
    os << _T(" { ");
    for ( auto j : vSet )
    {
        os << j + 1 << _T(" ");
    }
    os << _T("}");

    return os;
}

/**
 *  @brief Calculates and outputs the Power Set, P(S), constructed from a base Set 'S' of N number of unique elements
 *
 *
 *  @param [in,out] os           reference to the destination output stream
 *  @param [in] nNumElements     number of unique elements in the source Set
 *
 *  @retval tostream&            reference to the resultant output stream
 */
tostream& ComputeAndPrintPowerSet( tostream& os, size_t nNumElements );

#endif
