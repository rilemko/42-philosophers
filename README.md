<a id="readme-top" name="readme-top"></a>

<!-- ------------------------------
* TITLE, DESCRIPTION & CONTACT
------------------------------ -->
# 🍽️ philosophers

<table>
    <tr>
        <th align="left" width="3333px">Score</th>
        <th align="left" width="3333px">Duration</th>
        <th align="left" width="3333px">Peer(s)</th>
    </tr>
    <tr>
        <td>✅ <b>125</b> / 100</td>
        <td>🕓 2 week(s)</td>
        <td>👷🏻 No</td>
    </tr>
</table>

<br>

This project is a program inspired by the dining philosophers problem. It simulates a situation in which philosophers, represented by **several threads** (**or several processes**), must **share resources** (forks) to eat so as not to die. The aim is to understand **concurrency and synchronization issues**, to avoid **data races**, **deadlocks** or **starvations**, to learn how to use **mutexes** and **semaphores**, and to manage time with great precision.

[**⛓️ FILE : SUBJECT**](en.subject.pdf)

<br>

<!-- ------------------------------
* TABLE OF CONTENTS
------------------------------ -->
## 📋 Table of contents

- [**👀 Overview**](#readme-overview)
- [**📦 Requirements**](#readme-requirements)
- [**💾 Installation**](#readme-installation)
- [**⚡️ Usage**](#readme-usage)
- [**🛠️ Makefile**](#readme-makefile)
- [**📄 License**](#readme-license)

<a id="readme-overview" name="readme-overview"></a>
<p align="right"><b><a href="#readme-top">TOP ⬆️</a></b></p>

<!-- ------------------------------
* OVERVIEW
------------------------------ -->
## 👀 Overview

### Arguments

<table>
    <tr>
        <th align="left" width="500px">Argument</th>
        <th align="left" width="9500px">Description</th>
    </tr>
    <tr><td><code>&ltnumber&gt;</code></td><td>Number of philosophers and forks.</td></tr>
    <tr><td><code>&lttime_to_die&gt;</code></td><td>The time after which a philosopher dies if he doesn't eat.</td></tr>
    <tr><td><code>&lttime_to_eat&gt;</code></td><td>Duration of a meal, during which the philosopher holds two forks.</td></tr>
    <tr><td><code>&lttime_to_sleep&gt;</code></td><td>The time a philosopher spends sleeping.</td></tr>
    <tr><td><code>[must_eat]</code></td><td>The simulation stops if all philosophers have eaten <code>[must_eat]</code> times.</td></tr>
</table>

> **🔵 Info:** The `<time_to_die>` delay begins at the **start** of meals.

> **🟣 Tips:** The `[must_eat]` argument is optional. There is no meal limit if it is not specified.

<a id="readme-requirements" name="readme-requirements"></a>
<p align="right"><b><a href="#readme-top">TOP ⬆️</a></b></p>

<!-- ------------------------------
* REQUIREMENTS
------------------------------ -->
## 📦 Requirements

```
sudo apt -y install clang-12 make
```

<a id="readme-installation" name="readme-installation"></a>
<p align="right"><b><a href="#readme-top">TOP ⬆️</a></b></p>

<!-- ------------------------------
* INSTALLATION
------------------------------ -->
## 💾 Installation

**1. Get the project**

```
git clone https://github.com/rilemko/42-philosophers.git
```

<br>

**2. Build the project**

```
make -j$(nproc)
```

> **🔵 Info:** The `philo_m` and `philo_b` executables will be created in the project root directory.

<br>

**3. Run the project**

```
./philo_m <number> <time_to_die> <time_to_eat> <time_to_sleep> [must_eat]
```

```
./philo_b <number> <time_to_die> <time_to_eat> <time_to_sleep> [must_eat]
```

> **🟡 Important:** The `philo_m` executable uses multithreading, while `philo_b` uses multiprocessing.

<a id="readme-usage" name="readme-usage"></a>
<p align="right"><b><a href="#readme-top">TOP ⬆️</a></b></p>

<!-- ------------------------------
* USAGE
------------------------------ -->
## ⚡️ Usage

**Example:**

```console
$ ./philo_m 2 600 200 200
00000000 2 has taken a fork
00000000 2 has taken a fork
00000000 2 is eating
00000000 1 is thinking
00000200 2 is sleeping
00000200 1 has taken a fork
00000200 1 has taken a fork
00000200 1 is eating
00000400 2 is thinking
00000400 1 is sleeping
00000400 2 has taken a fork
00000400 2 has taken a fork
00000400 2 is eating
[...]
```

<br>

**With `[must_eat]` specified:**

```console
$ ./philo_m 2 600 200 200 1
00000000 2 has taken a fork
00000000 2 has taken a fork
00000000 2 is eating
00000000 1 is thinking
00000200 2 is sleeping
00000200 1 has taken a fork
00000200 1 has taken a fork
00000200 1 is eating
```

<a id="readme-makefile" name="readme-makefile"></a>
<p align="right"><b><a href="#readme-top">TOP ⬆️</a></b></p>

<!-- ------------------------------
* MAKEFILE
------------------------------ -->
## 🛠️ Makefile

<table>
    <tr>
        <th align="left" width="1000px">Rule</th>
        <th align="left" width="9000px">Action</th>
        </tr>
    <tr><td><code>all</code></td><td>Compile.</td></tr>
    <tr><td><code>clean</code></td><td>Delete all generated object files</td></tr>
    <tr><td><code>fclean</code></td><td>Apply <code>clean</code>, <code>lclean</code>and delete the executables.</td></tr>
    <tr><td><code>lclean</code></td><td>Apply <code>fclean</code> to all used libraries.</td></tr>
    <tr><td><code>re</code></td><td>Apply <code>fclean</code> and force recompile.</td></tr>
</table>

[**⛓️ FILE : MAKEFILE**](Makefile)

<a id="readme-license" name="readme-license"></a>
<p align="right"><b><a href="#readme-top">TOP ⬆️</a></b></p>

<!-- ------------------------------
* LICENSE
------------------------------ -->
## 📄 License

This project is licensed under the terms of the **MIT** license.

[**⛓️ FILE : LICENSE**](LICENSE.md)

<p align="right"><b><a href="#readme-top">TOP ⬆️</a></b></p>
