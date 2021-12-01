#include <stdio.h>
#include <stdlib.h>

// Very basic linked-list based FIFO queue.
// Written to help with an Operating Systems lab.
// Lev Bernstein
// 12/01/21

struct qNode {
	int data;
	struct qNode *next;
};

void enqueue(struct qNode **head, int data) {
	struct qNode *newNode = malloc(sizeof(struct qNode));
	struct qNode *walkingNode = *head;
	newNode->data = data;
	newNode->next = NULL;
	while (walkingNode->next != NULL) {
		walkingNode = walkingNode->next;
	}
	walkingNode->next = newNode;
	return;
}

int dequeue(struct qNode **head) {
	if ((*head)->next == NULL) return -1;
	struct qNode *poppedNode = (*head)->next;
	(*head)->next = poppedNode->next;
	int poppedData = poppedNode->data;
	free(poppedNode);
	return poppedData;
}

void printQueue(struct qNode *head) {
	struct qNode *current = head->next;
	printf("Queue contents: ");
	while (current != NULL) {
		printf("%d", current->data);
		current = current->next;
		if (current != NULL) {
			printf(", ");
		}
	}
	printf("\n");
}

int main() {
	struct qNode *head = malloc(sizeof(struct qNode));
	head->next = NULL;
	int data;

	enqueue(&head, 547548);
	enqueue(&head, 347437);
	enqueue(&head, 123217);
	enqueue(&head, 26);
	enqueue(&head, -1);
	enqueue(&head, 1818181881);

	printQueue(head);

	while (head->next != NULL) {
		data = dequeue(&head);
		printf("Dequeued %d\n", data);
		printQueue(head);
	}


	return 0;
}