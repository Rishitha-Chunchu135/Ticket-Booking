#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct TrainTicket {
int ticketNumber;
char passengerName[50];
char source[50];
char destination[50];
struct TrainTicket* next;
};
struct TrainTicket* createTicket(int ticketNumber, const char* passengerName, const char* source, const char* destination) {
struct TrainTicket* newTicket = (struct TrainTicket*)malloc(sizeof(struct
TrainTicket));
if (newTicket == NULL) {
printf("Memory allocation error.\n");
exit(1);
}
newTicket->ticketNumber = ticketNumber;
strcpy(newTicket->passengerName, passengerName); strcpy(newTicket->source, source);
strcpy(newTicket->destination, destination);
newTicket->next = NULL;
return newTicket;
}
void bookTicket(struct TrainTicket** head, int ticketNumber, const char*
passengerName, const char* source, const char* destination) {
struct TrainTicket* newTicket = createTicket(ticketNumber, passengerName, source, destination);
if (*head == NULL) {
*head = newTicket;
}
else {
struct TrainTicket* current = *head;
while (current->next != NULL) {
current = current->next;
}
current->next = newTicket;
}
printf("Ticket booked successfully.\n");
}void cancelTicket(struct TrainTicket** head, int ticketNumber) {
struct TrainTicket* current = *head;
struct TrainTicket* prev = NULL;
while (current != NULL && current->ticketNumber != ticketNumber) {
prev = current;
current = current->next;
}
if (current == NULL) {
printf("Ticket with number %d not found.\n", ticketNumber);
return;
}
if (prev == NULL) {
// Ticket to be canceled is the first one
*head = current->next;
}
else {
prev->next = current->next;
}
free(current);
printf("Ticket with number %d canceled successfully.\n", ticketNumber);
}void displayTickets(struct TrainTicket* head) {
if (head == NULL) {
printf("No tickets booked yet.\n");
}
else {
struct TrainTicket* current = head;
printf("Ticket Information:\n");
while (current != NULL) {
printf("Ticket Number: %d\n", current->ticketNumber);
printf("Passenger Name: %s\n", current->passengerName);
printf("Source: %s\n", current->source);
printf("Destination: %s\n", current->destination);
printf("------------------------\n");
current = current->next;
}
}
}
void freeTickets(struct TrainTicket* head) {
struct TrainTicket* current = head;
struct TrainTicket* next; while (current != NULL) {
next = current->next;
free(current);
current = next;
}
}
int main() {
struct TrainTicket* ticketList = NULL;
bookTicket(&ticketList, 101, "John", "City A", "City B");
bookTicket(&ticketList, 102, " Doe", "City C", "City D");
displayTickets(ticketList);
// Canceling a ticket
cancelTicket(&ticketList, 101);
//Display tickets
displayTickets(ticketList);
// Freeing allocated memory
freeTickets(ticketList);
return 0;
}


