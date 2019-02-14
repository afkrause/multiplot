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

	for (int x = 0; x<200; x++)
	{
		m.plot(x, sin(0.1 * x)); // plot an animated sine wave
		m.redraw();		// redraw the curve
		m.sleep(20); 	// sleep for 20 ms
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
## Compile
```console
g++ -std=c++14 test_multiplot.cpp -lfltk -lfltk_gl -lGL
```

## Documentation
### creating a new figure / window
Create a new plotting window at position (x,y) and with size (width, height):
```cpp
int x = 150, y = 50;
int w = 640, h = 480;
Multiplot m(x,y,w,h);
```

### adding datapoints to a plot
You can add individual points to a graph:
```cpp
for(int x = 0; x<100; x++)
{
	m.plot(x, sin(0.1*x);
	m.redraw();
}
```
redraw() refreshes the graph and draws it to the window. You can consider speeding up the process by e.g. redrawing only every tenth or hundreth frame: if(x % 100){m.redraw();}. Or you can slow down the process by sleeping for a specified amount of milliseconds: m.sleep(100) sleeps for 100ms. 

### using data stored in std::vector(s)

```cpp
auto vy = vector<float>{0, 1, -1, 2, -2, 3, -3};
m.plot(vy);
m.redraw();
```
x-values run from 0 .. size(vy).
You can also store x and y values in two vectors and plot those values: 

```cpp
vector<float> vx, vy;
vx.resize(100); vy.resize(100);
for(int i = 0; i<100; i++)
{
	vx[i] = sin(0.1*i);
	vy[i] = sin(0.3*i);
}
m.plot(vx, vy);
m.redraw();
```

