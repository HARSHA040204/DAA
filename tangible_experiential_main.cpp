#pragma once

#include <string>
#include <vector>
#include "ans.h"

int main(int argc, char **argv)
{
	std::vector<std::wstring> args(argv + 1, argv + argc);
	Experiential::main(args);
}

