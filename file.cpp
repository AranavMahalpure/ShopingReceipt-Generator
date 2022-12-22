#include<iostream>
#include<fstream>
#include<string.h>

using namespace std;
class shopping 
{

  private:
    int pcode;
    float price;
    float dis;
    string pname;

public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void remove1();
    void list();
    void receipt();
};

void shopping :: menu()
{   
    m:
    int choice;
    string email;
    string password;   
    cout<<"---------------Welcome All to @vnm Mall---------------\n";
    cout<<"               ___________________                \n";
    cout<<"                                                  \n";
    cout<<"---------------   Mall MainMenu  ---------------\n";
    cout<<"               ___________________                \n";
    cout<<" 1) Administrator\n\n";
    cout<<" 2) Buyer\n\n";
    cout<<" 3) Exit\n\n";
    cout<<"........... Please select from above List.........\n";
    cin>>choice;
    switch(choice){case 1: administrator();
        /*case 1:
            cout<<"Please Login Here.........................\n";
            cout<<"Enter your Email\n";
            cin>>email;
            cout<<"Enter your password\n";
            cin>>password;
             if(email=="aranav1289@gmail.com" && password=="Aranav@1289"){
                administrator();
             }
             else{
                cout<<"Invalid Email ID  Please Try again Later .......................\n"; 
             }
             break;*/
        case 2:
            {
                buyer();
            }
        case 3:
            {
                exit(0);
            }
        default: 
            {
                cout<<"Please select form the given Option Again.....\n";
            }
    }goto m;
}
void shopping :: administrator()
{   
    m:
    int choice;
    cout<<"               ___________________                \n";
    cout<<"                                                  \n";
    cout<<"----------------administrator Menu---------------\n";
    cout<<"               ___________________                \n";
    cout<<" 1) Add Product        \n\n";
    cout<<" 2) Modify the Product \n\n";
    cout<<" 3) Delete the Product \n\n";
    cout<<" 4) back to Main menu \n\n";
    cout<<" Please Enter your choice...........\n";
    cin>>choice;
    switch(choice){
        case 1:
        {
            add();
            break;
        }
        case 2:
        {
            edit();
            break;
        
        }
        case 3:
        {
            remove1();
            break;
        }
        case 4:
        {
             menu();
        }
        default:
            cout<<"Invalid chioce..............\n";
            cout<<" ....Going to main Menu......\n";
    }goto m;
}
void shopping :: buyer()
{   
    m:
    int choice;
    cout<<"               ___________________                \n";
    cout<<"                                                  \n";
    cout<<"---------------- Welcome to Market ---------------\n";
    cout<<"We Care, We Cure\n";
    cout<<"               ___________________                \n";
    cout<<" 1) buy a product     \n\n";
    cout<<" 2) Go to back        \n\n";
    cout<<" Please Enter your choice...........\n";
    cin>>choice;
    switch(choice){
        case 1:
        {
            receipt();
            break;
        }
        case 2:
        {
             menu();
        }
        default:
            cout<<"Invalid chioce..............\n";
            
    }goto m;
}
void shopping :: add()
{
    m:
    fstream data;
    int c;
    int token=0;
    float p;
    float d;
    string n;
    cout<<" -----Add New Product---------------\n";
    cout<< "product code of Product \n"; 
    cin>>pcode;
    cout<<"\n   Name of the Product  \n";
    cin>>pname;
    cout<<"\n   Price of the Product  \n";
    cin>>price;
    cout<<" Discount on Product \n";
    cin>>dis;
    data.open("data.txt",ios::in);
    if(!data)
    {
        data.open("database.txt",ios::app|ios::out);
        data<<"Product Name:- "<<pname<<"\t"<<"Product code:- "<<pcode<<"\t"<<"Product Price:- "<<price<<"\t"<<"Product discount:- "<<dis<<"\n";
        data.close();
    }
    else
    {
        data>>c>>n>>p>>d;
        while(!data.eof())
        {
            if(c==pcode)
            {
                token++;
            }
        data>>c>>n>>p>>d;     
        }
        data.close();

    
    if (token==1)
    {
        goto m;
    }
    else
    {
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pname<<" "<<pcode<<"  "<<price<<"\n";
        data.close();
    }
    }
    cout<<"......Product Inserted Successfully.......\n";

}
void shopping :: edit()
{
    fstream data,data1;
    int pkey;
    int c;
    int token=0;
    float p;
    float d;
    string n;
    cout<<" Modify th Record.....\n";
    cout<< "enter the product code\n";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<" File Doesn't Exit";
    }
    else
    {
         data1.open("database.txt",ios::app|ios::out);
          data<<"Product Name:- "<<pname<<"\t"<<"Product code:- "<<pcode<<"\t"<<"Product Price:- "<<price<<"\t"<<"Product discount:- "<<dis<<"\n";
         while(!data.eof())
        {
            if(pkey==pcode)
            {
                cout<<"Product New Code";
                cin>>c;
                cout<<"\n   Name of the Product  \n";
                cin>>n;
                cout<<"\n   Price of the Product  \n";
                cin>>p;
                cout<<" Discount on Product \n";
                cin>>d;
                 data<<"Product Name:- "<<n<<"\t"<<"Product code:- "<<c<<"\t"<<"Product Price:- "<<p<<"\t"<<"Product discount:- "<<d<<"\n";
                cout<<"......Record Edited Successfully.......\n";
                token++;
            }
            else{    
                  data<<"Product Name:- "<<n<<"\t"<<"Product code:- "<<c<<"\t"<<"Product Price:- "<<p<<"\t"<<"Product discount:- "<<d<<"\n";
}
            }
                   data<<"Product Name:- "<<pname<<"\t"<<"Product code:- "<<pcode<<"\t"<<"Product Price:- "<<price<<"\t"<<"Product discount:- "<<dis<<"\n";

        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");
        if(token==0)
        {
            cout<<"......Record Not Found.........\n";
        }
    }
void shopping :: remove1()
{
    fstream data,data1;
    int pkey;
    int token=0;
    cout<<" .........Delete Product.......\n";
    cout<<" Product code\n";
    cin>>pkey;
    data.open("database.txt", ios::in);
    if(!data)
    {
        cout<<"File doesn't Exists\n";
    }
    else
    {
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
         if(pcode==pkey)
         {
             cout<<" Product Deleted Successfully..........";
             token++;
         }
       else 
        {
            data1<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        }
        }
        data>>pcode>>pname>>price>>dis;
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");
        if(token==0)
        {
            cout<<" Record cann't Found............";
        }   
    }
}
void shopping :: list()
{
    fstream data;
    data.open("database.txt", ios::in);
     cout<<"               ___________________                \n";
    cout<<"                                                  \n";
    cout<<"Prono\t\tName\t\tPrice\n";
    cout<<"               ___________________                \n";
    data>>pcode>>pname>>price>>dis;
    while(!data.eof())
    {
        cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
        data>>pcode>>pname>>price>>dis;
    }
  data.close();
}
void shopping :: receipt()
{
    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int c=0;
    float amount=0;
    float dis=0;
    float total=0;
    cout<<" ___________________RECEIPT _______________________________ ";
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\n Empty Database";
    }
    else
    {
        data.close();
        list();
        cout<<"\n______________________________________________________\n";
        cout<<"\n                                                      \n";
        cout<<"\n______________Please place the Order _________________\n";
        cout<<"\n                                                      \n";
        cout<<"\n______________________________________________________\n";
        do{
            m:
            cout<<"\n\n Enter YOur Product Code\n";
            cin>>arrc[c];
            cout<<"\n\n Enter the Product Quantity \n";
            cin>>arrq[c];
            for(int i=0;i<c;i++)
            {
                if(arrc[c]==arrc[i])
                {
                    cout<<".........Duplicate Product Code.......\n";
                    cout<<"......Please try again\n";
                }
                c++;
                cout<<"\n\n Do you want to buy another product? if yes then press y else n:-";
                cin>>choice;}
            }while(choice=='y');
    cout<<" ___________________RECEIPT _______________________________ ";
    cout<<"Product No\t\t Product Name\t\tProduct Quantity\t\t Product price \t\t Amount\t\tAmount with discount \n";
    for(int i=0;i<c;i++)
    {
        data.open("database.txt",ios :: in);
        data>>pcode>>pname>>price>>dis;
        while(! data.eof())
        {
            if(pcode==arrc[i])
            {
                amount=price*arrq[i];
                dis=amount-(amount*dis/100);
                total=total+dis;
                cout<<"\n "<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t\t"<<amount<<"\t\t"<<dis;
        
            }
            data>>pcode>>pname>>price>>dis;
        }
    }
    data.close();
}
    cout<<"\n\n---------------------------------\n";   
    cout<<"\n Total Amount :"<<total;
    }
     

int main() {
    shopping s1;
    s1.menu();
    return 0;
}