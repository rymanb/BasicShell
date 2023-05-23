#include "shell.h"
#include <sys/wait.h>
#include <unistd.h>



void Shell::run()
{
    std::string input;
    Status status = Status::SUCCESS;

    // print initial prompt with welcome message basic commands such as exit and help, and credits
    // surround with a box
    std::cout << "\033[1;34m";
    std::cout << "+--------------------------------------+" << std::endl;
    std::cout << "|         Welcome to the shell         |" << std::endl;
    std::cout << "|  Type \"help\" for a list of commands  |" << std::endl;
    std::cout << "|    Type \"exit\" to exit the shell     |" << std::endl;
    std::cout << "|       Created by Ryman Barnett       |" << std::endl;
    std::cout << "+--------------------------------------+" << std::endl;
    std::cout << std::endl;
    std::cout << "\033[0m";




    do {
        // current working directory
        char cwd[1024];
        getcwd(cwd, sizeof(cwd));

        // user name
        char *username = getenv("USER");

        char* hostname = new char[1024];
        gethostname(hostname, 1024);



        // print prompt
        std::cout << "\033[1;32m";
        std::cout << username << "@" << hostname << ":\033[1;34m" << cwd << "\033[0m$ ";


        std::getline(std::cin, input);
        status = Shell::execute(input);
    } while (status != Status::EXIT);
}

Status Shell::execute(std::string input)
{
    std::vector<std::string> args;
    std::string arg;
    Status status = Status::SUCCESS;

    for (char c : input)
    {
        if (c == ' ')
        {
            args.push_back(arg);
            arg = "";
        }
        else
        {
            arg += c;
        }
    }

    args.push_back(arg);


    status = CommandTable::getInstance().run(args[0], args);

    if (status == Status::FAILURE)
    {
        status = CommandTable::getInstance().run("run", args);
    }


    return status;
}
