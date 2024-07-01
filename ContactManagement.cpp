#include<iostream>
#include<string>
#include<cstdlib> // for system()
using namespace std;


// To store the contact 's info
struct Contact
{
     string name;
     string email;
     string phone;

};
void clearScreen(){
    system("clear");
}
// function to display menu options

void displayMenu()
{
  cout<<"\n..........Contact Mangement System........\n";
  cout<<"1. Add a new contact \n";
  cout<<"2. Display all contacts\n";
  cout<<"3. Search for a contact\n";
  cout<<"4. Update a contact\n";
  cout<<"5. Delete a contact\n";
  cout<<"6. Exit\n";
}

void addContact(Contact contacts[],int &num_contacts)
{   if(num_contacts<100)
    {  Contact newContact;
       
       cout<<"Enter name: ";
       getline(cin,newContact.name);
       cout<<"Enter phone number: ";
       getline(cin,newContact.phone);
       cout<<"Enter Email address: ";
       getline(cin,newContact.email);
       contacts[num_contacts++]=newContact;
       cout<<"Contact has been added successfully.\n";
    }
    else cout<<"Maximum limit reached.\n";
}

void displayContacts(Contact contacts[],int num_contacts)
{
    if(num_contacts==0)
    {
        cout<<"No contacts to display.\n";
    }
    else
    {
        cout<<"-----------All Contacts------------\n";
        for(int i=0;i<num_contacts;i++)
        {
            cout<<"Name: "<<contacts[i].name<<"\n";
            cout<<"phone: "<<contacts[i].phone<<"\n";
            cout<<"Email: "<<contacts[i].email<<"\n";
            cout<<"***********************************\n";
        }
    }


}

void searchContact(Contact contacts[],int num_contacts)
{
   if(num_contacts==0)cout<<"No contacts to search.\n";
   
   else
   {
        string searchName;
        cout<<"Enter search Name: ";
        getline(cin,searchName); 
        

        bool found=false;

        for(int i=0;i<num_contacts;i++)
        {

        if(contacts[i].name==searchName)
        { 
            cout<<"Enter new phone number.\n";
            getline(cin,contacts[i].phone);
        }

        {
            cout<<">>>>>>>>>>>>>>>>>>>>>>>>> Contact has been found >>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
            cout<<"Name: "<<contacts[i].name<<"\n";
            cout<<"Phone:"<<contacts[i].phone<<"\n";
            cout<<"Email: "<<contacts[i].email<<"\n";
            found=true;
            break;
        }

        }
    if(!found)cout<<"Couldn't find the contact.\n";
   }
}

//function to update a contact by name

void updateContact(Contact contacts[],int num_contacts)
{
   if(num_contacts==0)cout<<"No contacts to update.\n";
   else
   {    
        string searchName;
        cout<<"Enter name of contact to update.\n";
        getline(cin,searchName);

        bool found=false;

        for(int i=0;i<num_contacts;i++)
        {

        if(contacts[i].name==searchName)
        {
            cout<<"Enter new phone number.\n";
            getline(cin,contacts[i].phone);
            cin.ignore();
            cout<<"Enter new email.\n";
            getline(cin,contacts[i].email);
            found=true;
            cout<<"Contact updated successfully.\n";
            break;
        }
      
        }

        if(!found)cout<<"Sorry,couldnt't find contact.\n";
   }
}

void deleteContact(Contact *contacts,int&num_contacts)
{   if (num_contacts == 0)cout << "No contacts to delete.\n"; 
    
    else 
    {

        string searchName;
        cout << "Enter name of contact to delete: ";
        getline(cin, searchName);

        bool found=false;
        for( int i=0;i<num_contacts;i++)
        {     
            
            if(searchName==contacts[i].name)
            {
                for(int j=i;j<num_contacts-1;j++)
                    contacts[j]=contacts[j+1];   // shifted contacts to the left and filled the gap
                
                num_contacts--;
                cout<<"Contact has been deleted succesfully.\n";
                found=true;
                break;

            }

        }

        if (!found)
            cout << "Contact not found.\n";
        
    }

}

int main()
{   const int MAX_CONTACTS=100;
    Contact contacts[MAX_CONTACTS];
    int num_contacts=0;
    int choice;
        do
        {
        displayMenu();
        cout<<"ENTER YOUR CHOICE: ";
        cin>>choice;
        cin.ignore();
        clearScreen();

        
            switch(choice)
            {
                case 1:
                    addContact(contacts,num_contacts);
                    break;
            
                case 2:
                    displayContacts(contacts,num_contacts);
                    break;
            
                case 3:
                    searchContact(contacts,num_contacts);   
                    break;

                case 4:
                    updateContact(contacts,num_contacts);
                    break;
           
                case 5:
                    deleteContact(contacts,num_contacts);
                    break;
            
                case 6:
                  
                    break;

                default:
                    cout<<"Invalid choice. Please try again.\n";
                    break;
            
            }
        }while(choice!=6);
    
        clearScreen();
        return 0;
}