#pragma once

// Includes

// Includes

// STL Includes
#include <string>
// STL Includes

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