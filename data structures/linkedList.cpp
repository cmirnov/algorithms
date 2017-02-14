#include <bits/stdc++.h>

using namespace std;

struct Node {
  int val;
  Node* next;
  Node(int x) : val(x), next(NULL) {}
};

struct List {
  Node* head;
  Node* tail;
  List() : head(NULL), tail(NULL) { }
  void add(int x) {
    Node* temp = new Node(x);
    if (tail == NULL) {
      head = temp;
      tail = temp;
    } else {
      tail->next = temp;
      tail = temp;
    }
  } 
  void remove(int x) {
    if (head == NULL) {
      return;
    }
    Node* prev = head;
    if (prev->val == x) {
      if (head == tail) {
        tail = NULL;
      }
      head = head->next;
      delete prev;
    }
    Node* temp = prev->next;
    while (temp != NULL) {
      if (temp->val == x) {
        if (tail == temp) {
          tail = prev;
        }
        prev->next = temp->next;
        delete temp;
        return;
      }
      prev = temp;
      temp = temp->next;
    }
  }
  bool find(int x) {
    if (head == NULL) {
      return false;
    }
    Node* temp = head;
    while (temp != NULL) {
      if (temp-> val == x) {
        return true;
      }
      temp = temp->next;
    }
    return false;
  }
};

int main() {
}

