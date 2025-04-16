#include<stdio.h>    // Standard I/O functions
#include<time.h>     // Time and date functions
#include<unistd.h>   // sleep() for POSIX systems
#include<stdlib.h>   // system() for clearing the screen

// Function prototypes
void fill_time(char*, int);  // Formats current time into the buffer
void fill_date(char*);       // Formats current date into the buffer
int input_format();          // Prompts user for time format selection
void clear_screen();         // Clears the terminal screen

int main()
{
    char time[50], date[100];	

    int format = input_format();  // Get user's preferred time format

    while(1)
    {
        fill_time(time, format);  // Update time string
        fill_date(date);          // Update date string
        clear_screen();           // Clear console for refreshed output

        printf("\nCurrent Time: %s\n", time);
        printf("Date: %s\n\n", date);

        sleep(1);  // Delay for 1 second
    }

    return 0;
}

// Clears the terminal screen depending on the OS
void clear_screen()
{
    #ifdef _WIN32
        system("cls");    // Windows
    #else
        system("clear");  // Unix/Linux/macOS
    #endif
}

// Populates the buffer with the current date in a readable format
void fill_date(char *buffer)
{
    time_t rawtime;
    struct tm *current_time;

    time(&rawtime);                        // Get current time
    current_time = localtime(&rawtime);   // Convert to local time struct

    strftime(buffer, 100, "%A %B %d %Y", current_time);  // Format: Weekday Month Day Year
}

// Populates the buffer with the current time based on selected format
void fill_time(char *buffer, int format)
{
    time_t rawtime;
    struct tm *current_time;

    time(&rawtime);
    current_time = localtime(&rawtime);

    if (format == 1)
        strftime(buffer, 50, "%H:%M:%S", current_time);       // 24-hour format
    else
        strftime(buffer, 50, "%I
