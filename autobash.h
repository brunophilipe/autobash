//
//  autobash.h
//  autobash
//
//  Created by Bruno Philipe on 12/15/13.
//  Although not necessary, any feedback or attribution to the usage of this software is welcome!
//
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

#ifndef autobash_autobash_h
#define autobash_autobash_h

#define LIBRARY_PATH "~/.autobash/library"

/**
 Runs a bash file from the library. The file name must match the parameter name without the extension.
 
 For example: calling `autobash_runFile("test")` will call the `test.sh` file from the library.
 
 @param name The name of the file to be executed.
 */
void autobash_runFile(const char *name);

/**
 Imports a file to the library. The parameter path must be a valid path to a file.
 
 @param path The path to the file to be imported.
 @returns `true` if the import was successful, `no` otherwise.
 */
bool autobash_importFile(const char *path);

/**
 Deletes a bash file from the library. The parameter name must match a bash file without the extension.
 
 For example, calling `autobash_deleteFile("test")` will delete the `test.sh` file from the library.
 
 @param The name of the bash file to be deleted without the extension.
 @returns `true` if the file could be deleted, `no` otherwise.
 */
bool autobash_deleteFile(const char *name);

/**
 Produces a list of the files currently present in the libary.
 */
void autobash_listFiles();

#endif
