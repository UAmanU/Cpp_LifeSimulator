#pragma once

// Includes
#include "human.h"

// Includes

// STL Includes
#include <string>

// STL Includes

void greeting();
void goodbye();
void print_error(std::string msg);
void print_character_stats(const Human &human);
void print_work_message(const Human &human);
void print_sleep_message(const Human &human);
void print_datasave_result(bool result);