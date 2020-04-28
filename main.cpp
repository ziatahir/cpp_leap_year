#include <iostream>
#include "validateYear.h"
using namespace std;


namespace
{
    struct usage_exception {};

    //! Cast `int` to `unsigned int` or throw `invalid_argument` if it is negative
    unsigned int to_uint(int n)
    {
        if (n < 0)
        {
            const auto msg = to_string(n) + " is negative.";
            throw invalid_argument{ msg };
        }

        return static_cast<unsigned int>(n);
    }
}

int main(int argc, char* argv[]){
   const auto year_signed = stoi(argv[1]);
   const auto year = to_uint(year_signed);

  bool flag = leapYear(year);
   if(flag == true)
      std::cout<<year<<" is a leap Year\n";
   else
      std::cout<<year<<" is not a leap Year\n";
   return 0;
}

