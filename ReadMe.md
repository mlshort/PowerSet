NAME: <b>Power Set Project</b>

  DIRECTORY STRUCTURE: 
===============================================================================

\Power Set
+ --- \PowerSetProject  (source)
+ --- \Bin              (compiled executable)
+ --- \Data             (output data file)
+ --- \Documentation    (implementation documentation)
+ --- \Obj              (discardable binary intermediaries)

DESCRIPTION:         see below  
DATE WRITTEN:        January 26, 2017  

  PowerSet Project Overview
===============================================================================

 Assignment CSCE 5370 Theory of Computation:

   Write a computer program in the language of your choice which reads in a single
   non-negative integer N as input and produces as output the power set of
   {I, 2, 3, ... , N}, written one subset per output line.

 Implementation
===============================================================================

 I think we can agree that there are C( N, K ) number of K-subsets of an <b>N</b>-element set,

 Where:

     a K-subset of a set (containing N elements) is a subset of consisting 
     of K number of elements; and,
     C( N, K ) = N! / ( ( N - K )! * K!)

 Suppose <b>N</b> is a positive integer and <b>S</b> is the set of integers { 1, 2, ..., <b>N</b> }
 
 I assert that the Power Set of <b>S</b> is actually the set of all of the k-subsets of 
 <b>S</b> for k = 0 to <b>N</b>;

 Consider that <b>N</b> = 5, then the Power Set of <b>S</b> is:

     P( S ) = { { 0-subsets }, 
                { 1-subsets }, 
                { 2-subsets }, 
                { 3-subsets }, 
                { 4-subsets }, 
                { 5-subsets } };

 Where:

       0-subsets = { O } (the empty set)

       1-subsets = { { 1 }, { 2 }, { 3 }, { 4 }, { 5 } }

       2-subsets = { { 1, 2 }, { 1, 3 }, { 1, 4 }, { 1, 5 }, { 2, 3 }, { 2, 4 },
                     { 2, 5 }, { 3, 4 }, { 3, 5 }, { 4, 5 } }

       3-subsets = { { 1, 2, 3 }, { 1, 2, 4 }, { 1, 2, 5 }, { 1, 3, 4 }, { 1, 3, 5 },
                     { 1, 4, 5 }, { 2, 3, 4 }, { 2, 3, 5 }, { 2, 4, 5 }, { 3, 4, 5 } }

       4-subsets = { { 1, 2, 3, 4 }, { 1, 2, 3, 5 }, { 1, 2, 4,  5 }, { 2, 3, 4, 5 } }

       5-subsets = { { 1, 2, 3, 4, 5 } }

 Reference(s)
===============================================================================

  * Power Set (via wikipedia)
    - https://en.wikipedia.org/wiki/Power_set

  * Combinations (via wikipedia)
    - https://en.wikipedia.org/wiki/Combination