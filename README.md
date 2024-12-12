# Reactor Simulation Project

This project is a Qt-based application for simulating and visualizing the operation of a nuclear reactor. It includes two main components:

1. **Reactor**: Handles the core physics of the reactor simulation.
2. **ReactorWindow**: Provides a user interface for interacting with the simulation, including dynamic graphs of power and temperature over time.

---

## Features

- **Dynamic Simulation**:
  - Simulates reactor power and temperature changes in real-time.
  - Adjust reactor parameters interactively using a control slider.

- **Visualization**:
  - Graphical representation of power and temperature over time using Qt Charts.
  - Real-time updates to the graphs as the simulation runs.

- **Modular Testing**:
  - Unit tests for the `Reactor` core logic.
  - UI tests for `ReactorWindow` functionality.

---

## Installation

### Prerequisites
- **C++ Compiler**: Ensure you have a modern C++ compiler supporting C++17 or higher.
- **Qt Framework**: Install Qt 5.15 or later with the necessary modules (`QtWidgets`, `QtCharts`, `QtTest`).
- **CMake**: Version 3.15 or later.

### Build Instructions

1. Clone the repository:
   ```bash
   git clone <repository_url>
   cd Reactor
   ```

2. Configure and build the project using CMake:
   ```bash
   mkdir build
   cd build
   cmake .. -DCMAKE_PREFIX_PATH=<path_to_qt>
   make
   ```

3. Run the application:
   ```bash
   ./ReactorApp
   ```

4. To execute tests:
   ```bash
   ctest
   ```

---

## Usage

1. Launch the application.
2. Use the slider to adjust reactor control parameters.
3. Observe real-time updates in the:
   - **Power graph**: Displays power output in megawatts (MW).
   - **Temperature graph**: Displays reactor core temperature in degrees Celsius.
4. Monitor numerical values for power and temperature below the slider.

---

## Testing

### Overview
- **TestReactor**: Validates the core logic of the `Reactor` class, including physics updates and parameter handling.
- **TestReactorWindow**: Ensures the UI components correctly reflect the simulation state and provide the intended interactivity.

### Running Tests
Tests are compiled into separate executables:

1. `QTReactorTests`: Runs the `Reactor` core logic tests.
2. `QTReactorWindowTests`: Runs the UI tests for `ReactorWindow`.

Run them individually:
```bash
./QTReactorTests
./QTReactorWindowTests
```

Or use CTest:
```bash
ctest
```

---

## Project Structure

```
Reactor/
|-- src/                # Source files for the application
|   |-- reactor.h       # Reactor class header
|   |-- reactor.cpp     # Reactor class implementation
|   |-- reactorwindow.h # UI class header
|   |-- reactorwindow.cpp # UI class implementation
|
|-- tests/              # Test files
|   |-- TestReactor.h   # Reactor unit tests header
|   |-- TestReactor.cpp # Reactor unit tests implementation
|   |-- TestReactorWindow.h # UI tests header
|   |-- TestReactorWindow.cpp # UI tests implementation
|
|-- CMakeLists.txt      # Build configuration
```

---

## Future Improvements

- Enhance the physics model with additional reactor parameters.
- Extend test coverage for edge cases and UI responsiveness.

---

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.

---

## Contributing

Contributions are welcome! Please submit a pull request or file an issue for any suggestions or improvements.

---

## Contact

For questions or feedback, please contact **Adrien Pizzo**.
