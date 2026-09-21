#pragma once
// Includes

// Includes

// STL Includes
#include <stdexcept>

// STL Includes

namespace Errors
{
    class StorageError : public std::runtime_error
    {
    public:
        StorageError(const std::string &msg) : std::runtime_error("DataBase exception: " + msg) {};
    };
    class InputError : public std::runtime_error
    {
    public:
        InputError(const std::string &msg) : std::runtime_error("Input Handler exception: " + msg) {};
    };
    class StorageManagerError : public std::runtime_error
    {
    public:
        StorageManagerError(const std::string &msg) : std::runtime_error("Storage Manager exception: " + msg) {};
    };
};