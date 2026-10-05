#pragma once

// Includes

// Includes

// STL Includes
#include <string>

// STL Includes

/*Input Handler - is a module without any structure, it's like set of tools for controlling the std::cin thread.
Input_handler is often used with Display handler (which is declared in include/GUI/display_handler.h).
Their functions are usually called by ProgrammLauncher class (which is declared in include/programm_launcher.h)*/

void clear_cin();
int choose_action();
std::string name_form();
int gender_form();
