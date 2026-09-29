// Includes
#include "gender.h"
// Includes

// STL Includes

// STL Includes

Gender convert_int_toGender(int num)
{
    switch (num)
    {
    case 0:
        return Gender::Male;
    case 1:
        return Gender::Female;
    case 2:
        return Gender::NA;
    }
    return;
}