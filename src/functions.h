#pragma once

#include <string>
#include <vector>
#include "status.h"
#include "unistd.h"

typedef std::vector<std::string> Args;

Status exit_f(Args args);
Status cd_f(Args args);
Status pwd_f(Args args);
Status ls_f(Args args);
Status mkdir_f(Args args);
Status rmdir_f(Args args);
Status rm_f(Args args);
Status mv_f(Args args);
Status cp_f(Args args);
Status cat_f(Args args);
Status ln_f(Args args);
Status chmod_f(Args args);
Status chown_f(Args args);
Status chgrp_f(Args args);
Status touch_f(Args args);
Status grep_f(Args args);
Status ps_f(Args args);
Status kill_f(Args args);
Status clear_f(Args args);

Status run_program(Args args);
Status help_f(Args args);