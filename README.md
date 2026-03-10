# Parallel Matrix Multiplication with HPX

A high-performance implementation of **parallel matrix multiplication** using the **HPX C++ runtime system**.  
This project demonstrates how modern **asynchronous task-based parallelism** can significantly accelerate computational workloads by distributing matrix operations across multiple CPU cores.

The implementation uses **HPX's lightweight threads and futures** to efficiently schedule and execute matrix multiplication tasks, showcasing how parallelism can be applied to classical numerical algorithms.

---

## Overview

Matrix multiplication is a fundamental operation used in many domains such as:

- Scientific computing
- Machine learning
- Computer graphics
- Data analysis
- Simulation systems

However, multiplying large matrices sequentially can be computationally expensive. This project leverages **HPX's parallel execution model** to perform matrix multiplication more efficiently by dividing the workload into concurrent tasks.

---

## Key Features

- **Task-based Parallelism**  
  Uses HPX’s lightweight threads to execute matrix computations concurrently.

- **Efficient Work Distribution**  
  Splits matrix operations into smaller units that can be executed in parallel.

- **Scalable Performance**  
  Utilizes multiple CPU cores to improve computation speed for large matrices.

- **Modern C++ Parallel Runtime**  
  Demonstrates practical use of the HPX library for high-performance computing applications.

---

## Tech Stack

- **Language:** C++
- **Parallel Runtime:** HPX
- **Build System:** CMake
- **Execution Model:** Asynchronous task-based parallelism


---

## How It Works

The program performs matrix multiplication using a **parallelized approach**:

1. Matrices are initialized with values.
2. The multiplication workload is divided into smaller tasks.
3. HPX schedules these tasks using lightweight threads.
4. Each thread computes a subset of the result matrix.
5. The results are combined to produce the final matrix.

This approach allows multiple matrix elements to be computed simultaneously, reducing total execution time.

---

## Installation

### Prerequisites

Make sure the following tools are installed:

- **C++17 compatible compiler**
- **CMake**
- **HPX library**

Install HPX (example for Linux):

```bash
git clone https://github.com/STEllAR-GROUP/hpx.git
cd hpx
mkdir build && cd build
cmake ..
make
sudo make install
```

## Build
```
mkdir build
cd build
cmake ..
make
```

## Example Use Cases

This project can be useful for:

- Learning **parallel programming in C++**
- Understanding **HPX runtime architecture**
- Experimenting with **high-performance computing techniques**
- Demonstrating **parallel algorithm optimization**

---

## Future Improvements

Possible enhancements include:

- Benchmarking sequential vs parallel performance
- Supporting larger matrix sizes
- Adding performance profiling
- GPU acceleration
- Improved memory optimization

---

## Learning Resources

- **HPX Documentation**  
  https://hpx-docs.stellar-group.org

- **HPX GitHub Repository**  
  https://github.com/STEllAR-GROUP/hpx
