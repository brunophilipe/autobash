//
//  types.h
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

#ifndef autobash_types_h
#define autobash_types_h

typedef long BPCommand;

enum {
	kBPCommandDebug		= 1<<0,
	kBPCommandAdd		= 1<<1,
	kBPCommandRemove	= 1<<2,
	kBPCommandList		= 1<<3,
	kBPCommandHelp		= 1<<4,
	kBPCommandRun		= 1<<5
};

typedef short bool;

#define true 1
#define false 0

bool debug;

#endif
