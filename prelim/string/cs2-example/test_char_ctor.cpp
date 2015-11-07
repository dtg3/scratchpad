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
        String  str1('a');
	String  str2('a');
        // VERIFY
	assert(str1 == 'a');
	assert(str2 == "a");
	assert(str1 == str2);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str1('a');
	String  str2('b');
        // VERIFY
	assert(str1 == 'a');
	assert(str2 == "b");
	assert(!(str1 == str2));

	assert('a' == str1);
	assert("b" == str2);
	assert(!(str2 == str1));
    }

    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing char c_tor." << std::endl;

}

