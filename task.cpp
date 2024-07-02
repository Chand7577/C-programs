#include<iostream>
#include<string>
using namespace std;

const int MaxTask=100;

struct Task
{
    string description;
    bool completed;
}; 


struct ToDoList
{
    Task tasks[MaxTask];
    int count;

    //Constructor
    ToDoList():count(0){}
    
    
    // task to be added
    void addTask(string &desc)
    {
        if(count<MaxTask)
        {

    
          tasks[count].description=desc;
          tasks[count].completed=false;
          count++;
          cout<<"Task has been added successfully.\n";
        
        }

        else cout<<"Task is full.\n";

    }
    // View all tasks

    void viewTasks()
    {
      if(count==0) cout<<"No tasks to display.\n";

      else
      {
            for(int i=0;i<count;i++)
            {
                cout<<i+1<<".";

                if(tasks[i].completed)
                {
                cout<<"[Completed] ";
                }
            
            cout<<tasks[i].description<<endl;
            
            }
      }
    }

    void completeTask(int index)
   //Marking tasks as completedindex
   {
        if(index>=0 && index<count) {tasks[index].completed=true;
            cout<<"Task marked as completed.\n";

        }
        else cout<<"Invalid Task  Number\n"<<endl;

   }
   void deleteTask(int index)
   {
        if(index>=0 && index<count)
        {
          for(int i=index;i<count-1;i++)
                tasks[i]=tasks[i+1];
        
            count--;
            cout<<"Task has been deleted Successfully.\n";
        }
        else
        {
          cout<<"Invalid Task Number."<<endl;
        }

   }



};

int getUserInput(int min,int max)
{
    int choice;
    cin>>choice;
    while(choice<min || choice>max)
    {
        cout<<"Invalid choice.Please enter a number b/w "<<min<<" and "<<max;
        cin>>choice;
    }
    return choice;

}

void displayMenu()
{
    cout<<"\t\t\t---------------------------To Do List ------------------------------\n\n";
    cout<<"\t\t\t\t\t1. ***  Add New Task \n";
    cout<<"\t\t\t\t\t2.***** View Tasks \n";
    cout<<"\t\t\t\t\t3.***** Delete  Task \n";
    cout<<"\t\t\t\t\t4.***** Complete Task \n\n";
    cout<<"\t\t\t\t\t5.***** Terminate The Program \n\n";
    cout<<"\t\t\t\t\t  +++++ Select Your Choice +++++++";

}


int main()
{
  ToDoList todolist;
  int choice=0;
  do
  {  
    displayMenu();
    choice=getUserInput(1,5);
    switch(choice)
    {
       
       case 1:{

            string desc;
            cout<<"Enter task description\n";
            cin.ignore();
            getline(cin,desc);
            todolist.addTask(desc);
            break;
       }
       case 2:{
            todolist.viewTasks();
            break;
       }

       case 3:{
            int indexToDelete;
            cout<<"Enter task number to delete\n";
            cin>>indexToDelete;
            todolist.deleteTask(indexToDelete-1);
            break;
       }
       case 4:{
            int indexToComplete;
            cout<<"Enter task number to mark as completed\n";
            cin>>indexToComplete;
            todolist.completeTask(indexToComplete-1);
            break;
       }
       case 5:{
            break;
       }
       default:
            cout<<"Invalid choice.Please try again";


    }
  }while(choice!=5);
 
    
  
  return 0;
}