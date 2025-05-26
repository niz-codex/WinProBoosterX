# ⚡ WinProBoosterX v1.0.0

> Advanced Windows Optimization CLI Tool  
> 🔧 Developed with love by **Nizath**   
> 📅 Version: `1.0.0` | 🖥️ Platform: Windows | 👨‍💻 Language: C

---

## 🧠 Overview

**WinProBoosterX** is a lightweight, fast, and powerful Windows system optimization utility developed in C. It focuses on:

- Cleaning junk and temp files
- Network performance tuning
- System latency reduction
- Built-in repair tools (DISM + SFC)
- Enhanced gaming and productivity experience

It’s built for enthusiasts, gamers, and professionals who want **maximum performance** with minimal bloat.

---

## ⚙️ Features

| Feature                   | Description                                                                 |
|--------------------------|-----------------------------------------------------------------------------|
| 🧹 **System Cleaner**     | Cleans `%TEMP%`, `C:\Windows\Temp`, flushes DNS, enables performance tweaks |
| 🌐 **Network Optimizer**  | Disables TCP auto-tuning, Nagle Algorithm, and boosts interface responsiveness |
| 🕹️ **Low Latency Mode**   | Disables mouse acceleration, unparks CPU cores for ultra-smooth performance |
| 🛠️ **System Repair**      | Runs `DISM` and `SFC` to fix corrupted Windows components                  |
| 📜 **EULA Viewer**        | View full End User License Agreement                                        |
| 🔐 **Authentication**     | Simple built-in password protection (`admin123` by default)                |

---

## 🛡️ Requirements

- ✅ Windows 10 or 11 (Admin Rights Required)
- ✅ C Compiler (e.g., GCC via MinGW)
- ✅ Run as Administrator to apply system-level changes

---

## 🚀 Installation

### 🔧 Build from Source

bash
```
git clone https://github.com/yourusername/WinProBoosterX.git
cd WinProBoosterX
gcc -o WinProBoosterX WinProBoosterX.c
```
