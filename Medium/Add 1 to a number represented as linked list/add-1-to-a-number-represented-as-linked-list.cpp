//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data%10; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    Node* rev(Node* head){
        if(!head or !head->next) return head;
        Node* curr= head, * prev= NULL;
        while(curr){
            Node* next= curr->next;
            curr->next= prev;
            prev= curr;
            curr=next;
        }
        return prev;
    }
    public:
    Node* addOne(Node *head) 
    {
        Node* temp= rev(head);
        Node* h=NULL, *t= NULL;
        int carry=1;
        while(temp){
            int sum=carry;
            sum+= temp->data;
            carry= sum/10;
            Node* newnode= new Node(sum%10);
            if(h){
                t->next= newnode;
                t=newnode;
            }
            else{
                h= newnode;
                t= newnode;
            }
            temp=temp->next;
        }
        if(carry){
            Node* newnode= new Node(1);
            t->next= newnode;
        }
        h= rev(h);
        return h;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends