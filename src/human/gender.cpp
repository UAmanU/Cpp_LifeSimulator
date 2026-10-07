// Includes
#include "Include/Human/gender.h"
#include "Include/errors.h"
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
    throw Errors::InvalidDataError("There's no Gender with "+std::to_string(num)+" id.");
}
std::string convert_gender_toString(Gender gender)
{
    switch (gender)
    {
    case Gender::Male:
        return "Male";
    case Gender::Female:
        return "Female";
    case Gender::NA:
        return "NA";
    }
    throw Errors::InvalidDataError("I don't know this Gender type.");
}