#pragma once

// Includes

// Includes

// STL Includes
#include <string>
// STL Includes

/*in this file, there is a declaration of all types of Jobs in enum class JobType. 
Also, there're 2 functions for converting this enum class to string and string to JobType.
JobType is owned by job struct (which is declared in include/Job/job.h).
It makes sense for better game logic.
For example: worker Alex , worker Goodman ---> cashier Alex , medic Goodman.*/

enum class JobType
{
    driver,
    counsellor,
    cashier,
    medic,
    cook,
    waiter,
    NA
};
std::string convert_jobType_toString(JobType job_type);
JobType convert_string_toJobType(const std::string &job_name);