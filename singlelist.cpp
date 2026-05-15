#include<iostream>
#include<string>
#include<conio.h>
using namespace std;
class NODE
{
public:
     string ID, UNAME, TWEET;
     NODE *NEXT;
     NODE( string x, string y, string z)
     {
         ID = x;
         UNAME = y;
         TWEET = z;
         NEXT = nullptr;
     }
};
class SLinkList
{
public:
    string TID, UName, UTweet;
    int TIDA, countnode;
    NODE *START, *END;
    SLinkList()
    {
        TIDA = 1001;
        countnode = 0;
        START = nullptr;
        END = nullptr;
    }
    void userinput()
    {
        TID = "TWEET" + to_string(TIDA);
        cout<<"Entered TID--"<<TID<<endl;
        cin.ignore();
        cout<<"Enter User Name--";
        getline(cin,UName);
        cout<<"Enter User TWEET--";
        getline(cin,UTweet);

    }
    void countednode()
    {
        system("cls");
        cout<<"Counted Node in LinkList..\n\n";
        cout<<"Total Nodes--"<<countnode<<" Nodes Availabed\n";
    }
    char continuecheck()
    {
        char c;
        cout<<"\n\nDo You Want.. \n";
        cout<<"1. Continue With Same\n";
        cout<<"2. Go to Previous Menu\n";
        cout<<"3. Go to Main Menu..\n";
        cout<<"4. Exit\n";
        c = getch();
        if ( c == '4'){
            thanksLine();
            exit(0);
        }
        else{
            return (c);
        }
    }



    int insertnode(int opr)
    {
        system("cls");
        if( opr == 1)
        {
            cout<<"\n INSERT AT BEGINNING...\n\n";
            userinput();
            NODE *TEMP = new NODE(TID,UName,UTweet);
            if (TEMP == nullptr){
                cout<<"INSUFICIENT MEMORY..TRY AGAIN..\n";
                return 0;
            }
            if (START == nullptr){
                END = START = TEMP;
            }
            else{
                TEMP->NEXT = START;
                START = TEMP;
            }
            countnode++;
            TIDA++;
        }
        else if( opr == 2){
            cout<<"\n INSERT AT END...\n\n";
            userinput();
            NODE *TEMP = new NODE(TID,UName,UTweet);
            if (TEMP == nullptr){
                cout<<"INSUFICIENT MEMORY..TRY AGAIN..\n";
                return 0;
            }
            if (START == nullptr){
                END = START = TEMP;
            }
            else{
                END->NEXT = TEMP;
                END = TEMP;
            }
            countnode++;
            TIDA++;
        }
         else if (opr = 3){
            cout<<"\n INSERT AT GIVING POSIOTIN...\n";
            cout<<"Total Nodes -- "<<countnode<<"\n\n";
            userinput();
            int pos;
            cout<<"Enter Position of Node between 0 to "<<countnode<<"---";
            cin>>pos;
            NODE *TEMP = new NODE(TID,UName, UTweet);
            if ( TEMP == nullptr){
                cout<<"Insufficient Memory.. \n";
                return 0;
            }
            int i;
            NODE *TEMP1 = START;
            for ( i = 2 ; i < pos ; i++){
                TEMP1 = TEMP1->NEXT;
            }
            if ( START == nullptr){
                END = START = TEMP;
            }
            else{
                TEMP->NEXT = TEMP1->NEXT;
                TEMP1->NEXT = TEMP;
                if (TEMP1 == END){
                    END = TEMP1->NEXT;
                }
            }
            countnode++;
            TIDA++;
        }
        char c = continuecheck();
        if (c == '1')
            insertnode(opr);
        else if ( c == '2')
            insertionoperation();
        else if ( c == '3')
            mainmenu();
    }
        int insertionoperation()
        {
            system("cls");
            cout<<"INSERTION OPERATION\n\n";
            cout<<"1. Insert At Beginning\n";
            cout<<"2. Insert At End\n";
            cout<<"3. Insert At Giving Position\n";
            char c = getch();
            if (c == '1'){
                insertnode(1);
            }
            else if (c == '2'){
                    insertnode(2);

            }
           else if (c == '3'){
                    insertnode(3);
            }
            else if (c == '4'){
                    mainmenu();
            }
            else if (c == '5'){
                    thanksLine();
                    exit(0);
            }
        }
        void traverselist()
        {
            cout<<"\n SINGLY LINKLIST -- \n\n";
        cout<<"* Head -> ";
        NODE *TEMP = START;
        if ( START == nullptr){
            cout<<"NULL \n\nlist is empty\n";
        }
        else{
            while ( TEMP!= nullptr){
                cout<<"["<<TEMP->ID<<", ";
                cout<<TEMP->UNAME<<", ";
                cout<<TEMP->TWEET<<"] -> ";
                TEMP = TEMP->NEXT;
            }
            cout<<"NULL";
        }
    }
        int searchtweetinnode()
        {
        cout<<"\n\nSearch Tweet in Nodes -- \n\n";
        cout<<"* Head -> ";
        NODE *TEMP = START;
        if ( START == nullptr){
            cout<<"NULL \n\nlist is empty\n";
            return 0;
        }
        else{
            cout<<"\n\n Enter User Name To Find Tweets -- ";
            string uname;
            int counter = 0;
            getline(cin,uname);
            while ( TEMP!= nullptr){
                if (TEMP->UNAME == uname)
                {
                    cout<<"\n["<<TEMP->ID<<", ";
                    cout<<TEMP->UNAME<<", ";
                    cout<<TEMP->TWEET<<"]\n";
                    counter++;
                }
                TEMP = TEMP->NEXT;
            }
            if ( counter == 0){
                cout<<"\n No Tweet Found..\n\n";
            }
        }
        char c;
        cout<<"\n\n Do You Want To .. \n";
        cout<<"1. Continue With Same\n";
        cout<<"2. Go To Main Menu..\n";
        cout<<"3. Exit\n";
        c = getch();
        if (c == '1')
            searchtweetinnode();
        else if ( c == '2')
            mainmenu();
        else if ( c == '3'){
            thanksLine();
            exit(0);
        }
    }
    int deletenode(int opr)
    {
        NODE *TEMP;
        if ( opr == 1){
            cout<<"\n\n DELETE FROM BEGINNING... \n\n";

            if ( START == nullptr)
            {
                cout<<"\n\nLinkList is Empty.. \n\n";
                return 0;
            }
            else if ( START->NEXT == nullptr){
                TEMP = START;
                END = START = nullptr;
            }
            else{
                TEMP = START;
                START = START->NEXT;
            }
            countnode--;
            delete(TEMP);
            cout<<"\n\n Node Deleted Successfully...\n\n";
        }
        else if ( opr == 2){
            cout<<"\n\n DELETE FROM END... \n\n";
            if ( START == nullptr)
            {
                cout<<"\n LinkList is Empty.. \n\n";
                return 0;
            }
            else if ( START->NEXT == nullptr){
                TEMP = START;
                END = START = nullptr;
            }
            else{
                TEMP = START;
                while ( TEMP->NEXT != END)
                {

                    TEMP = TEMP->NEXT;
                }
                NODE *T1 = END;
                TEMP->NEXT = nullptr;
                END = TEMP;
                delete(T1);
            }
            countnode--;
            cout<<"\n\n Node Deleted Successfully...\n\n";
        }
      else if ( opr == 3){
            cout<<"\n DELETE FROM GIVEN POSITION... \n\n";

            if ( START == nullptr )
            {
                cout<<"\nLinkList is Empty.. \n\n";
                return 0;
            }
            int pos;
            cout<<"Enter Desire Position for Delete 1 - "<<countnode<<"-- ";
            cin>>pos;
            if ( pos == 1 && START == END )
            {
                TEMP = START;
                START = END = nullptr;
            }
            else{
                TEMP = START;
                for (int i = 2 ; i < pos ; i++)
                {
                    TEMP = TEMP->NEXT;
                }
                if (TEMP->NEXT == END){
                    NODE *T1 = END;
                    TEMP->NEXT = nullptr;
                    END = TEMP;
                }
                else{
                    NODE *T1 = TEMP->NEXT;
                    TEMP->NEXT = T1->NEXT;
                    delete(T1);
                }
            }
            countnode--;
            cout<<"\n Node Deleted Successfully...\n\n";
        }
        char c = continuecheck();
        if (c == '1')
            deletenode(opr);
        else if ( c == '2')
            deleteoperation();
        else if ( c == '3')
            mainmenu();

}
    int deleteoperation()
    {
        system("cls");
        cout<<"\n DELETE OPERATIONS..\n\n";
        cout<<"1. DELETE FROM BEGINNING\n";
        cout<<"2. DELETE FROM END\n";
        cout<<"3. DELETE FROM GIVEN POSITION\n";
        cout<<"4. Go to Main Menu\n";
        cout<<"5. Exit.\n";
        char c = getch();
        if ( c == '1'){
            deletenode(1);
        }
        else if ( c == '2'){
            deletenode(2);
        }
        else if ( c == '3'){
            deletenode(3);
        }
        else if ( c == '4'){
            mainmenu();
        }
        else if ( c == '5'){
            thanksLine();
            exit(0);
        }
    }


    void mainmenu()
    {
        system("cls");
        cout<<"####### SINGLY LINKLIST #######\n\n";
        cout<<"1. Insertion Operation\n";
        cout<<"2. Traversal Operation\n";
        cout<<"3. Delete Operation\n";
        cout<<"4. Search Operation\n";
        cout<<"5. Count Nodes\n";
        cout<<"6. Exit\n";
        cout<<"Go With One Operation -- ";
        char c = getch();
        if ( c == '1'){
            insertionoperation();
        }
        else if ( c == '2'){
            traverselist();
        }
        else if ( c == '3'){
                deleteoperation();

        }
        else if ( c == '4'){
        searchtweetinnode();
        }
        else if ( c == '5'){
                countednode();

        }
        else if ( c == '6'){
            thanksLine();
            exit(0);
        }
        cout<<"\n\n Do you want to Continue .. Press 1 else press any key..";
        c = getch();
        if ( c == '1'){
            mainmenu();
        }
    }
    void thanksLine()
    {
        cout<<"\n\n Thank You for Using My App...\n\n";
    }

};
/*int main()
{
    SLinkList s;
    s.mainmenu();
    cout<<"\n\n Thank You For Using My App...\n\n";
}*/

