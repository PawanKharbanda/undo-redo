//
//  main.cpp
//  Undo-Redo
//
//  Created by Pawan
//  Copyright © 2018 Pawan. All rights reserved.
//

#include <iostream>
#include<string.h>
#include<cstring>
using namespace std;
class change
{
public:
    change();
    int top_undo=-1;
    int top_redo=-1;
    string input;
    string undo_backend[100];
    string redo_backend[100];
    void undo();
    void  redo();
    void change_state();
    void print();
    void save_state();
    void edit();
    void del();
};
change::change()
{
top_undo=-1;
 top_redo=-1;
    
}
void change::save_state()
{
   
top_undo++;
undo_backend[top_undo]=input;
}

void change::change_state()
{
   getline(cin,input);
    change::save_state();
    

}
void change::redo()
{
    
    if(top_redo>-1)
    {
       
        cout<<redo_backend[top_redo]<<endl;
        top_undo++;
        undo_backend[top_undo]=redo_backend[top_redo];
        top_redo--;
    }
}
void change::undo()
{
    
    if(top_undo>0)
    {
        
        top_redo++;
        redo_backend[top_redo]=undo_backend[top_undo];
        top_undo--;
        cout<<undo_backend[top_undo]<<" "<<top_undo<<endl;
    }
}
void change::print()
{
   /* while(top_redo>-1)
    {
        cout<<redo_backend[top_redo]<<endl;
        top_redo--;
    }*/
    /*while(top_undo>-1)
    {
        cout<<undo_backend[top_undo]<<top_undo<<endl;
        top_undo--;
    }*/
    
}
void change::edit()
{
    int pos,i;
    string n_str,str,a;
    getline(cin,n_str);
    cout<<"Enter Position"<<endl;
    cin>>pos;
    str=undo_backend[top_undo];
    
    a.resize(str.length()+n_str.length());
    for(i=0;i<pos;i++)
    {
        
        a[i]=str[i];
        
    }
    for(int j=0;j<n_str.length();j++)
    {
        a[i]=n_str[j];
        i++;
    }
    for(int j=pos;j<str.length();j++)
    {
        a[i]=str[j];
        i++;
    }
    top_undo++;
    undo_backend[top_undo]=a;
}


void change::del()
{
    int s_pos,e_pos,i;
    string str,a;
    str=undo_backend[top_undo];
    a.resize(str.length());
    cout<<"Enter starting and ending position"<<endl;
    cin>>s_pos>>e_pos;
    for( i=0;i<s_pos;i++)
    {
        a[i]=str[i];
    }
    for(int j=e_pos;j<str.length();j++)
    {
        a[i]=str[j];
        i++;
    }
    top_undo++;
    undo_backend[top_undo]=a;
    
}

int main()
{int c;
    change obj;
    int f=1;
    while(f)
    {
        cout<<"Press 1 for Entering string"<<endl;
        cout<<"Press 2 for Undo"<<endl;
        cout<<"Press 3 for Redo"<<endl;
        cout<<"Press 4 for Editing"<<endl;
        cout<<"Press 5 for Deleting"<<endl;
        cout<<"Press 6 for Exit"<<endl;
        
        cin>>c;
    switch (c)
    {
        case 1:
            obj.change_state();
            break;
        case 2:
            obj.undo();
            break;
        case 3:
            obj.redo();
            break;
        case 4:
            obj.edit();
            break;
        case 5:
            obj.del();
            break;
        case 6:
            f=0;
            break;
            
    }
    
    }
    

    
    return 0;
}
