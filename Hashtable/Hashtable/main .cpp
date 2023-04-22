#include <iostream>
#include <string>
#include <math.h>
using namespace std;
#define SIZE 100003

struct Node
{   
    string word;
    int numberOfOcurences;
    struct Node* next;
};

void append(Node** head,const string& word)
{
    Node* temp = *head;
    if (*head == nullptr) {
        Node* newNode = new Node;
        newNode->word = word;
        newNode->next = nullptr;
        newNode->numberOfOcurences=1;
        *head = newNode;
        return;
    }
    while (temp->next != nullptr && temp->word != word) { temp = temp->next;}
    if (temp->word == word) 
    {
        (temp->numberOfOcurences)++;
    }
    else {
        Node* newNode = new Node;
        newNode->word = word;
        newNode->next = nullptr;
        newNode->numberOfOcurences=1;
        temp->next = newNode;
    }
    return;
}
/*
void display(struct Node* head, short int* index)
{
    while (*(index) != 0)
    {
        head = head->next;
        (*index)--;
    }
    cout << head->word << endl;
    return;
}

void destroy_last(Node* head, int* size, Node** last) {
    if (*size == 1) {
        cout << head->word << endl;
        delete* last;
        delete head;
        --(*size);
        return;
    }
    for (int i = 2; i < *(size); i++) { head = head->next; }
    *last = head;
    delete head->next;
    --(*size);
    return;
}
*/
int Hash(const string& word) {
    long long unsigned int key = 0;
    int base=31;
    for (long long unsigned int i = 0; i < word.length(); i++)
    {
        key += (int)word[i]*(int)pow(base,i);
    }
    key = key % 100003;
    return (int)key;
}
int howMany(Node* head,const string& word) {
    if (head == nullptr) {
        return 0;
    }
    while (head->next != nullptr && head->word != word) {
        head = head->next;
    }
    if (head->numberOfOcurences != 0)   return head->numberOfOcurences;
    else return 0;
}

void deleteElement(Node** head, const string& word) {
    Node* temp = *head;
    if (*head == nullptr) return;
    while (temp->next != nullptr && temp->word != word) {
        temp = temp->next;
    }
    if (temp->word == word)temp->numberOfOcurences = 0;
}
int main()
{
    Node** tablica = new Node *[SIZE];
    for (int i = 0; i < SIZE; i++) tablica[i] = nullptr;
    string command;
    int quit = 0;
    while (quit != 1) {
        cin >> command;
        switch (command[0]) {
        case '?': {
            command.erase(0, 1);
            cout << howMany(tablica[Hash(command)], command) << endl;
            break;
        }
        case '-': {
            command.erase(0, 1);
            deleteElement(&tablica[Hash(command)], command);
            break;
        }
        case'q': {
            if (command[1] == '\0')quit = 1;
            else {
                append(&tablica[Hash(command)], command);
            }
            break;
        }
        default: {
            append(&tablica[Hash(command)], command);
            break;
        }
        }
    }
    return 0;
}

