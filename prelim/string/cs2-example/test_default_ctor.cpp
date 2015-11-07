//  String class test program
//
//  Tests: XXX
//

#include "string.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main () {
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str1;
	String  str2;
        // VERIFY
	assert(str1 == '\0');
	assert(str1 == "");
	assert(str1 == str2);
    }

    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing default c_tor." << std::endl;

}

