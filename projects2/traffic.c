#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // For sleep function

// Define a node in the circular linked list
typedef struct Node {
    char *color;
    int duration; // Duration in seconds for the light
    struct Node *next;
} Node;

// Function to create a new node
Node* createNode(char *color, int duration) {
    Node newNode = (Node)malloc(sizeof(Node));
    newNode->color = color;
    newNode->duration = duration;
    newNode->next = NULL;
    return newNode;
}

// Function to create the circular linked list
Node* createTrafficLight() {
    Node *red = createNode("Red", 5);
    Node *yellow = createNode("Yellow", 2);
    Node *green = createNode("Green", 4);

    // Link the nodes to form a circular linked list
    red->next = yellow;
    yellow->next = green;
    green->next = red;

    return red; // Return the starting node
}

// Function to simulate the traffic light
void simulateTrafficLight(Node *head, int cycles) {
    Node *current = head;

    for (int i = 0; i < cycles; i++) {
        printf("Light: %s (Duration: %d seconds)\n", current->color, current->duration);
        sleep(current->duration); // Pause for the duration of the current light
        current = current->next; // Move to the next light
    }
}

// Main function
int main() {
    Node *trafficLight = createTrafficLight();
    int cycles = 10; // Number of cycles to simulate

    printf("Starting Traffic Light Simulation...\n");
    simulateTrafficLight(trafficLight, cycles);

    // Free allocated memory
    Node *temp = trafficLight;
    Node *nextNode;
    do {
        nextNode = temp->next;
        free(temp);
        temp = nextNode;
    } while (temp != trafficLight);

    printf("Simulation Ended.\n");
    return 0;
}