#define __TEST_THIS_MODULE__


//#define MULTIPLOT_FLTK
#include "multiplot.h"
using namespace multiplot;

void minimal_example()
{
	Multiplot m(50, 50, 640, 480);

	for (float x = 0; x<100.0f; x+=1.0f)
	{
		// plot a sine wave
		m.plot(x, sin(0.1f * x));
		m.redraw();
		m.sleep(20);
	}
}


int main()
{
    minimal_example();

    test_module();
    return EXIT_SUCCESS;
}
