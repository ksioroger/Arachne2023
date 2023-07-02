#include <stdio.h>
#include "/usr/arachne/arachne-all/Arachne/src/Arachne.h"

void numberPrinter(int n) {
	printf("NumberPrinter says %d\n", n);
}

// This is where user code should start running.

void AppMain(int argc, const char** argv) {
	printf("Arachne says hello world and creates a thread.\n");
	auto tid = Arachne::createThread(numberPrinter, 5);
	Arachne::join(tid);
}

// The following bootstrapping code should be copied verbatim into most Arachn
// applications.
void AppMainWrapper(int argc, const char** argv) {
	AppMain(argc, argv);
	Arachne::shutDown();
}
int main(int argc, const char** argv){
	Arachne::init(&argc, argv);
	Arachne::createThread(&AppMainWrapper, argc, argv);
	Arachne::waitForTermination();
}
