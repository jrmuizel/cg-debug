#include <stdint.h>
typedef int32_t CGDisplayCoord;
#include "CGSInternal.h"

void dump_options()
{
	int options;
	CGSGetDebugOptions(&options);
	printf("%x\n", options);
#define OPTION_NAME(a) if (options & a) printf(#a "\n");
	OPTION_NAME(kCGSDebugOptionNone);
	OPTION_NAME(kCGSDebugOptionFlashScreenUpdates);
	OPTION_NAME(kCGSDebugOptionColorByAccelleration);
	OPTION_NAME(kCGSDebugOptionNoShadows);
	OPTION_NAME(kCGSDebugOptionNoDelayAfterFlash);
	OPTION_NAME(kCGSDebugOptionAutoflushDrawing);
	OPTION_NAME(kCGSDebugOptionShowMouseTrackingAreas);
	OPTION_NAME(kCGSDebugOptionFlashIdenticalUpdates);
}

int main(int argc, char **argv) {
	if (argc > 1) {
                if (!strcmp(argv[1], "opaque")) {
                    printf("setting opaque\n");
                    CGSSetDebugOptions(kCGSDebugOptionColorByAccelleration);
                }
		if (!strcmp(argv[1], "surface")) {
			printf("dumping surfaces to /tmp/WindowServer.sinfo.out\n");
			CGSSetDebugOptions(kCGSDebugOptionDumpSurfacesToFile);
		}
		if (!strcmp(argv[1], "color")) {
			// color profiles
			CGSSetDebugOptions(kCGSDebugOptionDumpColorProfileInfoToFile);
		}
		if (!strcmp(argv[1], "shmem")) {
			// shmeminfo
			CGSSetDebugOptions(kCGSDebugOptionDumpShmemInfoToFile);
		}

		if (!strcmp(argv[1], "flash")) {
			CGSSetDebugOptions(kCGSDebugOptionFlashScreenUpdates);
		}

		if (!strcmp(argv[1], "clear")) {
			CGSSetDebugOptions(kCGSDebugOptionNone);
		}
		if (!strcmp(argv[1], "window")) {
			CGSSetDebugOptions(kCGSDebugOptionDumpWindowListToFile);
		}

		/*! Dumps a very verbose debug log of the WindowServer to /tmp/CGLog_WinServer_<PID>. */
		if (!strcmp(argv[1], "vlog")) {
			printf("starting verbose log\n");
			CGSSetDebugOptions(kCGSDebugOptionVerboseLogging);
		}
	}
	dump_options();
}
