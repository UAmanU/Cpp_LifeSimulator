#pragma once

// Includes

// Includes

// STL Includes
#include <string>
// STL Includes

/*enum class Gender is like the JopType one (which is declared in include/job/job_types.h)
It means that we can do instead of human Alex, human Olivia do man Alex and woman Olivia.
Gender-type objects are usually owned by class Human-type objects (class Human is declared in include/human/human.h)
Gender::NA is used as a default construction. For example, we created an Human-type object , but we didn't send a Gender value into a constructor.
In this case, Human::gender will be set as a Gender::NA.*/

enum class Gender
{
    Male = 0,
    Female = 1,
    NA = 2
};
Gender convert_int_toGender(int num);
std::string convert_gender_toString(Gender gender);