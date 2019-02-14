#define __TEST_THIS_MODULE__

#define MULTIPLOT_FLTK
#ifndef _WIN32
#define MULTIPLOT_FLTK
#endif

#include "multiplot.h"

int main()
{

	// minimal example
	{
		Multiplot m(50, 50, 640, 480);

		// and plot a sine wave
		for (int x = 0; x<200; x++)
		{
			m.plot(x, sin(0.1 * x));
			m.redraw();
			m.sleep(20);
		}
	}

    test_module();
    return EXIT_SUCCESS;
}
