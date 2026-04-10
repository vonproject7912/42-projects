*This project has been created as part of the 42 curriculum by <mosriji>.*

# fractol


# Description

**fractol** is a small computer graphics project that renders beautiful fractals using the **MiniLibX** graphical library.

The objective of this project is to:
- Learn how to use a graphical library
- Work with **complex numbers**
- Understand fractal mathematics
- Handle **keyboard and mouse events**
- Practice graphical rendering and optimization

The program calculates fractals using the **escape-time algorithm** and displays them pixel by pixel in a window.

Currently implemented fractals:
- **Mandelbrot Set**
- **Julia Set**

The Julia set can be customized using parameters passed through the command line.

---

# Features

- Rendering of **Mandelbrot** and **Julia** fractals
- **Zoom in / Zoom out** using the mouse wheel
- **Smooth color gradients**
- Custom **Julia parameters**
- Proper window handling
- Clean exit using **ESC** or window close button

---

# Instructions

**Requirements:**
- Linux with X11 (or WSL with an X server like VcXsrv)
- MiniLibX (minilibx-linux)
- gcc, make

**Compilation:**
regular make.

**Execution:**

Mandelbrot set:
```./fractol mandelbrot```

Julia set (requires two float parameters for the complex constant):

```./fractol julia <real> <imaginary>```

Example:
```./fractol julia -0.7 0.27```

---

# Resources

- [MiniLibX Linux documentation](https://harm-smits.github.io/42docs/libs/minilibx)
- [Mandelbrot set — Wikipedia](https://en.wikipedia.org/wiki/Mandelbrot_set)
- [Julia set — Wikipedia](https://en.wikipedia.org/wiki/Julia_set)
- [Smooth coloring algorithm](https://en.wikipedia.org/wiki/Plotting_algorithms_for_the_Mandelbrot_set#Continuous_(smooth)_coloring)
- [Complex number arithmetic](https://en.wikipedia.org/wiki/Complex_number)
- [Julia render protypes examples](https://paulbourke.net/fractals/juliaset/)

**AI Usage:**
Claude (Anthropic) was used during this project for:
- Clarifying complex number arithmetic and fractal iteration formulas
- Debugging compilation errors (implicit declarations, static linkage issues)
- Understanding pixel-to-complex-plane coordinate mapping using a scaling function
- Explaining the MiniLibX hook system and how to pass a struct through `void *param`
```
