//
//  commands.h
//  autobash
//
//  Created by Bruno Philipe on 12/14/13.
//  Copyright (c) 2013 Bruno Philipe. All rights reserved.
//

#include "types.h"

#ifndef autobash_commands_h
#define autobash_commands_h

/**
 Decodes the command string format into a `BPCommand` variable.
 
 The transformation values for the `input` parameter are described below:

 "--debug" or "-d" returns `BPCommandDebug`
 "--add" or "-a" returns `BPCommandAdd`
 "--remove" or "-r" returns `BPCommandRemove`
 "--list" or "-l" returns `BPCommandList`
 "--help" or "-h" returns `BPCommandHelp`
 
 @returns A `BPCommand` value as decribed above.
 */
BPCommand commands_getCommandForString(const char *input);

/**
 This function iterates through an array of strings in search of commands using the `commands_getCommandForString(1)` function. Whenever it finds one, it adds it to the return value using the bitwise C OR operator.
 */
BPCommand commands_getCommandsForMainInput(int argc, const char * argv[]);

#endif
