#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

vector<string> tasks;
    // cout << "\033[1;31mThis is Red\033[0m" << endl;
    // cout << "\033[1;32mThis is Green\033[0m" << endl;
    // cout << "\033[1;33mThis is Yellow\033[0m" << endl;
    // cout << "\033[1;34mThis is Blue\033[0m" << endl;
    // cout << "\033[1;35mThis is Magenta\033[0m" << endl;
    // cout << "\033[1;36mThis is Cyan\033[0m" << endl;
    // cout << "\033[1;37mThis is White\033[0m" << endl;
void add_task(){
    cout<<endl;
    cout<<"Enter the number of tasks : ";
    int nAdd;
    cin>>nAdd;
    
}
void delete_task(){
    cout<<"delete";
    cout<<endl;
}
void print_task(){
    cout<<"Your tasks are as : "<<endl<<endl;
    for(int i=0; i<tasks.size();i++){
        cout<<"\033[1;32m";
        cout<<i+1<<". "<<tasks[i]<<endl;
        cout<<"\033[0m";
    }
    cout<<endl;
}
string response1;
int main(){

    cout<<"_______________________________________________________________________________"<<endl;
    cout<<"\033[1;32m"<<"----------------------------------TO-DO LIST-----------------------------------"<<"\033[0m"<<endl;
    cout<<"_______________________________________________________________________________"<<endl;
    int taskNo;
    cout<<endl<<endl;
    cout<<"\033[1;33mEnter the number of tasks you would like to add : \033[0m";
    cin>>taskNo;
    cout<<endl;
    cin.ignore();
    cout<<"ADD TASKS BELOW : "<<endl<<endl;
   vector<string> tasks;
    for(int i=0; i<taskNo; i++){
        cout<<"\033[1;34m";
        string task;
        cout<<"Task "<<i+1<<" : ";
        cout<<"\033[0m";
        getline(cin,task);
        tasks.push_back(task);
    }
 ///////////FILE HANDLING///////////////////////////
    ofstream fout;
    fout.open("tasks.text");
    fout<<"Tasks are : \n\n";
    for(int i=0; i<tasks.size();i++){
        fout<<i+1<<". "<<tasks[i]<<endl;
    }
    fout.close();
///////////////////////////////////////////////////////////////////
    cout<<endl;
    cout<<"________________________________________________________________________________________________________"<<endl<<endl;
    cout<<"Your tasks are as : "<<endl<<endl;
    for(int i=0; i<tasks.size();i++){
        cout<<"\033[1;34m";
        cout<<"Task "<<i+1<<" :  "<<"\033[0m"<<"\033[1;33m"<<tasks[i]<<"\033[0m"<<endl;
        cout<<"\033[0m";
    }
    cout<<endl;
    
    while(true){
    cout<<"________________________________________________________________________________________________________"<<endl<<endl;
    cout << "\033[1;36m";       
    cout<<"To ADD a new task enter"<<"\033[0m"<< "\033[1;32m"<<"        ADD/add"<<"\033[0m"<<endl;
    cout<< "\033[1;36m"<<"To DELETE any task enter"<<"\033[0m"<< "\033[1;32m"<<"       DELETE/delete"<<"\033[0m"<<endl;
    cout<< "\033[1;36m"<<"To PRINT tasks again enter"<<"\033[0m"<< "\033[1;32m"<<"     PRINT/print"<<"\033[0m"<<endl;
    cout<< "\033[1;36m"<<"To EXIT the program enter"<<"\033[0m"<< "\033[1;32m"<<"      EXIT/exit"<<"\033[0m"<<endl;
    cout<<"\033[0m";
    cout<<endl;
    cout<<"\033[1;31m";
    getline(cin,response1);
    cout<<"\033[0m";
    cout<<endl;
    if(response1=="ADD" || response1 == "add"){
    cout<<"________________________________________________________________________________________________________"<<endl<<endl;       
        int n1;
        cout<<"Enter number of your tasks : ";
        cin>>n1;
        cout<<endl;
        cout<<"Enter yout tasks : "<<endl<<endl;
        cin.ignore();
        for(int i=0; i<n1; i++){
            string tasksAdded;
            cout<<"\033[1;34m";
            cout<<"Task "<<i+1<<" : ";
            cout<<"\033[0m";
            cout << "\033[1;33m";
            getline(cin, tasksAdded);
            cout<<"\033[0m";
            tasks.push_back(tasksAdded);
        }
        cout<<endl;
        cout<<"\033[1;31m";
        cout<<"TASKS ADDED";
        cout<<"\033[0m";
        cout<<endl<<endl;
//////////////////////////////////////////////////////////
    ofstream fout;
    fout.open("tasks.text");
    fout<<"Tasks are : \n";
    for(int i=0; i<tasks.size();i++){
    fout<<i+1<<". "<<tasks[i]<<endl;
    }
    fout.close();
    }
/////////////////////////////////////////////////////////////
    if(response1=="DELETE" || response1 == "delete"){
        cout<<"________________________________________________________________________________________________________"<<endl<<endl;
        int n2;
        cout<<"Enter the task number you want to delete : ";
        cin>>n2;
        cin.ignore();
        tasks.erase(tasks.begin()+n2-1);
        cout<<"Your updated tasks are as : "<<endl<<endl;
        for(int i =0; i<tasks.size(); i++){
            cout<<"\033[1;34m";
            cout<<"Task "<<i+1<<" : "<<"\033[0m"<<"\033[1;32m"<<tasks[i]<<"\033[0m"<<endl;
        }
 //////////////////////////////////////////////////////////       
    ofstream fout;
    fout.open("tasks.text");
    fout<<"Tasks are : \n";
    for(int i=0; i<tasks.size();i++){
       fout<<i+1<<". "<<tasks[i]<<endl;
    }
    fout.close();
///////////////////////////////////////////////////////////
    }
    if(response1=="PRINT" || response1 == "print"){
        cout<<"________________________________________________________________________________________________________"<<endl<<endl;
        cout<<"YOUR TASKS ARE AS : "<<endl<<endl;
        ifstream fin;
        fin.open("tasks.text");
        char c;
        c = fin.get();
        while(!fin.eof()){
            cout<<c;
            c = fin.get();
        }
        fin.close();
        cout<<endl;
    }
    if(response1=="EXIT" || response1 == "exit"){
        cout<<"\033[1;31mENDING THE PROGRAM...\033[0m"<<endl<<endl;
        break;
    }
   
    }

}