#include "CommandTable.h"





CommandTable::CommandTable()
{
  // initialize the table
  table["cd"] = cd_f;
  table["exit"] = exit_f;
  table["pwd"] = pwd_f;
  table["ls"] = ls_f;
  table["mkdir"] = mkdir_f;
  table["rmdir"] = rmdir_f;
  table["rm"] = rm_f;
  table["mv"] = mv_f;
  table["cp"] = cp_f;
  table["cat"] = cat_f;
  table["ln"] = ln_f;
  table["chmod"] = chmod_f;
  table["chown"] = chown_f;
  table["chgrp"] = chgrp_f;
  table["touch"] = touch_f;
  table["grep"] = grep_f;
  table["ps"] = ps_f;
  table["kill"] = kill_f;
  table["clear"] = clear_f;
  

}

CommandTable CommandTable::getInstance()
{
  static CommandTable instance;
  return instance;
}

Status CommandTable::run(std::string command, Args args)
{
  if (table.find(command) != table.end())
  {

    return table[command](args);
  }
  else
  {
    return Status::FAILURE;
  }
}