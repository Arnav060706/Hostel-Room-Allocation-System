//gcc main.c source.c -o  hostel_app
#include "hostel.h"

int main() 
{
    Hostel hostel;
    int choice, id, pref1, pref2, total_rooms;

    printf("Enter total number of rooms: ");
    scanf("%d", &total_rooms);
    initHostel(&hostel, total_rooms);

    while (1) 
    {
        printf("\n1. Add Student\n2. Assign Rooms\n3. Free Room\n4. View Map\n5. Swap Rooms\n6. Heatmap\n7. Exit\n");
        printf("Enter choice: ");
        
        if (scanf("%d", &choice) != 1) 
        {
            printf("Invalid input! Please enter a number.\n");
            while (getchar() != '\n'); 
            continue; 
        }

        switch (choice) 
        {
            case 1:
            {
                int flag=0;
                do
                {
                    printf("Enter student ID and preferred room-1 and preferred room-2: ");
                    scanf("%d %d %d", &id, &pref1, &pref2);
                    for (int i=0; i<(hostel.curr_top);i++)
                    {
                        if (id==0)
                        {
                            printf("Student id cannot be 0!\n");
                            flag=1;
                            break;
                        }
                        if (id==(hostel.student_queue[i]).id)
                        {
                            printf("Student of id %d already in queue\n",id);
                            flag=1;
                            break;
                        }
                    }

                    for (int i=0; i<(hostel.MAX_ROOMS);i++)
                    {
                        if (id==(hostel.rooms[i]))
                        {
                            printf("Student of id %d already assigned a room\n",id);
                            flag=1;
                            break;
                        }
                    }

                    if (pref1 == pref2) 
                    {
                        printf("Both preferences cannot be the same!\n");
                        flag=1;
                    }

                    if ((pref1 < 1 || pref1 > total_rooms) && (pref2 < 1 || pref2 > total_rooms)) 
                    {
                        printf("Enter valid room numbers for both preferences (1 - %d)\n", total_rooms);
                        flag=1;
                    }

                    else if (pref1 < 1 || pref1 > total_rooms) 
                    {
                        printf("Enter valid room number for preferred room-1 (1 - %d)\n", total_rooms);
                        flag=1;
                    }

                    else if (pref2 < 1 || pref2 > total_rooms) 
                    {
                        printf("Enter valid room number for preferred room-2 (1 - %d)\n", total_rooms);
                        flag=1;
                    }

                    else 
                    break; 

                } while (1);

                if (!flag)
                { 
                    student stud=addStudent(&hostel, id, pref1, pref2);
                    printf("Student ID:%d with Preference-1 Room:%d and Preference-2 Room:%d has been added to the waiting queue\n", stud.id, stud.pref1,stud.pref2);
                }
                break;
            }
            case 2:
            {
                int remaining_students=assignRoom(&hostel);
                if (remaining_students==0) printf("No students remain in Queue\n");
                else if (remaining_students == -1) NULL;
                else printf("The number of students remaing after all the rooms are filled are:%d\n",remaining_students);
                break;
            }
            case 3:
            {
                printf("Enter student ID to free room: ");
                scanf("%d", &id);
                int Room_Number=freeRoom(&hostel, id);
                if (Room_Number) printf("Student ID:%d was found in Room:%d and freed\n", id, Room_Number);
                else printf("Student ID:%d was not found in any Room\n", id);
                break;
            }
            case 4:
            {
                int Empty_Rooms=viewMap(&hostel);
                printf("There are %d number of rooms in hostel and %d are Empty\n",hostel.MAX_ROOMS,Empty_Rooms);
                break;
            }
            case 5:
            {    
                int id1,id2,n;
                printf("Enter Student id1 and Student id2:");
                scanf("%d %d",&id1,&id2);
                n=swapRooms(&hostel,id1,id2);
                if (n)
                {
                    printf("Rooms have been swapped successfully :)\n");
                }
                
                else
                {
                    printf("Failure in swapping rooms :(\n");
                }
                break;
            }
            case 6:
            {
                Heatmap(&hostel);
                break;
            }
            case 7:
            {
                printf("Exiting...\n");
                cleanupHostel(&hostel);
                return 0;
            }
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
}