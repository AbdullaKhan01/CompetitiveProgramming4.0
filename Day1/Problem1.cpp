#include<bits/stdc++.h>
using namespace std; 
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void Reverse(Node* &head){
	if(head == NULL||head->next == NULL){
		return ;
	}
	Reverse(head->next);
	head -> next -> next = head;
	head -> next = NULL;
}
Node *getListAfterReverseOperation(Node *head, int n, int b[]){

	if(n == 1 && b[0] <= 1)return head;
	if(!head || !head->next) return head;
	Node* head1=head;
	Node* tail1=head;
	Node* head2=NULL;
	Node* tail2=NULL;
	Node* ans = head;
	bool isTrue = true;
	for(int i=0;i<n;i++){
		int e = b[i];
		if(e <= 0) continue;
		e-=1;
		while(e-- && tail1->next !=NULL){
			tail1 = tail1->next;
		}
		
		if(isTrue){
			ans = tail1;
			isTrue = false;
		}
		head2 = tail1->next;
		tail1->next = NULL;
		Reverse(head1);

		// head1 = head2;
		if(tail2!=NULL){
			tail2->next = tail1;

		}
		tail2 = head1;
		head1 = head2;
		tail1 = head1;
		if( !tail1||tail1->next == NULL ){
			break;
		}
		
	}
	tail2->next = head1;
	return ans;
}
int main(){ 
     
    return 0;
}