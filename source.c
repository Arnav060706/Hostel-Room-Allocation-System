#include "hostel.h"

student addStudent(Hostel *hostel, int id, int pref1, int pref2) 
{
    hostel->curr_top++;
    hostel->student_queue = realloc(hostel->student_queue, hostel->curr_top * sizeof(student));
    hostel->student_queue[hostel->curr_top - 1].id = id;
    hostel->student_queue[hostel->curr_top - 1].pref1 = pref1;
    hostel->student_queue[hostel->curr_top - 1].pref2 = pref2;
    return hostel->student_queue[hostel->curr_top - 1];
}

int assignRoom(Hostel *hostel) 
{   
    if ((hostel->curr_top)==0)
    {
        printf("Queue is Empty!!");
        return -1;
    }
    student *student_with_no_room_queue=malloc(hostel->curr_top * sizeof(student));
    int student_with_no_room_count=0;
    int student_remaining_count=0;
    int flag=0;
    for (int i=0; i<(hostel->curr_top);i++)
    {
        student stu=hostel->student_queue[i];
        if (hostel->rooms[stu.pref1-1]==0)
        {
            hostel->rooms[stu.pref1-1]=stu.id;
            printf("Assigned Student %d to Room %d a/c to their prefernce-1\n", stu.id, stu.pref1);
            continue;
        }
        else if (hostel->rooms[stu.pref2-1]==0)
        {
            printf("Student:%d of preference-1 Room:%d already assigned to someone else\n",stu.id,stu.pref1);
            hostel->rooms[stu.pref2-1]=stu.id;
            printf("Assigned Student %d to Room %d a/c to their prefernce-2\n", stu.id, stu.pref2);
            continue;
        }
        else
        {
            printf("No Rooms have been found for student:%d a/c to their prefernce-1 and 2\n",stu.id);
            student_with_no_room_queue[student_with_no_room_count]=stu;
            student_with_no_room_count++;
        }
        
    }
    for (int i = 0; i < student_with_no_room_count; i++)
    {
        student stu=student_with_no_room_queue[i];
        int flag=0;
        for (int j=0; j<hostel->MAX_ROOMS; j++)
        { 
            if (hostel->rooms[j]==0)
            {
                hostel->rooms[j]=stu.id;
                flag=1;
                printf("Assigned Student %d to Room %d\n",stu.id,j+1);
                break;
            }
        }
        if (!flag) 
        {
            printf("No Room is available for Student %d\n",stu.id);
            student_remaining_count++;
        }
    }
    free(student_with_no_room_queue);
    hostel->curr_top=0;
    return student_remaining_count;
}

int freeRoom(Hostel *hostel, int id) 
{
    for (int i = 0; i < hostel->MAX_ROOMS; i++) 
    {
        if (hostel->rooms[i] == id) 
        {
            hostel->rooms[i] = 0;
            return i+1;
        }
    }
    return 0;
}

int viewMap(Hostel *hostel) 
{
    int count_Empty=0;
    printf("===============ROOMS================\n");
    for (int i = 0; i < hostel->MAX_ROOMS; i++) 
    {
        if (hostel->rooms[i] == 0) 
        {
            printf("ROOM %d is EMPTY\n", i + 1);
            count_Empty++;
        }

        else printf("ROOM %d is occupied by Student %d\n", i + 1, hostel->rooms[i]);
    }
    printf("===============END==================\n");
    return count_Empty;
}

void initHostel(Hostel *hostel, int total_rooms) 
{
    hostel->MAX_ROOMS = total_rooms;
    hostel->rooms = calloc(total_rooms, sizeof(int));  
    hostel->student_queue = NULL;                      
    hostel->curr_top = 0;
}

void cleanupHostel(Hostel *hostel) 
{
    free(hostel->rooms);
    free(hostel->student_queue);
}

int swapRooms(Hostel *hostel, int id1, int id2)
{
    int Student_id1=-1,Student_id2=-1;
    for (int i = 0; i < hostel->MAX_ROOMS; i++) 
    {
        if (hostel->rooms[i] == id1) Student_id1=i;

        if (hostel->rooms[i] == id2) Student_id2=i;
    }

    if (Student_id1==-1 || Student_id2==-1) 
    {
        printf("Invalid Student ID!\n");
        return 0;
    }

    else
    {    
        hostel->rooms[Student_id1]=id2;
        hostel->rooms[Student_id2]=id1;
        return 1;
    }
}

void Heatmap(Hostel *hostel)
{
    int *heatmap = calloc(hostel->MAX_ROOMS, sizeof(int));  
    if (hostel->curr_top==0)
    {
        printf("Student Queue is Empty! NO HeatMap available\n");
        return;
    }
    for (int i=0;i<(hostel->curr_top);i++)
    {
        student stu=hostel->student_queue[i];
        heatmap[stu.pref1-1]+=1;
        heatmap[stu.pref2-1]+=1;
    }
    printf("===============ROOMS================\n");
    for (int i = 0; i < hostel->MAX_ROOMS; i++) 
    {
        printf("Room %d has %d preferences by students\n",i+1,heatmap[i]);
    }
    printf("===============END==================\n");

}