#pragma once

// Includes
#include "human/human.h"
#include "world/world.h"
// Includes

// STL Includes
#include <string>

// STL Includes

void greeting();
void goodbye();
void print_error(std::string msg);
void print_genders();
void print_world_stats(const World &world);
void print_character_stats(const Human &human);
void print_work_message(const Human &human);
void print_sleep_message(const Human &human);
void print_datasave_result(bool result);