#include <bits/stdc++.h>

using namespace std;
//Given a linked list, a1->a2->a3->a4->....->a(n-1)->a(n);
//Change it inplace and return head of a1->an->a2->a(n-1)->.....
  
/*
Steps
1. Find middle
2. Reverse second half of list
3. Merge alternate of two half lists
*/

/*
Splitting at middle of linked list

void splitMiddle(node* actual, node** ls1, node** ls2) {
    node* slow = actual, *fast = actual -> next;
    while(fast!=NULL) {
        fast = fast->next;
        if(fast!=NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    node* temp = slow->next;
    slow->next=NULL;
    *ls1 = actual;
    *ls2 = temp; 

    //changes made in ls1 and ls2 reflect in main
}

//Reverse the second half of list

void reverse(node* cur, node** head) {
    if(cur==NULL) {
        *head = NULL;
        return;
    }
    if(cur->next == NULL) {
        *head = cur;
        return;
    }
    reverse(cur->next, head);
    cur->next->next = cur;
    cur->next = NULL;
}

node* mergeAlternate(node* ls1, node* ls2) {
    node* head = ls1;
    node* temp1 = ls1;
    node* temp2 = ls2;
    while(temp1 && temp2) {
        node* next1 = temp1->next;
        node* next2 = temp2->next;
        temp1->next = temp2;
        temp2->next = next1;
        temp1 = next1;
        temp2 = next2;    
    }
    return head;
}

//These were helper functions
//Actual call from main

node* fold(node* inpList) {
    node* temp1, *temp2, *temp3;
    splitMiddle(inpList, &temp1, &temp2);
    reverse(temp2, &temp3);
    return mergeAlternate(temp1, temp3);
}

*/

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);


}