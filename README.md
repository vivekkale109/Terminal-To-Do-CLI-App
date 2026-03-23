# 🧠 CLI To-Do Application (C)

A simple and efficient command-line To-Do application built in **C**.
Manage your daily tasks directly from the terminal with persistent storage.

---

## 🚀 Features

* ✅ Add new tasks
* 📋 List all tasks
* ✔️ Mark tasks as completed
* ❌ Delete tasks
* 💾 Persistent storage using a JSON file
* 🎨 Colored terminal output for better readability
* ⚡ Fast and lightweight (no external dependencies)

---

## 📂 Project Structure

```
.
├── todo.c          # Main source code
├── tasks.json      # Auto-generated task storage
└── README.md       # Project documentation
```

---

## ⚙️ Installation & Setup

### 1. Clone the repository

```bash
git clone https://github.com/vivekkale109/cli-todo-c.git
cd cli-todo-c
```

---

### 2. Compile the program

```bash
gcc todo.c -o todo
```

---

### 3. Run the application

```bash
./todo <command>
```

---

## 📌 Usage

### ➕ Add a task

```bash
./todo add "Learn C programming"
```

### 📋 List all tasks

```bash
./todo list
```

### ✔️ Mark a task as completed

```bash
./todo done 1
```

### ❌ Delete a task

```bash
./todo delete 1
```

---

## 🧪 Example

```bash
$ ./todo add "Build CLI app"
Task added successfully!

$ ./todo list
--- To-Do List ---
1. [ ] Build CLI app

$ ./todo done 1
Task marked as completed!

$ ./todo list
1. [✔] Build CLI app
```

---

## 💾 Data Storage

Tasks are stored in a local file:

```
tasks.json
```

Example:

```json
{"id":1,"title":"Build CLI app","completed":1}
{"id":2,"title":"Push to GitHub","completed":0}
```

---

## ⚠️ Notes

* Do not manually edit `tasks.json` unless necessary
* Max tasks limit is set to 100 (can be increased in code)
* IDs are auto-generated

---

## 🔮 Future Improvements

* ✏️ Edit tasks
* 🔍 Search functionality
* 📅 Due dates & priorities
* 📊 Task statistics
* 🧩 Modular code structure (multiple files)
* 🧪 Unit testing
* 🛠️ Makefile support
* 🎨 Interactive terminal UI (ncurses)

---

## 🤝 Contributing

Contributions are welcome!

1. Fork the repo
2. Create a new branch
3. Make changes
4. Submit a pull request

---

⭐ If you like this project, consider giving it a star!
