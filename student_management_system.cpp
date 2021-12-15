#include<bits/stdc++.h>

using namespace std;

struct node {
    int id;
    int class_student;
    string name;
    struct node *link;
};
struct node *head = NULL;

void insert_entry() 
{

    // Input details
    int id, class_data;
    string name;
    cout<<endl;
    cout<<"Enter the following details: "<<endl;
    cout<<"Roll ID: "<<endl; 
    cin>>id;
    cout<<"Name: " <<endl;
    cin>>ws;
    getline(cin, name);
    cout<<"Class: " <<endl;
    cin>>class_data;

    struct node **linkp = &head;
    struct node* current = *linkp;
	struct node* temp = (struct node*)malloc(sizeof(struct node));

	if(temp == NULL){
		printf("Error in malloc!\n");
		return;
	}
	while(current!=NULL && current->id < id){
		linkp = &(current->link);
		current = *linkp;
	}
	temp->id = id;
    temp->name = name;
    temp->class_student = class_data;
	temp->link = current;
	*linkp = temp;

}

void delete_entry()
{
    int id;
    if(head == NULL)
    {
        cout<<"The list is empty"<<endl;
        return;
    }

    cout<<"Enter the ID of the student for deletion"<<endl;
    cin>>id;
    struct node **linkp = &head;
    struct node* current = *linkp;

    while(current!=NULL && current->id != id)
    {
		linkp = &(current->link);
		current = *linkp;
    }
    if(current != NULL)
    {
        *linkp = current->link;
        free(current);
        current = *linkp;
    }

}

void search_entry()
{
    int choice, id;
    string name;
    struct node **linkp = &head;
    struct node* current = *linkp;

    cout<<"1. ID"<<endl;
    cout<<"2. name"<<endl;
    cout<<"enter your choice"<<endl;
    cin>>choice;
   
    if(choice==1)
    {
        cout<<"Enter the ID of the student for the search"<<endl;
        cin>>id;
        while(current!=NULL && current->id != id )
        {
		    linkp = &(current->link);
		    current = *linkp;
        }

    }
    else if(choice == 2)
    {
        cout<<"Enter the name of the student for the search"<<endl;
        cin>>ws;
        getline(cin,name);
        while(current!=NULL && current->name != name )
        {
		    linkp = &(current->link);
		    current = *linkp;
        }
    }
    else{
        cout<<"invalid choice";
        return;
    }

    if(current != NULL)
    {
        cout<<"ID = "<<current->id<<endl;
         cout<<"Name = "<<current->name<<endl;
        cout<<"Class = "<<current->class_student<<endl;
    }
    else{
        cout<<"No entries found"<<endl;
    }

}

void print(struct node *head)   //printing the data
{
    if(head==NULL)
    {
        cout<<endl<<"No Entries Found!"<<endl<<endl;
        return;
    }

    cout<<endl<<"| ID\t| Name \t\t\t\t| Class\t|"<<endl;
    while(head!=NULL)
    {
        cout<<endl;
        cout<<"| " << head->id<<"\t";
        cout<<"| "<< head->name<<" \t\t\t\t";
        cout<<"| "<< head->class_student<<"\t|";
        head = head->link;
    }
    cout<<endl;

}

int main() 
{
    int opt;
    cout<<"Welcome to student record system :" << endl;

    do{
        cout<<endl;
        cout<<"1. View current records."<<endl;
        cout<<"2. Insert a record."<<endl;
        cout<<"3. Delete a record."<<endl;
        cout<<"4. Search a record."<<endl;
        cout<<"0. Exit"<<endl;
        cout<<endl<<"Input: ";
        cin>>opt;

        if(opt == 0)
            break;

        if(opt == 1){
                print(head);
                continue;
        }

        if(opt == 2)
            insert_entry();

        if(opt == 3)
            delete_entry();

        if(opt == 4)
            search_entry();

    }while(opt>=0 && opt<5);

    cout<<endl<<"Exiting! Bye."<<endl;


}
