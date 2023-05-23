#include "shell.h"
#include <sys/wait.h>
#include <unistd.h>



void Shell::run()
{
    std::string input;
    Status status = Status::SUCCESS;

    do {
        std::cout << ">> ";
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
        // try to run the command as a program
        pid_t pid = fork();

        if (pid == 0)
        {
            // child process

            int status = 0;
            char* argsl[args.size() + 1];

            for (int i = 0; i < (int)args.size(); i++)
            {
                argsl[i] = (char*) args[i].c_str();
                std::cout << argsl[i] << std::endl;
            }

            argsl[args.size()] = NULL;

            status = execvp(args[0].c_str(), argsl);

            std::cout << status << std::endl;

            if (status == -1)
            {
                std::cout << "Command not found" << std::endl;
                exit(-1);
            }

            exit (0);
        }
        else
        {
            // parent process waits for child to finish
            int status = 0;
            waitpid(pid, &status, 0);

            if (status == -1)
            {
                //std::cout << "Command not found" << std::endl;
            }
        }
    }


    return status;
}
