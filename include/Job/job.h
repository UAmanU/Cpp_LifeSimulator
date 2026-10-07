#pragma once

// Includes
#include "Job/job_types.h"
// Includes

// STL Includes

// STL Includes

/*Job is a struct without any methods.
It contains JobType , int salary and int energy_per_day.
Job is usually owned by class Human (which is declared in include/Human/human.h).
Job struct makes sense for adding money to human and spending his energy.*/

struct Job
{
    JobType job_type;
    int salary;
    int energy_per_day;
    Job(int salary = 0, JobType job_type = JobType::NA, int energy_per_day = 50);
    ~Job() = default;
};