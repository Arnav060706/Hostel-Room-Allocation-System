#ifndef HOSTEL_H
#define HOSTEL_H

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    int pref1;
    int pref2;
} student;

typedef struct 
{
    int *rooms;             
    student *student_queue; 
    int MAX_ROOMS;
    int curr_top;           
} Hostel;

student addStudent(Hostel *hostel, int id, int pref1, int pref2);
int assignRoom(Hostel *hostel);
int freeRoom(Hostel *hostel, int id);
int viewMap(Hostel *hostel);
void initHostel(Hostel *hostel, int total_rooms);
void cleanupHostel(Hostel *hostel);
int swapRooms(Hostel *hostel, int id1, int id2);
void Heatmap(Hostel *hostel);

#endif