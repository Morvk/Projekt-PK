#include <iostream>
#include "FileHandling.h"
#include "Network.h"
using namespace std;


int main(int argc, char *argv[])
{
	FileHandling* program = new FileHandling();
	program->checkArguments(argc,argv);
	program->runNetwork();
	
	delete program;
	return 0;
}
