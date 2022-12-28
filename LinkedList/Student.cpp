#include <bits/stdc++.h>

#include <utility>
using namespace std;

struct Student {
    char name[256], id[20];
    double gpa;
};

struct node {
    Student data;
    struct node *next;
};

void input(Student s) {
    printf("Nhap ID: ");
    scanf("%s", s.id);

    printf("Nhap Name: ");
    scanf("%s", s.name);

    printf("Nhap GPA: ");
    scanf("%lf", &s.gpa);
}

struct node *makeNode(Student s) {
    auto *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = s;
    newNode->next = nullptr;
    return newNode;
}

void pushBack(struct node **head, Student s) {
    struct node *tmp = *head;
    struct node *newNode = makeNode(s);
    if(*head == nullptr) {
        *head = newNode;
        return;
    }

    while(tmp->next != nullptr) {
        tmp = tmp->next;
    }
    tmp->next = newNode;
}

void output(struct node *head) {
    while(head != nullptr) {
        printf("ID: %s\n", head->data.id);
        printf("Name: %s\n", head->data.name);
        printf("GPA: %lf\n", head->data.gpa);
        head = head->next;
    }
}

void sortList(struct node **head) {
    for(struct node *i = *head; i != nullptr; i = i->next) {
        struct node *minNode = i;
        for(struct node *j = i->next; j != nullptr; j = j->next) {
            if(j->data.gpa < minNode->data.gpa) {
                minNode = j;
            }
        }
        Student tmp = minNode->data;
        minNode->data = i->data;
        i->data = tmp;
    }
}

int main() {
    struct node *head = nullptr;
    Student s{};
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        input(s);
        pushBack(&head, s);
    }
    sortList(&head);
    output(head);
    return 0;
}