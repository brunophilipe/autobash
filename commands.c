//
//  commands.c
//  autobash
//
//  Created by Bruno Philipe on 12/14/13.
//  Copyright (c) 2013 Bruno Philipe. All rights reserved.
//

#include <stdio.h>
#include <strings.h>

#include "commands.h"

BPCommand commands_getCommandForString(const char *input)
{
	const char *array[1];
	array[0] = input;

		 if (strcmp(input, "--debug") == 0	|| strcmp(input, "-d") == 0) return kBPCommandDebug;
	else if (strcmp(input, "--add") == 0	|| strcmp(input, "-a") == 0) return kBPCommandAdd;
	else if (strcmp(input, "--remove") == 0	|| strcmp(input, "-r") == 0) return kBPCommandRemove;
	else if (strcmp(input, "--list") == 0	|| strcmp(input, "-l") == 0) return kBPCommandList;
	else if	(strcmp(input, "--help") == 0	|| strcmp(input, "-h") == 0) return kBPCommandHelp;
	else return kBPCommandRun;
}

BPCommand commands_getCommandsForMainInput(int argc, const char * argv[])
{
	BPCommand command = 0, test;
	int i;

	for (i=0; i<argc; i++) {
		test = commands_getCommandForString(argv[i]);
		if (test != kBPCommandRun) {
			command |= test;
		}
	}

	return command;
}