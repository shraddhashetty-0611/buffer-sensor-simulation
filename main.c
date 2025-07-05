#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BUFFER_SIZE 1024
#define PRINT_THRESHOLD 50

unsigned char buffer[MAX_BUFFER_SIZE];
int buffer_size = 0;

void generate_sensor_data(int second) {
    int count = rand() % 6; 
    printf("[Second %d] Added %d bytes: ", second, count);

    for (int i = 0; i < count && buffer_size < MAX_BUFFER_SIZE; i++) {
        unsigned char byte = rand() % 256;
        buffer[buffer_size++] = byte;
        printf("%02X ", byte);
    }

    if (count == 0)
        printf("(no data)");

    printf("\n");
}


void print_and_clear_latest_50() {
    if (buffer_size < PRINT_THRESHOLD) {
        printf("Buffer has only %d bytes. Skipping print.\n", buffer_size);
        return;
    }

    printf(">>> 10s reached: Printing latest 50 bytes:\n");
    for (int i = buffer_size - PRINT_THRESHOLD; i < buffer_size; i++) {
        printf("%02X ", buffer[i]);
    }
    printf("\n>>> Deleted 50 bytes from buffer.\n");

    buffer_size -= PRINT_THRESHOLD; 
}

int main() {
    srand(time(NULL)); 

    for (int second = 1; second <= 100; second++) {
        generate_sensor_data(second);

        if (second % 10 == 0) {
            print_and_clear_latest_50();
        }

        
    }

    return 0;
}
