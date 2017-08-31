/**
	Copyright (c) 2017 Eudaemon <eudaemonal@gmail.com> 
	test.cpp
	Purpose:

	@author: Eudaemon
	@version:  
*/
/**
	

	@param
	@return 
*/


#include <iostream>
#include "test.h"


class ArrayWrapper
{
    public:
        ArrayWrapper (int n)
            : _p_vals( new int[ n ] )
            , _size( n )
        {}
        // copy constructor
        ArrayWrapper (const ArrayWrapper& other)
            : _p_vals( new int[ other._size  ] )
            , _size( other._size )
        {
            for ( int i = 0; i < _size; ++i )
            {
                _p_vals[ i ] = other._p_vals[ i ];
            }
        }

	
	// move constructor
    	ArrayWrapper (ArrayWrapper&& other)
    	    : _p_vals( other._p_vals  )
    	    , _size( other._size )
  	{
  	      other._p_vals = NULL;
  	      other._size = 0;
  	}

	
        ~ArrayWrapper ()
        {
            delete [] _p_vals;
        }
    private:
    int *_p_vals;
    int _size;
};


int main(int argc, char* argv[]){


	return 0;
}
