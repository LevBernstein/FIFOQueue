#include <stdio.h>
#include <stdlib.h>

// Very basic linked-list based FIFO queue.
// Written to help with an Operating Systems lab.
// Lev Bernstein
// 12/01/21

typedef struct qNode {
	int data;
	struct qNode *next;
} Node;

void enqueue(Node **head, int data) {
	Node *newNode = malloc(sizeof(Node));
	Node *walkingNode = *head;
	newNode->data = data;
	newNode->next = NULL;
	while (walkingNode->next != NULL) {
		walkingNode = walkingNode->next;
	}
	walkingNode->next = newNode;
	return;
}

int dequeue(Node **head) {
	if ((*head)->next == NULL) return -1;
	Node *poppedNode = (*head)->next;
	(*head)->next = poppedNode->next;
	int poppedData = poppedNode->data;
	free(poppedNode);
	return poppedData;
}

void printQueue(Node *head) {
	Node *walkingNode = head->next;
	printf("Queue contents: ");
	while (walkingNode != NULL) {
		printf("%d", walkingNode->data);
		walkingNode = walkingNode->next;
		if (walkingNode != NULL) {
			printf(", ");
		}
	}
	printf("\n");
}

int main() {
	Node *head = malloc(sizeof(Node));

	enqueue(&head, 547548);
	enqueue(&head, 347437);
	enqueue(&head, 123217);
	enqueue(&head, 26);
	enqueue(&head, -1);
	enqueue(&head, 1818181881);

	printQueue(head);

	while (head->next != NULL) {
		printf("Dequeued %d\n", dequeue(&head));
		printQueue(head);
	}

	return 0;
}
