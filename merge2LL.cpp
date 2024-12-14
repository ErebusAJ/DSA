# include<iostream>

using namespace std;

struct ListNode {
     int val;
     ListNode* next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode* next) : val(x), next(next) {}
 };

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head1 = list1;
        ListNode *head2 = list2;
        ListNode *headr;
        ListNode *headcheck;
        if(head1->val <= head2->val){
            headr = head1;
            headcheck = head2;
        }else{
            headr = head2;
            headcheck = head1;
        }

        while(head1 != NULL && head2 != NULL){
            ListNode *temp1 = headr->next;
            ListNode *temp2 = headcheck;
            if(temp1->val < temp2->val && temp2->val < temp1->next->val){
                temp1->next = temp2;
            }else{
                temp1 = temp1->next;
            }

        }

        return headr;
    }

int main(){
    ListNode *list1 = new ListNode(12);
    
}