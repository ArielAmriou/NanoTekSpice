# NanoTekSpice

## Overview

NanotekSpice is an Epitech project whose goal is to simulate an electronical circuit of chipsets.

https://github.com/user-attachments/assets/e1e36918-e653-440d-b467-3a0720b68901 \
[Basic installation](#installation)

https://github.com/user-attachments/assets/995c21de-2328-41b8-b350-70e163a867b1 \
[Graphic installation](#graphic-usage)

## Features

This project present the next features:
- Integrated shell
- Simulation of components

## Getting Started

### Prerequisites

This project requires the following dependencies:

- **Programming Language:** C++
- **Package Manager:** Cmake
- **Graphic Library:** Sfml

### Installation

Build NanoTekSpice and install dependencies:

1. **Clone the repository:**

```sh
git clone https://github.com/ArielAmriou/NanoTekSpice
```

2. **Navigate to the project directory:**

```sh
cd NanoTekSpice
```

3. **Compile:**

```sh
cmake . && make
```

### Usage

Usage:

```sh
# To use the shell manually
./NanoTekSpice [.nts filepath]
# To automate the input with config file
cat [config filepath] | ./NanoTekSpice [.nts filepath]
```
For exemple:

```sh
./NanoTekSpice ./tests/inputOutput.nts
# Or
cat tests/testCommands/logger | ./nanotekspice tests/testfiles/logger.nts
```

And then use the shell with the following commands:

- [component name]=[0/1/U]: attribute new value to input components.
- display: show the current tick and all inputs / outputs components tristate value value
- simulate: increment the tick and simulate all the new components inputs / outputs.
- loop: enter a infinite loop of simulating and displaying(press ^C to exit).
- exit: quit the program.

For exemple:
```sh
./nanotekspice tests/testfiles/logger.nts 
> clock=0
> simulate
> simulate
> in_128=0
> simulate
> simulate 
> display
tick: 4
input(s): 
  clock: 1
  in_128: 0
output(s): 
> exit
```

### Graphic usage

1. **Move to bonus directory:**
```sh
cd bonus/
```

2. **Compile:**

```sh
cmake . && make
```

3. **Execute:**

```sh
./bonus save/[file].ntsg
```

For exemple

```sh
./bonus save/matrix.ntsg
```

**Keyboard shortcuts:**

- Ctr + Q: Quit
- Ctr + E: Open/Close sidebar
- Ctr + O: Center view-point
- Ctr + Tab: Increment speed
- Ctr + Enter: Pause/Play
- F5: Save current component's states
- Arrows: Change the current view-point position

### Testing
Run the tests with:

```sh
cmake . && make tests_run
```
## Project organisation

. \
├── src/ \
│   ├── Components/ \
│   ├── ComponentFactory.cpp \
│   ├── Main.cpp \
│   ├── Parsing.cpp \
│   ├── Pin.cpp \
│   ├── Shell.cpp \
│   ├── Tristate.cpp \
│   └── Utils.cpp \
├── include/ \
│   ├── Components/ \
│   ├── ComponentFactory.hpp \
│   ├── Connection.hpp \
│   ├── NanoTekSpice.hpp \
│   ├── NtsException.hpp \
│   ├── Parsing.hpp \
│   ├── Pin.hpp \
│   ├── Shell.hpp \
│   ├── Tristate.hpp \
│   └── Utils.hpp \
├── CMakeLists.txt \
├── readme.md \
└── tests/ \

## Roadmap

- ✅ **`Architechture`**: Implement architechture to accomodate simulation and components creation.
- ✅ **`Components`**: Create the 25 required components.
- ✅ **`Graphical`**: Produce a graphical version of the program.

---
