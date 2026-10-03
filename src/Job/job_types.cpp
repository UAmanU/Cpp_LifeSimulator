// Includes
#include "include/Job/job_types.h"
// Includes

// STL Includes
#include <map>

// STL Includes

JobType convert_string_toJobType(const std::string &job_name)
{
    std::map<std::string, JobType> job_map = {
        {"driver", JobType::driver},
        {"counsellor", JobType::counsellor},
        {"cashier", JobType::cashier},
        {"medic", JobType::medic},
        {"cook", JobType::cook},
        {"waiter", JobType::waiter},
    };
    if (!(job_map.contains(job_name)))
    {
        return JobType::NA;
    }
    return job_map[job_name];
}
std::string convert_jobType_toString(JobType job_type)
{
    switch (job_type)
    {
    case JobType::driver:
        return "driver";
    case JobType::counsellor:
        return "counsellor";
    case JobType::cashier:
        return "cashier";
    case JobType::cook:
        return "cook";
    case JobType::medic:
        return "medic";
    case JobType::waiter:
        return "waiter";
    }
    return "NA";
}