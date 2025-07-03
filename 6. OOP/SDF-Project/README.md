# Vehicle Management System in C++

This repository contains a C++ implementation of a Vehicle Management System, designed to demonstrate object-oriented programming (OOP) concepts such as inheritance, encapsulation, and polymorphism.

## Features

- **Base Class:** `Car`  
    Encapsulates common attributes like wheels, engine, and colour.

- **Derived Classes:**  
    - `Sedan`: Adds comfort features.
    - `Hatchback`: Includes boot space.
    - `SUV`: Adds ground clearance and length.
    - `Compact_SUV`: Specifies number of seats.
    - `Supercar`: Adds exhaust type and speed.
    - `Hypercar`: Focuses on performance.

## Sample Code Structure

```cpp
class Car { /* ... */ };
class Sedan : public Car { /* ... */ };
class Hatchback : public Car { /* ... */ };
class SUV : public Car { /* ... */ };
class Compact_SUV : public Car { /* ... */ };
class Supercar : public Car { /* ... */ };
class Hypercar : public Car { /* ... */ };
```

## Getting Started

1. **Clone the repository:**
     ```bash
     git clone <repo-url>
     ```
2. **Compile the code:**
     ```bash
     g++ -std=c++11 main.cpp -o vehicle_mgmt
     ```
3. **Run the program:**
     ```bash
     ./vehicle_mgmt
     ```

## Requirements

- C++11 or later
- Standard C++ libraries

## Contributing

Contributions are welcome! Please open issues or submit pull requests for improvements.

## License

This project is licensed under the MIT License.
