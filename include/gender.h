#pragma once

// Includes

// Includes

// STL Includes
#include <string>
// STL Includes
enum class Gender
{
    Male = 0,
    Female = 1,
    NA = 2
};
Gender convert_int_toGender(int num);
std::string convert_gender_toString(Gender gender);