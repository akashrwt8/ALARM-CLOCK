#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Function to play the alarm sound
void playAlarm() {
    printf("\a"); // Outputting a bell character to produce sound
}

int main() {
    int alarm_hour, alarm_minute;
    int current_hour, current_minute;
    char choice;

    // Getting alarm time from user
    printf("Enter the hour and minute for the alarm (24-hour format, e.g., 13 30 for 1:30 PM): ");
    scanf("%d %d", &alarm_hour, &alarm_minute);

    // Main loop
    while (1) {
        // Getting current time
        printf("Current time: ");
        scanf("%d %d", &current_hour, &current_minute);

        // Checking if it's time for the alarm
        if (current_hour == alarm_hour && current_minute == alarm_minute) {
            printf("Alarm is going off!\n");
            playAlarm(); // Playing the alarm sound
            printf("Stop playing alarm? (y/n): ");
            scanf(" %c", &choice);
            if (choice == 'y' || choice == 'Y') {
                printf("Alarm stopped.\n");
                break; // Exiting the loop
            }
        }

        // Sleeping for 1 minute
        sleep(60);
    }

    return 0;
}
