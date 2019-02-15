#define __TEST_THIS_MODULE__


#include "multiplot.h"
using namespace multiplot;

void minimal_example()
{
	Multiplot m(50, 50, 640, 480);

	for (int x = 0; x<100; x++)
	{
		// plot a sine wave
		m.plot(float(x), sin(0.1f * x));
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
