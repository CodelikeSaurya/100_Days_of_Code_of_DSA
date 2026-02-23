/*#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

struct ListNode* insertEnd(struct ListNode* head, int val) {
    struct ListNode* newNode = createNode(val);

    if (head == NULL)
        return newNode;

    struct ListNode* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

void createCycle(struct ListNode* head, int pos) {
    if (pos < 0) return;

    struct ListNode* temp = head;
    struct ListNode* cycleNode = NULL;
    int index = 0;

    while (temp->next != NULL) {
        if (index == pos)
            cycleNode = temp;
        temp = temp->next;
        index++;
    }

    if (cycleNode != NULL)
        temp->next = cycleNode;
}

bool hasCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL)
        return false;

    struct ListNode *slow = head;
    struct ListNode *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }

    return false;
}

int main() {
    int n, value, pos;
    struct ListNode* head = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    printf("Enter position to create cycle (-1 for no cycle): ");
    scanf("%d", &pos);

    createCycle(head, pos);

    if (hasCycle(head))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

struct Node* mergeLists(struct Node* l1, struct Node* l2) {
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while (l1 != NULL && l2 != NULL) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    if (l1 != NULL)
        tail->next = l1;
    else
        tail->next = l2;

    return dummy.next;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, m, value;
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        list1 = insertEnd(list1, value);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &value);
        list2 = insertEnd(list2, value);
    }

    struct Node* merged = mergeLists(list1, list2);

    printList(merged);

    return 0;
}