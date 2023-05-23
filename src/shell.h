#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "status.h"

// unix
#include <unistd.h>

#include "CommandTable.h"

class Shell
{
public:



    static void run();
    static Status execute(std::string input);


};


