#include <bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *next; //luu dia chi node tiep theo trong bo nho
};

struct node *makeNode(int x) {
    auto *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->next = nullptr;
    return newNode;
}

void out(struct node *head) {
    while(head != nullptr) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int size(struct node *head) {
    int count = 0;
    while(head!= nullptr) {
        ++count;
        head = head->next;
    }
    return count;
}

//them vao dau
void pushFront(struct node **head, int x) {
    struct node *newNode = makeNode(x);
    newNode->next = (*head); //dia chi node head
    (*head) = newNode;
}

void pushBack(struct node **head, int x) {
    struct node *tmp = *head;
    struct node *newNode = makeNode(x);
    if(*head == nullptr) {
        *head = newNode;
        return;
    }

    while(tmp->next != nullptr) {
        tmp = tmp->next;
    }
    tmp->next = newNode;
}

void insert(struct node **head, int k, int x) {
    int n = size(*head);
    if(k < 1 || k > n + 1) {
        return;
    }
    if(k == 1) {
        pushFront(head, x);
        return;
    }
    struct node *tmp = *head;
    for(int i = 1; i <= k - 1; i++) {
        tmp = tmp->next;
    }
    struct node *newNode = makeNode(x);
    newNode->next = tmp->next;
    tmp->next = newNode;
}

void popFront(struct node **head) {
    if(*head == nullptr) {
        return;
    }
    struct node *tmp = *head;
    *head = tmp->next;
    free (tmp);
}

void popBack(struct node **head) {
    if(*head == nullptr) {
        return;
    }
    struct node *tmp = *head;
    if(tmp->next == nullptr) {
        *head = nullptr;
        free (tmp);
        return;
    }
    while(tmp->next->next != nullptr) {
        tmp = tmp->next;
    }
    struct node *last = tmp->next;
    tmp->next = nullptr;
    free (last);
}

void erase(struct node **head, int k) {
    int n = size(*head);
    if (k < 1 || k > n + 1) {
        return;
    }
    if (k == 1) {
        popFront(head);
        return;
    } else {
        struct node *tmp = *head;
        for(int i = 1; i <= k - 2; i++) {
            tmp = tmp->next;
        }
        struct node *kth = tmp->next; //node thu k
        //cho k - 1 voi k + 1
        tmp->next = kth->next;
        free (kth);
    }
}

void sortList(struct node **head) {
    for(struct node *i = *head; i != nullptr; i = i->next) {
        struct node *minNode = i;
        for(struct node *j = i->next; j != nullptr; j = j->next) {
            if(j->data < minNode->data) {
                minNode = j;
            }
        }
        int tmp = minNode->data;
        minNode->data = i->data;
        i->data = tmp;
    }
}

int main() {
    struct node *head = nullptr;
    while(true) {
        printf("1. Them vao dau\n");
        printf("2. Them vao cuoi \n");
        printf("3. Them vao vi tri k\n");
        printf("4. Xoa dau\n");
        printf("5. Xoa cuoi\n");
        printf("6. Xoa o vi tri k\n");
        printf("7. In ra DSLK\n");
        printf("8. Size\n");
        printf("9. Sap xep");
        printf("Dung");
        int choose;
        scanf("%d", &choose);
        if(choose == 1) {
            int n;
            scanf("%d", &n);
            for(int i = 0; i < n; i++) {
                int x;
                scanf("%d", &x);
                pushFront(&head, x);
            }
        } else if(choose == 2) {
            int n;
            scanf("%d", &n);
            for(int i = 0; i < n; i++) {
                int x;
                scanf("%d", &x);
                pushBack(&head, x);
            }
        } else if(choose == 3) {
            int k, x;
            scanf("%d%d", &k, &x);
            insert(&head, k, x);
        } else if(choose == 4) {
            popFront(&head);
        } else if(choose == 5) {
            popBack(&head);
        } else if(choose == 6) {
            int k;
            scanf("%d", &k);
            erase(&head, k);
        } else if(choose == 7) {
            printf("%d", &head);
        } else if(choose == 8) {
            printf("%d", size(head));
        } else if (choose == 9) {
            sortList(&head);
        } else {
            break;
        }
    }
    return 0;
}

