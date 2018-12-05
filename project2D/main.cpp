#include "Application2D.h"
#include "CDDSBinaryTreeApp.h"

int main() 
{
	
	// allocation
	auto app = new CDDS_BinaryTreesApp();

	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}