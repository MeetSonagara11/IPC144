// ############################################################################
//
//  Assignment:  1 
//  Milestone:   2
//  Description: Main Application Entry Point
//
// +---------------------------------------------------------+
// | *** The contents of this file is NOT to be modified *** |    
// +---------------------------------------------------------+
//
// ############################################################################


#include <stdio.h>

// include the user library "clinic" where the data types are declared
#include "clinic.h"

#define MAX_PETS 7

int main(void)
{
    struct Patient pets[MAX_PETS] = {
        {1024, "Shaggy Yanson", {"CELL","3048005191"} },
        {1032, "Puglsey Yanson", {"CELL","3048005191"} },
        {1040, "Beans Maulin", {"HOME","3649155831"} },
        {1048, "Banjo Codi", {"TBA",{'\0'}} },
        {1056, "Rover Davidov", {"WORK","7934346809"} }
    };
    struct ClinicData data = { pets, MAX_PETS };

    // Entry point to the application logic:
    menuMain(&data);

    return 0;
}

