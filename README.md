# Hostel-Room-Allocation-System
A Hostel Room Allocation System implemented in C that assigns hostel rooms to students based on their preferences and room availability. The project demonstrates core data structures, dynamic memory management, and algorithm design.

Features:
1) Student registration and preference handling
2) Room allocation based on availability and priority
3) Dynamic tracking of room occupancy
4) Handling unallocated students using queues
5) Modular design with separate functions for each operation

Technologies used:
1) C Programming Language
2) Data Structures<br>
    a)Structures (struct)<br>
    b)Dynamic Arrays<br>
    c)Queues (for waiting list handling)<br>


How It Works:
1) Students enter their room preferences.
2) The system checks room availability.
3) Rooms are allocated based on:<br>
    a)Preference priority<br>
    b)Availability<br>
4) If no rooms are available:<br>
    a)Students are added to a waiting queue.
5) When rooms are freed:<br>
    a)Waiting students are reallocated.

Running the project:<br>
The following steps should be followed to compile the code and then run it: (For windows)<br>
1) gcc main.c source.c -o hostel_app<br>
This creates the hostel_app.exe file that is an executable that should be ran
2) ./hostel_app.exe<br>
This runs the executable file