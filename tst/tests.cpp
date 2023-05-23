#include "gtest/gtest.h"
#include "shell.h"
#include "status.h"

// Test the Shell::execute() method.
TEST(ShellExecuteTest, Exit)
{
    Shell shell;
    Status status = shell.execute("exit");
    EXPECT_EQ(status, Status::EXIT);
}

TEST(ShellExecuteTest, Cd)
{
    Shell shell;
    Status status = shell.execute("cd /home");
    EXPECT_EQ(status, Status::SUCCESS);
}

TEST(ShellExecuteTest, Ls)
{
    Shell shell;
    Status status = shell.execute("ls");
    EXPECT_EQ(status, Status::SUCCESS);
}

TEST(ShellExecuteTest, Pwd)
{
    Shell shell;
    Status status = shell.execute("pwd");
    EXPECT_EQ(status, Status::SUCCESS);
}

TEST(ShellExecuteTest, Mkdir)
{
    Shell shell;
    Status status = shell.execute("mkdir test");
    EXPECT_EQ(status, Status::SUCCESS);
}

TEST(ShellExecuteTest, Rmdir)
{
    Shell shell;
    Status status = shell.execute("rmdir test");
    EXPECT_EQ(status, Status::SUCCESS);
}

TEST(ShellExecuteTest, Rm)
{
    Shell shell;
    Status status = shell.execute("rm test");
    EXPECT_EQ(status, Status::SUCCESS);
}

TEST(ShellExecuteTest, Mv)
{
    Shell shell;
    Status status = shell.execute("mv test test2");
    EXPECT_EQ(status, Status::SUCCESS);
}

TEST(ShellExecuteTest, Cp)
{
    Shell shell;
    Status status = shell.execute("cp test test2");
    EXPECT_EQ(status, Status::SUCCESS);
}

TEST(ShellExecuteTest, Cat)
{
    Shell shell;
    Status status = shell.execute("cat test");
    EXPECT_EQ(status, Status::SUCCESS);
}

TEST(ShellExecuteTest, Ln)
{
    Shell shell;
    Status status = shell.execute("ln test test2");
    EXPECT_EQ(status, Status::SUCCESS);
}

TEST(ShellExecuteTest, Chmod)
{
    Shell shell;
    Status status = shell.execute("chmod 777 test");
    EXPECT_EQ(status, Status::SUCCESS);
}

TEST(ShellExecuteTest, Chown)
{
    Shell shell;
    Status status = shell.execute("chown root test");
    EXPECT_EQ(status, Status::SUCCESS);
}

TEST(ShellExecuteTest, Chgrp)
{
    Shell shell;
    Status status = shell.execute("chgrp root test");
    EXPECT_EQ(status, Status::SUCCESS);
}

TEST(ShellExecuteTest, Touch)
{
    Shell shell;
    Status status = shell.execute("touch test");
    EXPECT_EQ(status, Status::SUCCESS);
}

TEST(ShellExecuteTest, Grep)
{
    Shell shell;
    Status status = shell.execute("grep test test");
    EXPECT_EQ(status, Status::SUCCESS);
}

TEST(ShellExecuteTest, Ps)
{
    Shell shell;
    Status status = shell.execute("ps");
    EXPECT_EQ(status, Status::SUCCESS);
}

TEST(ShellExecuteTest, Kill)
{
    Shell shell;
    Status status = shell.execute("kill 1");
    EXPECT_EQ(status, Status::SUCCESS);
}

TEST(ShellExecuteTest, Clear)
{
    Shell shell;
    Status status = shell.execute("clear");
    EXPECT_EQ(status, Status::SUCCESS);
}




