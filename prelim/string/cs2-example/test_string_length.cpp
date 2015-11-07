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
        String  str1("");
	String  str2('\0');
	String  str3;
        // VERIFY
	assert(str1.length() == 0);
	assert(str2.length() == 0);
	assert(str3.length() == 0);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str1('a');
        String  str2("a");

        // VERIFY
       	assert(str1.length() == 1);
       	assert(str2.length() == 1);
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str1("asdfghjklq");

        // VERIFY
	assert(str1.length() == 10);
    }

    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing string length." << std::endl;

}

