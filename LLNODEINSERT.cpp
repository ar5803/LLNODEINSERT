#include<iostream>
using namespace std;
struct Node{
    int data;
    struct Node *next;
};
void lltraversal(struct Node* ptr){
    while(ptr!=NULL){
        cout<<ptr -> data<<endl;
        ptr = ptr -> next;
    }
}
struct Node * insertatfirst(struct Node *head, int data){
    struct Node * ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr -> next = head;
    ptr -> data = data;
    return ptr;
}

struct Node * insertatindex(struct Node* head,int data ,int index){
    struct Node * ptr = (struct Node* )malloc(sizeof(struct Node));
    struct Node * p = head;
    int i=0;
    while(i!=index-1){
        p = p -> next;
        i++;
    }
    ptr -> data = data;
    ptr -> next = NULL;
    p -> next = ptr; 
    return head;
}
struct Node * insertatend(struct Node* head,int data){
    struct Node * ptr = (struct Node* )malloc(sizeof(struct Node));
    struct Node * p = head;
    while(p -> next !=NULL){
        p = p -> next;
    }
    ptr -> data = data;
    p -> next = ptr; 
    ptr -> next = NULL;
    return head;
}

struct Node * insertafternode(struct Node* head, struct Node *prevnode, int data){
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr -> data = data;
    ptr->next = prevnode -> next;
    prevnode -> next = ptr;
    return head;
}
int main(){
    struct Node* head  = (struct Node *)malloc(sizeof(struct Node));
    struct Node* second = (struct Node *)malloc(sizeof(struct Node));
    struct Node* third = (struct Node *)malloc(sizeof(struct Node));

    head -> data = 7;
    head -> next = second;

    second -> data = 11;
    second -> next = third;

    third -> data = 78;
    third -> next = NULL;
    cout<<"LL before insertion\n";
    lltraversal(head);
    //INSERTION IN A LINKED LIST
    // struct Node* ptr1 = (struct Node *)malloc(sizeof(struct Node));
    // ptr1 -> data = 1;
    // ptr1 -> next = head;
    // head = ptr1;
    // cout<<"LL after insertion\n";
    // lltraversal(head);  
    // insertatend(head , 655);
    // head = insertatfirst(head , 560);
    // lltraversal(head);
    head = insertafternode(head,third,432);
    lltraversal(head);
}
