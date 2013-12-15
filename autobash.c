//
//  autobash.c
//  autobash
//
//  Created by Bruno Philipe on 12/15/13.
//  Copyright (c) 2013 Bruno Philipe. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <libgen.h>
#include <unistd.h>
#include <wordexp.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/dirent.h>

#include "autobash.h"

void autobash_runFile(const char *name)
{
	char *command;
	char *path;

	path = malloc(sizeof(char)*(strlen(LIBRARY_PATH)+strlen(name)+5));
	sprintf(path, "%s/%s.sh", LIBRARY_PATH, name);

	wordexp_t exp_result;
    wordexp(path, &exp_result, 0); //Expand library path

	if (access(exp_result.we_wordv[0], R_OK) < 0) {
		printf("autobash: could not find bash file named %s!\n",name);
		if (debug) printf("%s\n",exp_result.we_wordv[0]);
		return;
	}

	command = malloc(sizeof(char)*(strlen(exp_result.we_wordv[0])+7));
	sprintf(command, "bash %s", exp_result.we_wordv[0]);

	system(command);

	printf("autobash: process finished!\n");

	free(path);
	free(command);
	wordfree(&exp_result);
}

bool autobash_importFile(const char *path)
{
	char *filename;
	char *name;
	char *command;
	char *destination;

	if (access(path, R_OK) < 0) {
		printf("autobash: file \"%s\" not found!\n",path);
		return false;
	}

	filename = basename((char *)path);
	name = malloc(sizeof(char)*strlen(filename));

	long length = strrchr(filename, '.')-filename;

	if (length <= 0) {
		return false;
	}

	strncpy(name, filename, length);

	name[strlen(name)] = '\0';

	destination = malloc(sizeof(char)*(strlen(LIBRARY_PATH)+strlen(name)+5));
	sprintf(destination, "%s/%s.sh", LIBRARY_PATH, name);

	command = malloc(sizeof(char)*(strlen(path)+strlen(destination)+5));
	sprintf(command, "cp %s %s", path, destination);

	if (debug) printf("Running command: %s\n",command);

	system("mkdir -p ~/.autobash/library/");
	system(command);

	free(name);
	free(destination);
	free(command);

	return true;
}

bool autobash_deleteFile(const char *name)
{
	char *command;
	char *path;

	path = malloc(sizeof(char)*(strlen(LIBRARY_PATH)+strlen(name)+5));
	sprintf(path, "%s/%s.sh", LIBRARY_PATH, name);

	wordexp_t exp_result;
    wordexp(path, &exp_result, 0); //Expand library path

	if (access(exp_result.we_wordv[0], R_OK) < 0) {
		printf("autobash: could not find bash file named %s!\n",name);
		if (debug) printf("%s\n",exp_result.we_wordv[0]);
		return false;
	}

	command = malloc(sizeof(char)*(strlen(exp_result.we_wordv[0])+5));
	sprintf(command, "rm %s", exp_result.we_wordv[0]);

	system(command);

	printf("autobash: bash file %s removed from library.\n",name);

	free(path);
	free(command);
	wordfree(&exp_result);

	return true;
}

void autobash_listFiles()
{
	wordexp_t exp_result;
	DIR *dir;
	struct dirent *ent;

    wordexp(LIBRARY_PATH, &exp_result, 0); //Expand library path

	if (access(exp_result.we_wordv[0], R_OK) < 0) {
		printf("autobash: no files in library.\n");
		if (debug) printf("%s\n",exp_result.we_wordv[0]);
		return;
	}

	char name[256];
	int namelen;

	if ((dir = opendir(exp_result.we_wordv[0])) != NULL) {
		while ((ent = readdir(dir)) != NULL) {
			if (ent->d_name[0] == '.') continue; //skip system files

			namelen = strlen(ent->d_name);

			strncpy(name, ent->d_name, namelen-3);
			name[namelen-3] = '\0';

			printf("\t%s\n", name);
		}
		closedir(dir);
	} else {
		printf("autobash: error opening library directory!\n");
		return;
	}

	wordfree(&exp_result);
}