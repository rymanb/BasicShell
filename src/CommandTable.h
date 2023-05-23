#pragma once

#include <string>
#include <unordered_map>
#include <vector>
#include "unistd.h"
#include "shell.h"
#include "status.h"
#include <functional>
#include "functions.h"

typedef std::function<Status(Args)> Command;


class CommandTable
{
  public:
    static CommandTable getInstance();
    Status run(std::string,  Args);

  private:
    CommandTable();
    std::unordered_map<std::string, Command> table;
};