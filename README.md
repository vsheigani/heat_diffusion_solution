# 1D Heat Diffusion — Crank-Nicolson Solver

Numerical simulation of the one-dimensional heat equation using the **Crank-Nicolson implicit finite-difference scheme**. The solver is implemented in C++ and produces output data files that can be visualized with Gnuplot.

## Physics

The 1D heat equation solved here is:

$$\frac{\partial u}{\partial t} = \frac{\partial^2 u}{\partial x^2}$$

with Dirichlet boundary conditions $u(0,t) = u(L,t) = 0$ and a user-selected initial condition $u(x,0)$.

## Method

The Crank-Nicolson scheme discretizes the equation as a half-implicit, half-explicit step. This yields a tridiagonal linear system at each time step, solved using the **Thomas algorithm** (tridiagonal matrix algorithm).

**Numerical parameters:**

| Parameter | Value |
|-----------|-------|
| Spatial domain | $[0, 10]$ |
| Time domain | $[0, 8]$ |
| Spatial points (`nx`) | 80 |
| Time steps (`nt`) | 1000 |
| $\Delta x$ | 0.125 |
| $\Delta t$ | 0.008 |
| $\sigma = \Delta t / (2\Delta x^2)$ | ~0.256 |

## Initial Conditions

Three initial profiles are available, selected at runtime:

| Argument | Profile |
|----------|---------|
| `gaussian` | Biquadratic pulse: $(10x - 4)^2 (6 - 10x)^2$ |
| `sin` | Sinusoidal: $\sin(x)$ |
| `quadratic` | Gaussian bell: $e^{-80(x-8)^2}$ |

## Requirements

- C++ compiler (`g++`)
- `make`
- [Gnuplot](http://www.gnuplot.info/) (for visualization)

## Build & Run

### Using the convenience script

```bash
# Create the output directory (required once)
mkdir -p dataFiles

# Build, run, and get plotting instructions
./run_simulation.sh gaussian   # or: sin | quadratic
```

### Manual steps

```bash
# Build
make

# Run (choose one initial condition)
./CrankNicolson gaussian
./CrankNicolson sin
./CrankNicolson quadratic

# Plot results
gnuplot plot.gnu        # outputs graph.pdf
```

### Clean build artifacts

```bash
make clean
```

## Output

The solver writes temperature snapshots every 50 time steps to the `dataFiles/` directory:

```
dataFiles/results_50.dat
dataFiles/results_100.dat
...
dataFiles/results_1000.dat
```

Each `.dat` file contains two columns:

```
x_position    u(x, t)
```

The Gnuplot script `plot.gnu` reads these files and produces a multi-curve PDF (`graph.pdf`) showing the evolution of the temperature profile over time.

## Project Structure

```
.
├── CrankNicolson.cpp   # Solver source (Thomas algorithm + Crank-Nicolson time-stepping)
├── Makefile            # Build rules
├── plot.gnu            # Gnuplot visualization script
├── run_simulation.sh   # End-to-end build + run script
└── dataFiles/          # Generated output data (created before first run)
```

## Reference

Thomas algorithm implementation adapted from:
> Boudreau, J. F. & Swanson, E. S., *Applied Computational Physics*, Oxford University Press.
