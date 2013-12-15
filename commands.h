//
//  commands.h
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
