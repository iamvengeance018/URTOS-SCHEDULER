```markdown
# 💡 uRTOS Scheduler – A Mini RTOS Simulation in C++

[![Made with C++](https://img.shields.io/badge/Made%20with-C%2B%2B17-blue?style=for-the-badge&logo=cplusplus)](https://en.cppreference.com/)
[![Platform](https://img.shields.io/badge/Platform-Linux%20Ubuntu-green?style=for-the-badge&logo=linux)]()
[![Status](https://img.shields.io/badge/Project-Complete-brightgreen?style=for-the-badge)]()
[![License](https://img.shields.io/badge/License-MIT-yellow?style=for-the-badge)]()

---

> 🧵 Simulating an operating system scheduler from scratch in C++ using `std::thread`, `std::mutex`, and smart task logic.

---

## 🎯 Objective

Build a **mini RTOS scheduler** that can:
- 🚦 Manage tasks with Round-Robin & Priority scheduling
- ⏱ Handle preemptive time-slicing
- 🚫 Simulate task blocking & resuming
- 📝 Log all task events to a file for debugging

---

## 📁 Folder Structure

```

rtos\_project/
├── include/
│   └── scheduler.h
├── src/
│   ├── main.cpp
│   └── scheduler.cpp
├── tasks/
│   ├── task1.cpp
│   ├── task2.cpp
│   └── task\_config.h
├── Makefile
└── urtos\_log.txt  # Auto-generated

````

---

## 🧠 Concepts Used

- 🧵 `std::thread` — Task-level concurrency  
- 🔒 `std::mutex`, `std::lock_guard` — Thread synchronization  
- ⏳ `this_thread::sleep_for()` — Simulated execution time  
- 📄 `std::ofstream` — Logging to `urtos_log.txt`  
- 🧰 Makefile — Compilation automation

---

## 🔧 Build & Run

> 📌 Tested on Ubuntu/Linux VM with `g++` and `make`.

### 🔨 Compile

```bash
make
````

### 🧼 Clean

```bash
make clean
```

### ▶️ Run

```bash
./urtos
```

### 📖 View Logs

```bash
cat urtos_log.txt
```

---

## 📌 Example Output

```
Task1 is running for 300 ms...
Task1 is paused at 300 ms
Task2 is running for 300 ms...
Task2 is completed after 600 ms
Task1 is running for 300 ms...
Task1 is completed after 900 ms
```

---

## ✨ Features Table

| 🔧 Feature                       | ✅ Status    |
| -------------------------------- | ----------- |
| Task Registration                | ✅ Completed |
| Round-Robin Scheduling           | ✅ Completed |
| Priority-Based Scheduling        | ✅ Completed |
| Preemptive Time-Sliced Execution | ✅ Completed |
| Blocking & Unblocking            | ✅ Completed |
| Logging System (`urtos_log.txt`) | ✅ Completed |
| Mutex/Thread Safety              | ✅ Completed |

---

## 🚀 Future Ideas

* 📊 Gantt-style Task Timeline Visualizer
* 🧮 Semaphore & Flag Simulation
* 🧑‍💻 Runtime CLI Scheduler Control
* 🧬 More advanced scheduling strategies (EDF, SJF...)

---

## 👨‍💻 Author

### **Chandra Sekaran S**

🎓 ECE Undergrad | ⚙️ Embedded Systems Enthusiast | 🧠 RTOS Learner

> Building this RTOS simulation helped me understand OS-level scheduling and real-world embedded constraints using pure C++.

---

## 📜 License

This project is open-source under the [MIT License](LICENSE).

---

⭐ *If you find this project interesting, give it a star on GitHub!*

````

---

## ✅ Next Steps for GitHub

1. Save the file as `README.md` inside your project root directory.
2. In Git Bash / GitHub Desktop:
```bash
git add README.md
git commit -m "Added README.md with badges and details"
git push
````

---
