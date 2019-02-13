# multiplot
Multiplot is a very easy to use, single-header C++ tool  for plotting auto-scaling curves / scatter plots. 

Multiplot homepage: http://www.andre-krause.net/multiplot

<img src="http://www.andre-krause.net/multiplot/multiplot.png">

With MultiPlot, you can easily plot simple graphs like line- and scatter plots in C++.
It is a single - header library with zero dependencies under win32.

For other platforms, the small, lightweight and statically linkable FLTK toolkit (<a href="http://www.fltk.org">www.FLTK.org</a>) is used to create an OpenGL Window.  
It uses <a href="http://www.opengl.org">www.opengl.org</a> for plotting.

Simply include multiplot.h and start plotting. 
Add points with their coordinates (x,y) and optionally their colors (r,g,b) and MULTIPLOT does the rest for you.
It scales automatically such that the whole graph fits to the window.

## here is a minimal C++ example:

#include "multiplot.h"
using namespace multiplot;

```cpp
void main()
{
	// create a multiplot Window at position (x,y)=(50,50) and width=640, height=480
	Multiplot m(50, 50, 640, 480);	
	m.show(); 

	// and plot a sine wave
	for(int x=0; x<10000; x++)
	{
		m.plot(x, sin(0.1 * x) );
		m.redraw();
		m.check(); // event propagation
	}
}
```

## install prerequisites
under linux, Multiplot uses the Fast Light Toolkit ( https://www.fltk.org/ ) to create an OpenGL context. 

### Fedora:
```console
sudo dnf install fltk-devel
```
### Debian based Linux (Ubuntu, Linux Mint etc.):
```console
sudo apt-get install libfltk1.3-dev
```
## compile
```console
g++ -std=c++14 test_multiplot.cpp -lfltk -lfltk_gl -lGL
```
