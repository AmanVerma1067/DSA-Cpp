# DSA-Cpp

**Fundamentals of Data Structures & Algorithms in C++ with Code Examples & Notebooks**

This repository contains essential concepts, code examples, and interactive Jupyter notebooks to help you master Data Structures and Algorithms (DSA) in C++. The materials are suitable for beginners as well as intermediate learners, with explanations, annotated `.cpp` files, and interactive `.ipynb` notebooks powered by C++ kernels.

---

## 📂 Repository Structure

- `*.cpp` — Standalone C++ code files for each topic/example
- `*.ipynb` — Jupyter notebooks with C++ (xeus-cling) code and explanations

---

## 🚀 Getting Started

### 1. **Explore the Notebooks Online (Recommended!)**

You can run the C++ Jupyter notebooks in your browser **without any local installation** using [Binder](https://mybinder.org):

[![Open in Binder](https://mybinder.org/badge_logo.svg)](https://mybinder.org/v2/gh/AmanVerma1067/DSA-Cpp/HEAD?labpath=)

- Click the badge or [this link](https://mybinder.org/v2/gh/AmanVerma1067/DSA-Cpp/HEAD?labpath=).
- Wait for the Binder environment to launch.
- Open any `.ipynb` notebook and execute C++ code interactively!

> **Note:** Binder might take a few minutes to start the environment for the first time.

---

### 2. **Run Notebooks Locally with `xeus-cling` (Jupyter C++ Kernel)**

If you want to run the notebooks on your own computer:

#### a. **Install Miniconda/Anaconda**  
Download and install from [here](https://docs.conda.io/en/latest/miniconda.html).

#### b. **Create a new conda environment and install `xeus-cling`:**

```bash
conda create -n dsa-cpp-notebooks -c conda-forge xeus-cling notebook jupyterlab
conda activate dsa-cpp-notebooks
```

#### c. **Launch Jupyter Lab:**

```bash
jupyter lab
```

- Open any `.ipynb` notebook from this repository.
- Make sure to select the **C++17** or **C++ kernel (xeus-cling)** from the kernel menu.

---

### 3. **Run Standalone C++ Files**

- You can compile and run any `.cpp` file using your favorite C++ compiler:
    ```bash
    g++ filename.cpp -o output
    ./output
    ```

---

## 📚 Topics Covered

- Pointers, Arrays, Strings, Linked Lists, Stacks, Queues, Trees, Graphs, Sorting & Searching Algorithms, and more!
- Each concept is explained with C++ code in both script and notebook formats.

---

## ❓ FAQ

**Q: Why do some notebooks not render code/output on GitHub?**  
A: GitHub does not natively render C++ code cells in `.ipynb` files.
- Use Binder or run locally as shown above for the best experience.

---

## 🤝 Contributing

Contributions, bug reports, and suggestions are welcome! Please open an issue or submit a pull request.

---

## 📄 License

This repository is licensed under the [MIT License](LICENSE).

---

**Happy Coding & Learning DSA in C++!**
