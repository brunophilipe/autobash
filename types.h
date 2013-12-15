//
//  types.h
//  autobash
//
//  Created by Bruno Philipe on 12/15/13.
//  Copyright (c) 2013 Bruno Philipe. All rights reserved.
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
