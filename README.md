
# 🚍 **Smart Transit - Transport Management System**  

Efficient **Transport Management System (TMS)** designed to streamline **scheduling, coordination, and management** for students, teachers, and staff. The system ensures smooth transport operations with a structured scheduling system and real-time updates.  

---

## 📌 **Project Overview**  

🔹 **Smart Transit** is a **C++-based transport management system** developed using the **Qt Framework** and **SQLite Database**.  
🔹 It enhances **transport logistics, scheduling, and user coordination** to ensure seamless operations.  
🔹 Designed for **educational institutions**, it simplifies **bus tracking, seat allocation, and transport scheduling**.  

This project was developed as part of our **2nd Semester Object-Oriented Programming (OOP) course** at **International Islamic University Chittagong (IIUC)**.  

---

## 👥 **Developed By**  

| Name | Role |  
|------|------|  
| **Mohammed Hasan** | Team Leader & Frontend Developer |  
| **Gazi Shaharabi Anwar Tuhin** | UI/UX Developer |  
| **Shuvo Nath** | Backend Developer |  

---

## 🛠 **Technologies Used**  

| Technology | Purpose |  
|------------|---------|  
| **C++** | Core programming language |  
| **Qt Framework** | GUI development & application logic |  
| **SQLite** | Database for transport scheduling & management |  

---

## 🚀 **Key Features**  

✅ **Schedule Management** – Manage transport schedules for students, teachers, and staff.  
✅ **Real-Time Updates** – Notify users of bus availability, changes, and cancellations.  
✅ **User-Friendly Interface** – Designed for simple navigation and accessibility.  
✅ **Secure Database Integration** – Stores and retrieves transport schedules efficiently.  
✅ **Role-Based Access Control** – Differentiates between students, faculty, and admins.  
✅ **Error Handling & Logging** – Ensures smooth performance and troubleshooting.  

---

## 💻 **System Requirements**  

| Requirement | Details |  
|------------|---------|  
| **Operating System** | Windows / Linux / macOS |  
| **Qt Framework** | Qt 5.12+ (Recommended) |  
| **SQLite** | Pre-installed or bundled with Qt |  
| **C++ Compiler** | MinGW / MSVC / GCC |  

---

## 🏗 **Installation & Setup Guide**  

### 📌 **Prerequisites**  

Ensure you have the following software installed:  
- **Qt Creator** (Qt 5.12+ recommended)  
- **SQLite Database**  
- **C++ Compiler (MinGW/MSVC/GCC)**  

### 🛠 **Steps to Run the Project**  

#### 1️⃣ **Extract the Project Files**  
📂 Download and extract the `OOP Final Project.zip` file.  

#### 2️⃣ **Open the Project in Qt Creator**  
📌 Locate the **`TMS.pro`** file and open it in Qt Creator.  

#### 3️⃣ **Configure the Database Path**  
🛠 Open `mainwindow.cpp` and locate the database connection code.  
✏️ **Update the path of `OOP_BUS.db`** to match the correct location of your database file.  

#### 4️⃣ **Fix Potential Build Errors**  
If you encounter an error such as:  
```cpp
undefined reference to 'MainWindow::on_pushButton_21_clicked()'
```  
📌 **Solution:**  
-  Click on the error message, which will navigate you to the problematic section.  
-  **Locate `case 21:` to `case 94:` in your switch statement** and replace them with the correct logic from **`case 21-case 194.txt`**.  
-  Save the file and rebuild the project.  

#### 5️⃣ **Build & Run**  
After making the necessary changes, build and run the project inside **Qt Creator**.  

---

## 🗄️ **Database Structure**  

| Table | Purpose | Fields |  
|-------|---------|--------|  
| `users` | Stores user details | `id, name, role, email, password` |  
| `buses` | Stores bus details | `bus_id, route, driver_name, seats_available` |  
| `schedules` | Stores transport schedules | `schedule_id, bus_id, departure_time, arrival_time` |  
| `bookings` | Stores user bookings | `booking_id, user_id, schedule_id, seat_number` |  

📌 **Note:** The database follows **relational constraints**, ensuring data integrity and **preventing duplicate entries**.  

---

## 🏆 **Project Impact**  

📌 **Enhanced Transport Operations** – The project improves scheduling efficiency and coordination.  
📌 **User Satisfaction** – Real-time updates and a **user-friendly interface** enhance the experience.  
📌 **Optimized Workflow** – The structured approach ensures a **more organized transport system**.  

---

## 🔮 **Future Enhancements**  

🔹 **GPS Tracking** – Integrate real-time bus tracking.  
🔹 **Mobile App Support** – Extend the system to mobile platforms.  
🔹 **Automated Notifications** – Email/SMS alerts for schedule updates.  
🔹 **Advanced User Roles** – Add administrative permissions for better management.  
🔹 **Machine Learning for Route Optimization** – Suggest better transport routes dynamically.  

---

## 📩 **Support & Contact**  

📧 **Email:** [mohammedhasan.contact@gmail.com](mailto:mohammedhasan.contact@gmail.com)  

If you encounter any issues or have feedback, feel free to **open an issue** on GitHub.  

---

## 🔥 **Final Notes**  

- **Security Best Practices:**  
  - Always validate user inputs to prevent SQL Injection.  
  - Use **hashed passwords** for user authentication.  
  - Restrict database access for unauthorized users.  

- **Performance Optimization:**  
  - Optimize database queries for faster execution.  
  - Implement caching for frequently accessed data.  
  - Use multi-threading in Qt for **responsive UI interactions**.  

---
