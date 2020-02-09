/****************************************************
*   Template for coding contests                    *
*   Author    :    Sanjeev Sharma                   *
*   Email     :    thedevelopersanjeev@gmail.com    *
*****************************************************/
#include <bits/stdc++.h>
using namespace std;

#define deb(x) cout << #x << " is " << x << "\n";

class Node{
	public :
	int data;
	Node* next;
};

void addNode(Node** head, int data){
	Node* node = new Node();
	node->data = data;
	node->next = (*head);
	(*head) = node;
}

void printList(Node* node){
	while(node != NULL){
		cout <<node->data <<" ";
		node = node->next;
	}
}

void moveTail(Node** node){
	if(*node == NULL || (*node)->next == NULL)
		return;
	Node* slow = NULL;
	Node* fast = *node;
	while(fast->next != NULL){
		slow = fast;
		fast = fast->next;
	}
	slow->next = NULL;
	fast->next = *node;
	*node = fast;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int n, k, ele;
	cin >>n;
	Node* head = NULL;
	vector<int> arr;
	for(int i = 0; i < n; i++){
		cin >>ele;
		arr.push_back(ele);
	}
	for(int i = n - 1; i >= 0; i--){
		addNode(&head, arr[i]);
	}
	cin >>k;
	k %= n;
	while(k--){
		moveTail(&head);
	}
	printList(head);
	return 0;
}
