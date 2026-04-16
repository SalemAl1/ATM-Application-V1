//DO NOT run this code using Clion
//You can run this code using VS, VS Code, or CodeBlocks
#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>
using namespace std;

struct ATM{
    string name;
    string card_number{};
    string pass{};
    int balance{};
};
int numberOfUsers=5;

void AssignData(ATM user[]);
void DisplayThanks();

int DisplayFirstMenu();

void AdminLogIn(ATM user[]);
int DisplayAdminMenu();
int AccessData(ATM user[]);
void EditData(ATM user[]);

int SignIn(ATM user[]);
void SignUp(ATM user[]);

bool UserMenu(ATM user[], int userNumber);

int main(){
    ATM user[10]; AssignData(user);
    int firstMenuChoice;
    int adminMenuChoice, accessDataChoice;
    int userNumber, userChoice;
    while (true){
        firstMenuChoice=DisplayFirstMenu();
        if (firstMenuChoice==1){
            userNumber=SignIn(user);
            userChoice=UserMenu(user, userNumber);
            if (userChoice)
                return 0;
        }
        else if (firstMenuChoice==2){
            SignUp(user);
        }
        else if (firstMenuChoice==3){
            AdminLogIn(user);
            while (true){
                adminMenuChoice=DisplayAdminMenu();
                if (adminMenuChoice==1){
                    accessDataChoice=AccessData(user);
                    if (accessDataChoice==1)
                        continue;
                    else if (accessDataChoice==2)
                        break;
                }
                else if (adminMenuChoice==2)
                    EditData(user);
                else if (adminMenuChoice==3)
                    break;
            }
        }
        else{
            DisplayThanks();
            return 0;
        }
    }
}

//A function that assign data (Name, card number, password, and balance) to STRUCT array.
void AssignData(ATM user[]) {
    user[0] = {"admin", "0000000000000000", "2005", 0};
    user[1] = {"Ahmed Ali Hassan Mahmoud", "4829174630285913", "7381", 2000};
    user[2] = {"Sara Mohamed Karim El-Sayed", "5372819467032851", "4620", 8900};
    user[3] = {"Mona Youssef Saad Ibrahim", "6083295147381264", "9157", 0};
    user[4] = {"Khaled Ahmed Omar Hassan", "7514836920475193", "3842", 5500};
    user[5] = {"Hala Fathy Mostafa Rami", "1937524867103829", "6745", 1000};
    user[6] = {"", "", "",0};
    user[7] = {"", "", "",0};
    user[8] = {"", "", "",0};
    user[9] = {"","","", 0};
}
//A function displays thank you before closing the code (not important).
void DisplayThanks(){
    for (int i=1; i<=48; i++)
        cout<<"#";
    cout<<"\n";
    for (int i=1; i<=16; i++){
        if (i!=2 && i!=4){
            for (int j=1; j<=48; j++){
                if (j==1 || j==48)
                    cout<<"#";
                else
                    cout<<" ";
            }
            cout<<"\n";
        }
        if (i==2)
            cout<<"#           Thank you for using ATM!           #\n";
    }
    for (int i=1; i<=48; i++)
        cout<<"#";
    cout<<"\n";
    this_thread::sleep_for(chrono::seconds(2));
    system("cls");
}


//A function Display firt menu and return the value of the choice you choose.
int DisplayFirstMenu(){
    int firstMenuChoice;
    while (true){
        for (int i=1; i<=48; i++)
            cout<<"#";
        cout<<"\n";
        for (int i=1; i<=12; i++){
            if (i==3){
                cout<<"#                  1- Sign In                  #\n"
                      "#                  2- Sign Up                  #\n"
                      "#              3-Sign as an admin              #\n"
                      "#                    4-Exit                    #\n";
            }
            else{
                for (int j=1; j<=48; j++){
                    if (j==1 || j==48)
                        cout<<"#";
                    else
                        cout<<" ";

                }
                cout<<"\n";
            }
        }
        for (int i=1; i<=48; i++)
            cout<<"#";
        cout<<"\n";
        cin>>firstMenuChoice;
        system("cls");
        if (firstMenuChoice>=5 || firstMenuChoice<=0){
            for (int i=1; i<=48; i++)
                cout<<"#";
            cout<<"\n";
            for (int i=1; i<=12; i++){
                if (i!=2 && i!=4){
                    for (int j=1; j<=48; j++){
                        if (j==1 || j==48)
                            cout<<"#";
                        else
                            cout<<" ";
                    }
                    cout<<"\n";
                }
                if (i==2)
                    cout<<"#       Not supported, Please try again.       #\n";
            }
            for (int i=1; i<=48; i++)
                cout<<"#";
            cout<<"\n";
            this_thread::sleep_for(chrono::seconds(2));
            system("cls");
        }
        else{
            return firstMenuChoice;
        }
    }
}


//Salem Alsayed part:
//A function asks for the admin number and password to access admin menu.
void AdminLogIn(ATM user[]){
    string adminNumber, adminPassword;
    for (int i=1; i<=17; i++){
        if (i==1 || i==17){
            for (int j=1; j<=48; j++){
                cout<<"#";
            }
            cout<<"\n";
        }
        else if (i==3){
            cout<<"#            Enter  Admin\'s number.            #\n";
        }
        else{
            cout<<"#";
            for (int j=1; j<=46; j++)
                cout<<" ";
            cout<<"#\n";
        }
    }
    while (true){
        cin>>adminNumber;
        system("cls");
        if (adminNumber.size()!=16){
            for (int i=1; i<=17; i++){
                if (i==1 || i==17){
                    for (int j=1; j<=48; j++){
                        cout<<"#";
                    }
                    cout<<"\n";
                }
                else if (i==3){
                    cout<<"#       Enter a 16-digit Admin\'s number.       #\n";
                }
                else{
                    cout<<"#";
                    for (int j=1; j<=46; j++)
                        cout<<" ";
                    cout<<"#\n";
                }
            }
        }
        else if (adminNumber!=user[0].card_number){
            for (int i=1; i<=17; i++){
                if (i==1 || i==17){
                    for (int j=1; j<=48; j++){
                        cout<<"#";
                    }
                    cout<<"\n";
                }
                else if (i==3){
                    cout<<"#    Number is incorrect, Please try again.    #\n";
                }
                else{
                    cout<<"#";
                    for (int j=1; j<=46; j++)
                        cout<<" ";
                    cout<<"#\n";
                }
            }
        }
        else
            break;
    }
    for (int i=1; i<=17; i++){
        if (i==1 || i==17){
            for (int j=1; j<=48; j++){
                cout<<"#";
            }
            cout<<"\n";
        }
        else if (i==3){
            cout<<"#           Enter  Admin\'s password.           #\n";
        }
        else{
            cout<<"#";
            for (int j=1; j<=46; j++)
                cout<<" ";
            cout<<"#\n";
        }
    }
    while (true){
        cin>>adminPassword;
        system("cls");
        if (adminPassword.size()!=4){
            for (int i=1; i<=17; i++){
                if (i==1 || i==17){
                    for (int j=1; j<=48; j++){
                        cout<<"#";
                    }
                    cout<<"\n";
                }
                else if (i==3){
                    cout<<"#      Enter a  4-digit Admin\'s password.      #\n";
                }
                else{
                    cout<<"#";
                    for (int j=1; j<=46; j++)
                        cout<<" ";
                    cout<<"#\n";
                }
            }
        }
        else if (adminPassword!=user[0].pass){
            for (int i=1; i<=17; i++){
                if (i==1 || i==17){
                    for (int j=1; j<=48; j++){
                        cout<<"#";
                    }
                    cout<<"\n";
                }
                else if (i==3){
                    cout<<"#   Password is incorrect, Please try again.   #\n";
                }
                else{
                    cout<<"#";
                    for (int j=1; j<=46; j++)
                        cout<<" ";
                    cout<<"#\n";
                }
            }
        }
        else
            break;
    }
}
//After entering the password number and password correctly:
//This function Display admin's menu then return the value of the choice you choose.
int DisplayAdminMenu(){
    int adminChoice;
    while (true){
        for (int i=1; i<=48; i++)
            cout<<"#";
        cout<<"\n";
        for (int i=1; i<=13; i++){
            if (i!=2 && i!=4){
                for (int j=1; j<=48; j++){
                    if (j==1 || j==48)
                        cout<<"#";
                    else
                        cout<<" ";
                }
                cout<<"\n";
            }
            if (i==2)
                cout<<"#             Administrator mode               #\n";
            if (i==4){
                cout<<"#               1- Access data                 #\n"
                      "#                2- Edit data                  #\n"
                      "#                   3-Exit                     #\n";
            }
        }
        for (int i=1; i<=48; i++)
            cout<<"#";
        cout<<"\n";
        cin>>adminChoice;
        system("cls");
        if (adminChoice>=4 || adminChoice<=0){
            for (int i=1; i<=48; i++)
                cout<<"#";
            cout<<"\n";
            for (int i=1; i<=16; i++){
                if (i!=2 && i!=4){
                    for (int j=1; j<=48; j++){
                        if (j==1 || j==48)
                            cout<<"#";
                        else
                            cout<<" ";
                    }
                    cout<<"\n";
                }
                if (i==2)
                    cout<<"#       Not supported, Please try again.       #\n";
            }
            for (int i=1; i<=48; i++)
                cout<<"#";
            cout<<"\n";
            this_thread::sleep_for(chrono::seconds(2));
            system("cls");
        }
        else{
            return adminChoice;
        }
    }
}
//This function make the user to access and see the data stored.
int AccessData(ATM user[]){
    int accessMenuChoice;
    while (true){
        for (int i=1; i<=7; i++){
            if (i==1 || i==7){
                for (int j=1; j<=48; j++){
                    cout<<"#";
                }
                cout<<"\n";
            }
            else if (i==3){
                cout<<"# Name: "<<user[1].name<<"               #\n";
                cout<<"# Card number: "<<user[1].card_number<<" Password: "<<user[1].pass<<" #\n";
                cout<<"# Name: "<<user[2].name<<"            #\n";
                cout<<"# Card number: "<<user[2].card_number<<" Password: "<<user[2].pass<<" #\n";
                cout<<"# Name: "<<user[3].name<<"              #\n";
                cout<<"# Card number: "<<user[3].card_number<<" Password: "<<user[3].pass<<" #\n";
                cout<<"# Name: "<<user[4].name<<"               #\n";
                cout<<"# Card number: "<<user[4].card_number<<" Password: "<<user[4].pass<<" #\n";
                cout<<"# Name: "<<user[5].name<<"                #\n";
                cout<<"# Card number: "<<user[5].card_number<<" Password: "<<user[5].pass<<" #\n";
            }
            else if (i==5){
                cout<<"#    <-- 1-Back                                #\n"
                      "#        2-Exit                                #\n";
            }
            else{
                cout<<"#";
                for (int j=1; j<=46; j++)
                    cout<<" ";
                cout<<"#\n";
            }
        }
        cin>>accessMenuChoice;
        system("cls");
        if (accessMenuChoice>=3 || accessMenuChoice<=0){
            for (int i=1; i<=48; i++)
                cout<<"#";
            cout<<"\n";
            for (int i=1; i<=12; i++){
                if (i!=2 && i!=4){
                    for (int j=1; j<=48; j++){
                        if (j==1 || j==48)
                            cout<<"#";
                        else
                            cout<<" ";
                    }
                    cout<<"\n";
                }
                if (i==2)
                    cout<<"#       Not supported, Please try again.       #\n";
            }
            for (int i=1; i<=48; i++)
                cout<<"#";
            cout<<"\n";
            this_thread::sleep_for(chrono::seconds(2));
            system("cls");
        }
        else
            return accessMenuChoice;
    }
}
//The user can edit the data stored using this function.
void EditData(ATM user[]){
    int editUser, editChoice=1;
    string name, cardNumber, password;
    while (editChoice==1){
        for (int i=1; i<=17; i++){
            if (i==1 || i==17){
                for (int j=1; j<=48; j++){
                    cout<<"#";
                }
                cout<<"\n";
            }
            else if (i==3){
                cout<<"#       Choose which user to edit  (1-"<<numberOfUsers<<")       #\n";
            }
            else{
                cout<<"#";
                for (int j=1; j<=46; j++)
                    cout<<" ";
                cout<<"#\n";
            }
        }
        while (true){
            cin>>editUser;
            system("cls");
            if (editUser>numberOfUsers || editUser<1){
                for (int i=1; i<=17; i++){
                    if (i==1 || i==17){
                        for (int j=1; j<=48; j++){
                            cout<<"#";
                        }
                        cout<<"\n";
                    }
                    else if (i==3){
                        cout<<"#         Please choose between 1 and "<<numberOfUsers<<"        #\n";
                    }
                    else{
                        cout<<"#";
                        for (int j=1; j<=46; j++)
                            cout<<" ";
                        cout<<"#\n";
                    }
                }
            }
            else
                break;
        }
        for (int i=1; i<=17; i++){
            if (i==1 || i==17){
                for (int j=1; j<=48; j++){
                    cout<<"#";
                }
                cout<<"\n";
            }
            else if (i==3){
                cout<<"#          Please enter the new names.         #\n";
            }
            else{
                cout<<"#";
                for (int j=1; j<=46; j++)
                    cout<<" ";
                cout<<"#\n";
            }
        }
        cin>>name;
        user[editUser].name.clear();
        user[editUser].name=name;
        system("cls");
        for (int i=1; i<=17; i++){
            if (i==1 || i==17){
                for (int j=1; j<=48; j++){
                    cout<<"#";
                }
                cout<<"\n";
            }
            else if (i==3){
                cout<<"#        Please enter a 16-digit number.       #\n";
            }
            else{
                cout<<"#";
                for (int j=1; j<=46; j++)
                    cout<<" ";
                cout<<"#\n";
            }
        }
        while (true){
            cin>>cardNumber;
            system("cls");
            if (cardNumber.size()!=16){
                for (int i=1; i<=17; i++){
                    if (i==1 || i==17){
                        for (int j=1; j<=48; j++){
                            cout<<"#";
                        }
                        cout<<"\n";
                    }
                    else if (i==3){
                        cout<<"#        Please enter a 16-DIGIT number.       #\n";
                    }
                    else{
                        cout<<"#";
                        for (int j=1; j<=46; j++)
                            cout<<" ";
                        cout<<"#\n";
                    }
                }
            }
            else
                break;
        }
        user[editUser].card_number.clear();
        user[editUser].card_number=cardNumber;
        for (int i=1; i<=17; i++){
            if (i==1 || i==17){
                for (int j=1; j<=48; j++){
                    cout<<"#";
                }
                cout<<"\n";
            }
            else if (i==3){
                cout<<"#        Please enter a  4-digit number.       #\n";
            }
            else{
                cout<<"#";
                for (int j=1; j<=46; j++)
                    cout<<" ";
                cout<<"#\n";
            }
        }
        while (true){
            cin>>password;
            system("cls");
            if (password.size()!=4){
                for (int i=1; i<=17; i++){
                    if (i==1 || i==17){
                        for (int j=1; j<=48; j++){
                            cout<<"#";
                        }
                        cout<<"\n";
                    }
                    else if (i==3){
                        cout<<"#        Please enter a  4-DIGIT number.       #\n";
                    }
                    else{
                        cout<<"#";
                        for (int j=1; j<=46; j++)
                            cout<<" ";
                        cout<<"#\n";
                    }
                }
            }
            else
                break;
        }
        user[editUser].pass.clear();
        user[editUser].pass=password;
        for (int i=1; i<=15; i++){
            if (i==1 || i==15){
                for (int j=1; j<=48; j++){
                    cout<<"#";
                }
                cout<<"\n";
            }
            else if (i==3){
                cout<<"#              Make another edit ?             #\n"
                      "#                    1- Yes                    #\n"
                      "#                     2-No                     #\n";
            }
            else{
                cout<<"#";
                for (int j=1; j<=46; j++)
                    cout<<" ";
                cout<<"#\n";
            }
        }
        while (true){
            cin>>editChoice;
            system("cls");
            if (editChoice>2 || editChoice<1){
                for (int i=1; i<=48; i++)
                    cout<<"#";
                cout<<"\n";
                for (int i=1; i<=16; i++){
                    if (i!=2 && i!=4){
                        for (int j=1; j<=48; j++){
                            if (j==1 || j==48)
                                cout<<"#";
                            else
                                cout<<" ";
                        }
                        cout<<"\n";
                    }
                    if (i==2)
                        cout<<"#       Not supported, Please try again.       #\n";
                }
                for (int i=1; i<=48; i++)
                    cout<<"#";
                cout<<"\n";
            }
            else
                break;
        }
    }
}


//Ziad Mahmoud part:
//The user can sign in using this function.
//This function uses the data that already stored.
int SignIn(ATM user[]){
    string cardNumber, password;
    int index=0;
    int test_card_number=1;
    for (int i=1; i<=17; i++){
        if (i==1 || i==17){
            for (int j=1; j<=48; j++){
                cout<<"#";
            }
            cout<<"\n";
        }
        else if (i==3){
            cout<<"#        Please enter the card number .        #\n";
        }
        else{
            cout<<"#";
            for (int j=1; j<=46; j++)
                cout<<" ";
            cout<<"#\n";
        }
    }
    while(test_card_number>0) {
        cin>>cardNumber;
        system("cls");
        for (int k=0; k<6; ++k) {
            if (cardNumber==user[k].card_number) {
                for (int i=1; i<=17; i++){
                    if (i==1 || i==17){
                        for (int j=1; j<=48; j++){
                            cout<<"#";
                        }
                        cout<<"\n";
                    }
                    else if (i==3){
                        cout<<"#             Enter the password .             #\n";
                    }
                    else{
                        cout<<"#";
                        for (int j=1; j<=46; j++)
                            cout<<" ";
                        cout<<"#\n";
                    }
                }
                test_card_number=0;
                index=k;
                break;
            }
        }
        if(!index){
            for (int i=1; i<=16; i++){
                if (i==1 || i==16){
                    for (int j=1; j<=48; j++){
                        cout<<"#";
                    }
                    cout<<"\n";
                }
                else if (i==3){
                    cout<<"#    The card number you entered is wrong .    #\n"
                          "#              Please try again .              #\n";
                }
                else{
                    cout<<"#";
                    for (int j=1; j<=46; j++)
                        cout<<" ";
                    cout<<"#\n";
                }
            }
        }
    }
    while(true){
        cin>>password;
        system("cls");
        if(password==user[index].pass){
            return index;
        }
        else{
            for (int i=1; i<=17; i++){
                if (i==1 || i==17){
                    for (int j=1; j<=48; j++){
                        cout<<"#";
                    }
                    cout<<"\n";
                }
                else if (i==3){
                    cout<<"#   Password is incorrect, Please try again.   #\n";
                }
                else{
                    cout<<"#";
                    for (int j=1; j<=46; j++)
                        cout<<" ";
                    cout<<"#\n";
                }
            }
        }
    }
}
//The user can sign up using this function.
//This function stores data that the user entered to use it in SignIn function.
void SignUp(ATM user[]){
    string cardNumber, password;
    for (int i=1; i<=48; i++)
        cout<<"#";
    cout<<"\n";
    for (int i=1; i<=16; i++){
        if (i!=2 && i!=4){
            for (int j=1; j<=48; j++){
                if (j==1 || j==48)
                    cout<<"#";
                else
                    cout<<" ";
            }
            cout<<"\n";
        }
        if (i==2)
            cout<<"#     Please enter a 16-digit card number.     #\n";
    }
    for (int i=1; i<=48; i++)
        cout<<"#";
    cout<<"\n";
    int test_card_number=1, test_pass_number=1, index=6;
    while (test_card_number>0) {
        cin>>cardNumber;
        system("cls");
        if (cardNumber.size()!=16){
            for (int i=1; i<=48; i++)
                cout<<"#";
            cout<<"\n";
            for (int i=1; i<=16; i++){
                if (i!=2 && i!=4){
                    for (int j=1; j<=48; j++){
                        if (j==1 || j==48)
                            cout<<"#";
                        else
                            cout<<" ";
                    }
                    cout<<"\n";
                }
                if (i==2)
                    cout<<"#       Please enter a 16-digit number .       #\n";
            }
            for (int i=1; i<=48; i++)
                cout<<"#";
            cout<<"\n";
            continue;
        }
        for (int i = 0; i < 16; ++i) {
            if (cardNumber[i] < 48 || cardNumber[i] > 57) {
                for (int k=1; k<=48; k++)
                    cout<<"#";
                cout<<"\n";
                for (int k=1; k<=15; k++){
                    if (k!=2 && k!=4){
                        for (int j=1; j<=48; j++){
                            if (j==1 || j==48)
                                cout<<"#";
                            else
                                cout<<" ";
                        }
                        cout<<"\n";
                    }
                    if (k==2)
                        cout<<"#       You have entered a wrong digit .       #\n"
                              "#              please try again .              #\n";
                }
                for (int k=1; k<=48; k++)
                    cout<<"#";
                cout<<"\n";
                test_card_number=1;
                break;
            }
            else{
                test_card_number=0;
            }
        }
    }
    for (int i=1; i<=48; i++)
        cout<<"#";
    cout<<"\n";
    for (int i=1; i<=16; i++){
        if (i!=2 && i!=4){
            for (int j=1; j<=48; j++){
                if (j==1 || j==48)
                    cout<<"#";
                else
                    cout<<" ";
            }
            cout<<"\n";
        }
        if (i==2)
            cout<<"#        Please enter a 4-digit number.        #\n";
    }
    for (int i=1; i<=48; i++)
        cout<<"#";
    cout<<"\n";
    while(test_pass_number){
        cin>>password;
        system("cls");
        if (password.size()!=4){
            for (int i=1; i<=48; i++)
                cout<<"#";
            cout<<"\n";
            for (int i=1; i<=16; i++){
                if (i!=2 && i!=4){
                    for (int j=1; j<=48; j++){
                        if (j==1 || j==48)
                            cout<<"#";
                        else
                            cout<<" ";
                    }
                    cout<<"\n";
                }
                if (i==2)
                    cout<<"#        Please enter a 4-digit number.        #\n";
            }
            for (int i=1; i<=48; i++)
                cout<<"#";
            cout<<"\n";
            continue;
        }
        for (int i = 0; i < 4; ++i) {
            if (password[i] < 48 || password[i] > 57) {
                for (int k=1; k<=48; k++)
                    cout<<"#";
                cout<<"\n";
                for (int k=1; k<=16; k++){
                    if (k!=2 && k!=4){
                        for (int j=1; j<=48; j++){
                            if (j==1 || j==48)
                                cout<<"#";
                            else
                                cout<<" ";
                        }
                        cout<<"\n";
                    }
                    if (k==2)
                        cout<<"#        Please enter a 4-digit number.        #\n";
                }
                for (int k=1; k<=48; k++)
                    cout<<"#";
                cout<<"\n";
                test_pass_number=1;
                break;
            }
            else{
                test_pass_number=0;
            }
        }
    }
    user[index].card_number=cardNumber;
    user[index].pass=password;
    numberOfUsers++;
}

//Saif and Ziad Sayed part:
//This function display user's menu after the user signs in.
bool UserMenu(ATM user[], int userNumber){
    int deposit_amount, withdrawal_amount, userChoice, inUserChoice=1;
    char check;
    double dollar, amount=user[userNumber].balance;
    while (inUserChoice==1){
        while (true){
            for (int i=1; i<=12; i++){
                if (i==1 || i==12){
                    for (int j=1; j<=48; j++){
                        cout<<"#";
                    }
                    cout<<"\n";
                }
                else if (i==3){
                    cout << "#                Menu oprations                #\n"
                            "#               1. Check balance               #\n"
                            "#                  2. Deposit                  #\n"
                            "#                 3.withdrawal                 #\n"
                            "#              4. Change currency              #\n"
                            "#                    5.Exit                    #\n";
                }
                else{
                    cout<<"#";
                    for (int j=1; j<=46; j++)
                        cout<<" ";
                    cout<<"#\n";
                }
            }
            cin>>userChoice;
            system("cls");
            if (userChoice>5 || userChoice<1){
                for (int i=1; i<=48; i++)
                    cout<<"#";
                cout<<"\n";
                for (int i=1; i<=16; i++){
                    if (i!=2 && i!=4){
                        for (int j=1; j<=48; j++){
                            if (j==1 || j==48)
                                cout<<"#";
                            else
                                cout<<" ";
                        }
                        cout<<"\n";
                    }
                    if (i==2)
                        cout<<"#       Not supported, Please try again.       #\n";
                }
                for (int i=1; i<=48; i++)
                    cout<<"#";
                cout<<"\n";
                this_thread::sleep_for(chrono::seconds(2));
                system("cls");
            }
            else
                break;
        }
        switch (userChoice) {
            case 1 :
                for (int i=1; i<=48; i++)
                    cout<<"#";
                cout<<"\n";
                for (int i=1; i<=14; i++){
                    if (i!=2 && i!=4){
                        for (int j=1; j<=48; j++){
                            if (j==1 || j==48)
                                cout<<"#";
                            else
                                cout<<" ";
                        }
                        cout<<"\n";
                    }
                    if (i==2){
                        cout<<"#         Your account balance is "<<amount<<"         #\n";
                        cout<<"#         1-Back                               #\n"
                              "#         2-Exit                               #\n";
                    }

                }
                for (int i=1; i<=48; i++)
                    cout<<"#";
                cout<<"\n";
                cin>>inUserChoice;
                system("cls");
                break;

            case 2 :
                while (true){
                    for (int i=1; i<=48; i++)
                        cout<<"#";
                    cout<<"\n";
                    for (int i=1; i<=16; i++){
                        if (i!=2 && i!=4){
                            for (int j=1; j<=48; j++){
                                if (j==1 || j==48)
                                    cout<<"#";
                                else
                                    cout<<" ";
                            }
                            cout<<"\n";
                        }
                        if (i==2)
                            cout<<"#          Enter the deposit amount .          #\n";
                    }
                    for (int i=1; i<=48; i++)
                        cout<<"#";
                    cout<<"\n";
                    cin >> deposit_amount;
                    system("cls");
                    if (deposit_amount <= 32E3 && deposit_amount >= 50) {
                        amount += deposit_amount;
                        for (int i=1; i<=48; i++)
                            cout<<"#";
                        cout<<"\n";
                        for (int i=1; i<=11; i++){
                            if (i!=2 && i!=4){
                                for (int j=1; j<=48; j++){
                                    if (j==1 || j==48)
                                        cout<<"#";
                                    else
                                        cout<<" ";
                                }
                                cout<<"\n";
                            }
                            if (i==2)
                                cout<<"#      The amount has been deposited into      #\n"
                                      "#           your account, thank you.           #\n"
                                      "#      1-Back                                  #\n"
                                      "#      2-Exit                                  #\n";
                        }
                        for (int i=1; i<=48; i++)
                            cout<<"#";
                        cout<<"\n";
                        cin>>inUserChoice;
                        system("cls");
                        break;
                    }
                    else{
                        for (int i=1; i<=48; i++)
                            cout<<"#";
                        cout<<"\n";
                        for (int i=1; i<=14; i++){
                            if (i!=2 && i!=4){
                                for (int j=1; j<=48; j++){
                                    if (j==1 || j==48)
                                        cout<<"#";
                                    else
                                        cout<<" ";
                                }
                                cout<<"\n";
                            }
                            if (i==2)
                                cout << "#           Invalid deposit amount .           #\n";
                        }
                        for (int i=1; i<=48; i++)
                            cout<<"#";
                        cout<<"\n";
                    }
                }
                break;
            case 3 :
                while (true){
                    for (int i=1; i<=48; i++)
                        cout<<"#";
                    cout<<"\n";
                    for (int i=1; i<=16; i++){
                        if (i!=2 && i!=4){
                            for (int j=1; j<=48; j++){
                                if (j==1 || j==48)
                                    cout<<"#";
                                else
                                    cout<<" ";
                            }
                            cout<<"\n";
                        }
                        if (i==2)
                            cout<<"#         Enter the withdrawal amount.         #\n";
                    }
                    for (int i=1; i<=48; i++)
                        cout<<"#";
                    cout<<"\n";
                    cin >> withdrawal_amount;
                    system("cls");
                    if (withdrawal_amount >= 50) {
                        if (amount - withdrawal_amount >= 0) {
                            amount -= withdrawal_amount;
                            for (int i=1; i<=48; i++)
                                cout<<"#";
                            cout<<"\n";
                            for (int i=1; i<=13; i++){
                                if (i!=2 && i!=4){
                                    for (int j=1; j<=48; j++){
                                        if (j==1 || j==48)
                                            cout<<"#";
                                        else
                                            cout<<" ";
                                    }
                                    cout<<"\n";
                                }
                                if (i==2)
                                    cout<<"#     The amount  has been withdrawal from     #\n"
                                          "#           your account, thank you.           #\n"
                                          "#     1-Back                                   #\n"
                                          "#     2-Exit                                   #\n";
                            }
                            for (int i=1; i<=48; i++)
                                cout<<"#";
                            cout<<"\n";
                            cin>>inUserChoice;
                            system("cls");
                            break;
                        }
                        else {
                            for (int i=1; i<=48; i++)
                                cout<<"#";
                            cout<<"\n";
                            for (int i=1; i<=16; i++){
                                if (i!=2 && i!=4){
                                    for (int j=1; j<=48; j++){
                                        if (j==1 || j==48)
                                            cout<<"#";
                                        else
                                            cout<<" ";
                                    }
                                    cout<<"\n";
                                }
                                if (i==2)
                                    cout<<"#            Insufficient balance .            #\n";
                            }
                            for (int i=1; i<=48; i++)
                                cout<<"#";
                            cout<<"\n";
                            this_thread::sleep_for(chrono::seconds(2));
                            system("cls");
                        }
                    }
                }
                break;
            case 4 :
                do {
                    for (int i=1; i<=48; i++)
                        cout<<"#";
                    cout<<"\n";
                    for (int i=1; i<=16; i++){
                        if (i!=2 && i!=4){
                            for (int j=1; j<=48; j++){
                                if (j==1 || j==48)
                                    cout<<"#";
                                else
                                    cout<<" ";
                            }
                            cout<<"\n";
                        }
                        if (i==2)
                            cout<<"#       Enter how many dollars you need.       #\n";
                    }
                    for (int i=1; i<=48; i++)
                        cout<<"#";
                    cout<<"\n";
                    cin>>dollar;
                    system("cls");
                    dollar*=50;
                    if(dollar >amount){
                        check=true;
                    }else{
                        check=false;
                    }
                }
                while (check);
                amount-=dollar;
                for (int i=1; i<=48; i++)
                    cout<<"#";
                cout<<"\n";
                for (int i=1; i<=16; i++){
                    if (i!=2 && i!=4){
                        for (int j=1; j<=48; j++){
                            if (j==1 || j==48)
                                cout<<"#";
                            else
                                cout<<" ";
                        }
                        cout<<"\n";
                    }
                    if (i==2)
                        cout<<"#            Your new balance: "<<amount<<"            #\n";
                }
                for (int i=1; i<=48; i++)
                    cout<<"#";
                cout<<"\n";
                this_thread::sleep_for(chrono::seconds(2));
                system("cls");
                break;
            case 5 :
                DisplayThanks();
                return true;
            default :
                for (int i=1; i<=48; i++)
                    cout<<"#";
                cout<<"\n";
                for (int i=1; i<=16; i++){
                    if (i!=2 && i!=4){
                        for (int j=1; j<=48; j++){
                            if (j==1 || j==48)
                                cout<<"#";
                            else
                                cout<<" ";
                        }
                        cout<<"\n";
                    }
                    if (i==2)
                        cout<<"#       Not supported, Please try again.       #\n";
                }
                for (int i=1; i<=48; i++)
                    cout<<"#";
                cout<<"\n";
                break;
        }
    }
}