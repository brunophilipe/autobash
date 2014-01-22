//
//  commands.c
//  autobash
//
//  Created by Bruno Philipe on 12/14/13.
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.

//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.

//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
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
	else if	(strcmp(input, "--edit") == 0	|| strcmp(input, "-e") == 0) return kBPCommandEdit;
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