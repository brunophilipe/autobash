//
//  main.c
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

#include "commands.h"
#include "autobash.h"
#include "types.h"
#include "textstyle.h"

void showHelpMessages();

int main(int argc, const char * argv[])
{
	BPCommand command;
	bool cameFromError;

	if (argc == 1) { //No parameter provided, show help!
		command = kBPCommandHelp;
		cameFromError = true;
	}
	else if (argc >= 2)
	{
		command = commands_getCommandForString(argv[1]);
		if (command & kBPCommandDebug) { //First command is --debug
			debug = true;
			if (argc >= 3) { //Try to get a next command
				command = commands_getCommandForString(argv[2]);
			} else { //The only parameter provided was --debug, show help!
				command = kBPCommandHelp;
				cameFromError = true;
			}
		}
	}

	if (debug) {
		printf("Debug: Enabled debug mode! %ld\n",command);
	}

	if (command & kBPCommandRun)
	{
		if (debug) printf("Debug: Entering file-run mode...\n");
		autobash_runFile(argv[(debug ? 2 : 1)]);
	}
	else if (command & kBPCommandAdd)
	{
		if (debug) printf("Debug: Entering file-add mode...\n");
		autobash_importFile(argv[(debug ? 3 : 2)]);
	}
	else if (command & kBPCommandHelp)
	{
		if (debug) printf("Debug: Entering help mode...\n");
		if (cameFromError) printf("autobash: no command provided!\n");
		showHelpMessages();
	}
	else if (command & kBPCommandRemove)
	{
		if (debug) printf("Debug: Entering file-remove mode...\n");
		autobash_deleteFile(argv[(debug ? 3 : 2)]);
	}
	else if (command & kBPCommandList)
	{
		if (debug) printf("Debug: Entering file-list mode...\n");
		autobash_listFiles();
	}
	else if (command & kBPCommandEdit)
	{
		if (debug) printf("Debug: Entering file-edit mode...\n");
		autobash_editFile(argv[(debug ? 3 : 2)]);
	}

	return 0;
}

/**
 Writes the help messages. Placed here to unclutter the `main()` function.
 */
void showHelpMessages()
{
	printf("\n"BOLD);
	printf("               __        __               __  \n");
	printf("  ____ ___  __/ /_____  / /_  ____ ______/ /_ \n");
	printf(" / __ `/ / / / __/ __ \\/ __ \\/ __ `/ ___/ __ \\\n");
	printf("/ /_/ / /_/ / /_/ /_/ / /_/ / /_/ (__  ) / / /\n");
	printf("\\__,_/\\__,_/\\__/\\____/_.___/\\__,_/____/_/ /_/ \nVersion 1.2\n");
	printf(RESET"\n");
	printf("usage: autobash [flag] file\n\n");
	printf("Flags:\n");
	printf("\t(no flags) source_file\n\t\tRuns the bash file with the parameter name.\n\t\tThis bash must be in the autobash library.\n\n");
	printf("\t[-a|--add] source_file\n\t\tAdds the parameter file to the autobash library.\n\n");
	printf("\t[-r|--remove] bash_name\n\t\tRemoves the parameter bash from the autobash library.\n\t\tThis name should not contain an extension.\n\n");
	printf("\t[-l|--list]\n\t\tLists the bash files currently in the autobash library.\n\n");
	printf("\t[-e|--edit] source_file\n\t\tEdits the parameter file with the default editor set in $EDITOR.\n\n");
	printf("\t[-h|--help]\n\t\tShows this help.\n\n");
	printf("Example:\n");
	printf("\tautobash --add ./myscript.sh\n\t\tAdds myscript.sh to the autobash library with the name myscript.\n\n");
	printf("\tautobash myscript\n\t\tRuns the bash file with the name myscript.\n\n");
	printf("\tautobash --remove myscript\n\t\tRemoves the myscript bash from the autobash library.\n\n");
}

