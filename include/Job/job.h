#pragma once

// Includes
#include "job_types.h"
// Includes

// STL Includes

// STL Includes

struct Job
{
    JobType job_type;
    int salary;
    int energy_per_day;
    Job(int salary = 0, JobType job_type = JobType::NA, int energy_per_day = 50);
    ~Job() = default;
};