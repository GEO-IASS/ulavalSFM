/*
*	File : util.h
*	Author : Émile Robitaille @ LERobot
*	Creation date : 2014, June 27th
*	Version : 1.0
*	
*	Description : Bunch of useful functions
*/

#ifndef UTIL
#define UTIL

#include "directory.h"

#define VERSION "3.0"

#define BTOS(x) ((x)?"supercomputer":"computer")

/* 
*	Struct : Opts
*	Description : Configuration struct fill after parsing
*	
*	int choice : choice of algorithm(s)
*	unsigned int cores : number of cores to work on
*	bool cluster : on cluster or not
*	char* dir : working directory
*/
struct Opts
{
	int choice;
	int cores;
	int seconds;
	int geo;
	bool cluster;
	util::Directory dir;

	//default constructor
	Opts()
	{
		choice = 0;
		cores = 1;
		seconds = 300;
		geo = 1;
		cluster = false;
	}
};

//Command line functions
void parseArgs(int argc, char* argv[], Opts &o);
void printVersion();
void printHelp();
void printError();
void listDir(const util::Directory &dir);

//MPI distribution functions
int* createDist(const util::Directory &dir, int netSize);
void deleteDist(int* dist);
int* createDist4Match(int numimages, int numcore);
int* createDist4Geometry(int NP, int netSize);

//other util functions
void showProgress(int i, int n, int w, int actualize);
int ffind(FILE* f, const std::string &sr, char* buffer);
void createSubmit(const std::string &path, int numcore, int seconds, int option);

//Bundler functions
void createOptions(const std::string &path);
void Bundler(const std::string &path);

#endif
