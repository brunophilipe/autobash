//
//  main.c
//  autobash
//
//  Created by Bruno Philipe on 12/14/13.
//  Copyright (c) 2013 Bruno Philipe. All rights reserved.
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

    return 0;
}

/**
 Writes the help messages. Placed here to unclutter the `main()` function.
 */
void showHelpMessages()
{
	printf("\n"BOLD"autobash version 1.0 – www.brunophilipe.com\n"RESET);
	printf("usage: autobash [flag] file\n\n");
	printf("Flags:\n");
	printf("\t(no flags) source_file\n\t\tRuns the bash file with the parameter name.\n\t\tThis bash must be in the autobash library.\n\n");
	printf("\t[-a|--add] source_file\n\t\tAdds the parameter file to the autobash library.\n\n");
	printf("\t[-r|--remove] bash_name\n\t\tRemoves the parameter bash from the autobash library.\n\t\tThis name should not contain an extension.\n\n");
	printf("\t[-l|--list]\n\t\tLists the bash files currently in the autobash library.\n\n");
	printf("\t[-h|--help]\n\t\tShows this help.\n\n");
	printf("Example:\n");
	printf("\tautobash --add ./myscript.sh\n\t\tAdds myscript.sh to the autobash library with the name myscript.\n\n");
	printf("\tautobash myscript\n\t\tRuns the bash file with the name myscript.\n\n");
	printf("\tautobash --remove myscript\n\t\tRemoves the myscript bash from the autobash library.\n\n");
}
