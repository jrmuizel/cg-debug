#include "CGSInternal.h"

int main(int argc, char **argv) {
	if (argc < 2)
		exit(1);
	if (!strcmp(argv[1], "surface")) // write out to /tmp/WindowServer.sinfo.out
		CGSSetDebugOptions(kCGSDebugOptionDumpSurfacesToFile);
}
