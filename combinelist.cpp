#include<iostream>
#include<conio.h>
#include"singlelist.cpp"
#include"doublylist.cpp"
class MainLinkList
{
public:
    SLinkList s;
    DLinkList d;
    void MainLinkListModule()
    {
        system("cls");
        cout<<"------ Welcome In Link List Project ------\n\n";
        cout<<"1. Singly Link List \n\n";
        cout<<"2. Doubly Link List \n\n";
        cout<<"3. Exit \n\n";
        cout<<"Choose any one of list....";
        char c = getch();
        if ( c == '1'){
            s.mainmenu();
        }
        else if ( c == '2'){
            d.mainmenu();
        }
        else if ( c == '3'){
                cout<<"\n\n Thank You for Using My App..\n\n";
                cout<<"Design & Coded By -- Pooja Khandelwal.. \n\n";
                exit(0);
        }

    }

};
int main()
{
    MainLinkList mll;
    mll.MainLinkListModule();
    cout<<"\n\n Thank You for Using My App..\n\n";
    cout<<"Design & Coded By -- Pooja Khandelwal.. \n\n";
}

