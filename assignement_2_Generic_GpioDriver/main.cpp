

#define ARM 0
#define AVR 1

#define HARDWARE [AVR or ARM] // Have to choose

#if HARDWARE == 0
	#include "ARM_class.h"
#elif HARDWARE == 1
	#include "AVR_class.h"
#else
	#error "Unknown hardware type!"
#endif

int main(void)
{
	return 0;
}
