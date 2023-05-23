#include "functions.h"
#include <iostream>
#include <filesystem>
#include <sys/stat.h>
#include <fstream>
#include <ostream>
#include <signal.h>
#include <istream>
#include <iterator>

Status exit_f(Args args)
{
  return Status::EXIT;
}

Status cd_f(Args args)
{
  // change directory
  if (args.size() == 1)
  {
    // no arguments, change to home directory
    chdir(getenv("HOME"));
  }
  else if (args.size() == 2)
  {
    // change to the directory specified
    chdir(args[1].c_str());
  }
  else
  {
    // too many arguments
    return Status::FAILURE;
  }

  return Status::SUCCESS;
}

Status pwd_f(Args args)
{
  // print working directory
  char cwd[1024];
  getcwd(cwd, sizeof(cwd));
  std::cout << cwd << std::endl;
  return Status::SUCCESS;
}

Status ls_f(Args args)
{
  // list directory contents (files and subdirectories)
  for (auto &p : std::filesystem::directory_iterator("."))
  {
    std::cout << p.path().filename() << std::endl;
  }
  return Status::SUCCESS;
}

Status mkdir_f(Args args)
{
  // make directory
  if (args.size() == 2)
  {
    // make directory with the name specified
    mkdir(args[1].c_str(), 0777);
  }
  else
  {
    // too many arguments
    return Status::FAILURE;
  }
  return Status::SUCCESS;
}

Status rmdir_f(Args args)
{
  // remove directory
  if (args.size() == 2)
  {
    // remove directory with the name specified
    rmdir(args[1].c_str());
  }
  else
  {
    // too many arguments
    return Status::FAILURE;
  }
  return Status::SUCCESS;
}

Status rm_f(Args args)
{
  // remove file
  if (args.size() == 2)
  {
    // remove file with the name specified
    remove(args[1].c_str());
  }
  else
  {
    // too many arguments
    return Status::FAILURE;
  }
  return Status::SUCCESS;
}

Status mv_f(Args args)
{
  // move file
  if (args.size() == 3)
  {
    // move file with the name specified
    rename(args[1].c_str(), args[2].c_str());
  }
  else
  {
    // too many arguments
    return Status::FAILURE;
  }
  return Status::SUCCESS;
}

Status cp_f(Args args)
{
  // copy file
  if (args.size() == 3)
  {
    // copy file with the name specified
    std::ifstream src(args[1], std::ios::binary);
    std::ofstream dst(args[2], std::ios::binary);
    dst << src.rdbuf();
  }
  else
  {
    // too many arguments
    return Status::FAILURE;
  }
  return Status::SUCCESS;
}

Status cat_f(Args args)
{
  // concatenate files and print on the standard output
  if (args.size() == 2)
  {
    // concatenate file with the name specified
    std::ifstream file(args[1]);
    std::string str;
    while (std::getline(file, str))
    {
      std::cout << str << std::endl;
    }
  }
  else
  {
    // too many arguments
    return Status::FAILURE;
  }

  return Status::SUCCESS;
}

Status ln_f(Args args)
{
  // create a link to a file
  if (args.size() == 3)
  {
    // create a link to a file with the name specified
    symlink(args[1].c_str(), args[2].c_str());
  }
  else
  {
    // too many arguments
    return Status::FAILURE;
  }

  return Status::SUCCESS;
}

Status chmod_f(Args args)
{
  // change file mode bits
  if (args.size() == 3)
  {
    // change file mode bits with the name specified
    chmod(args[1].c_str(), std::stoi(args[2]));
  }
  else
  {
    // too many arguments
    return Status::FAILURE;
  }

  return Status::SUCCESS;
}

Status chown_f(Args args)
{
  // change file owner and group
  if (args.size() == 4)
  {
    // change file owner and group with the name specified
    chown(args[1].c_str(), std::stoi(args[2]), std::stoi(args[3]));
  }
  else
  {
    // too many arguments
    return Status::FAILURE;
  }

  return Status::SUCCESS;
}

Status chgrp_f(Args args)
{
  // change file group ownership
  if (args.size() == 3)
  {
    // change file group ownership with the name specified
    chown(args[1].c_str(), -1, std::stoi(args[2]));
  }
  else
  {
    // too many arguments
    return Status::FAILURE;
  }

  return Status::SUCCESS;
}

Status touch_f(Args args)
{
  // change file timestamps
  if (args.size() == 2)
  {
    // change file timestamps with the name specified
    std::ofstream file(args[1]);
  }
  else
  {
    // too many arguments
    return Status::FAILURE;
  }

  return Status::SUCCESS;
}

Status grep_f(Args args)
{
  // print lines matching a pattern
  if (args.size() == 3)
  {
    // print lines matching a pattern with the name specified
    std::ifstream file(args[2]);
    std::string str;
    while (std::getline(file, str))
    {
      if (str.find(args[1]) != std::string::npos)
      {
        std::cout << str << std::endl;
      }
    }
  }
  else
  {
    // too many arguments
    return Status::FAILURE;
  }

  return Status::SUCCESS;
}

Status ps_f(Args args)
{
  // report a snapshot of the current processes
  if (args.size() == 1)
  {
    // report a snapshot of the current processes
    std::cout << "PID\tTTY\tTIME\tCMD" << std::endl;
    for (auto &p : std::filesystem::directory_iterator("/proc"))
    {
      if (std::filesystem::exists(p.path() / "stat"))
      {
        std::ifstream file(p.path() / "stat");
        std::string str;
        std::getline(file, str);
        std::istringstream iss(str);
        std::vector<std::string> tokens{std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>{}};
        std::cout << tokens[0] << "\t" << tokens[6] << "\t" << tokens[13] << "\t" << tokens[1] << std::endl;

      }
    }
  }
  else
  {
    // too many arguments
    return Status::FAILURE;
  }

  return Status::SUCCESS;
}

Status kill_f(Args args)
{
  // send a signal to a process
  if (args.size() == 3)
  {
    // send a signal to a process with the name specified
    kill(std::stoi(args[1]), std::stoi(args[2]));
  }
  else
  {
    // too many arguments
    return Status::FAILURE;
  }

  return Status::SUCCESS;
}

Status clear_f(Args args)
{
  // clear the screen
  std::cout << "\033[2J\033[1;1H";
  return Status::SUCCESS;
}
