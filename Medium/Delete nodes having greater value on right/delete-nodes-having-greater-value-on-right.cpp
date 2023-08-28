//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    Node *compute(Node *head)
    {
        vector<int> nodes;
        for(auto it= head; it; it=it->next){
            nodes.push_back(it->data);
        }
        stack<int> st;
        int n= nodes.size();
        vector<int> nge;
        for(int i=n-1; i>=0; i--){
            while(st.size() && st.top()<= nodes[i]) st.pop();
            if(st.empty()) nge.push_back(nodes[i]);
            st.push(nodes[i]);
        }
        Node* dummy= new Node(-1);
        Node* tail=dummy;
        int nofnodes= nge.size();
        for(int i=nofnodes-1; i>=0 ; i--) {
            Node* newnode= new Node(nge[i]);
            tail->next=newnode;
            tail=newnode;
        }
        return dummy->next;
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends