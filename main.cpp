#include<iostream>
#include<fstream>
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
        void rem();
        void list();
        void receipt();

};

void shopping :: menu()
{
    m:
    int choice;
    string email;
    string password;

    cout<<"\t_______________________________________________\n";
    cout<<"\t                                               \n";
    cout<<"\t             Supermarket Main Menu             \n";
    cout<<"\t                                               \n";
    cout<<"\t_______________________________________________\n";
    cout<<"\t                                               \n";
    cout<<"\t          |  1)Administrator    |\n";
    cout<<"\t          |                     |\n";
    cout<<"\t          |  2)Buyer            |\n";
    cout<<"\t          |                     |\n";
    cout<<"\t          |  3)Exit             |\n";
    cout<<"\t          |                     |\n";
    cout<<"\t          Please select! :";

    cin>>choice;
    switch( choice )
    {
        case 1:
            system("cls");
            cout<<"\t\t\t Please Login  \n";
            cout<<"\t\t Enter Email : ";
            cin>>email;
            cout<<"\n\t\t Enter Password : ";
            cin>>password;
            if( email=="rohit@mail.com" && password=="mohit@123")
            {
                administrator();
            }
            else   
            {
                system("cls");
                cout<<"\t\t\tInvalid email/password\n";
                break;
            }      
        case 2:
            buyer();
        case 3:
            exit(0);
        default:
            cout<<"Please Select from the given option\n";
    }
    goto m;
}

void shopping::administrator()
{
    m: 
    int choice;
    cout<<"\n\n\n\t\t\t Administrator Menu";
    cout<<"\n\t\t\t|_____1) Add the product______|\n";
      cout<<"\t\t\t|                             |\n";
    cout<<"\n\t\t\t|_____2) Modify the product___|\n";
      cout<<"\t\t\t|                             |\n";
    cout<<"\n\t\t\t|_____3) Delete the product___|\n";
      cout<<"\t\t\t|                             |\n";
    cout<<"\n\t\t\t|_____4) Back to Main menu____|\n";
      cout<<"\t\t\tPlease enter your choice      \n";
    cin>>choice;

    switch( choice )
    {
        case 1:
            add();
            break;
        case 2:
            edit();
            break;
        case 3:
            rem();
            break;
        case 4:
            menu();
            break;
        default:
            cout<<"Invalid choice!";
    }
    goto m;
}

void shopping::buyer()
{
    m:
    int choice;
    cout<<"\t\t\t  Buyer  \n";
    cout<<"\t\t\t_________\n";
    cout<<"               \n";
    cout<<"\t\t\t1) Buy product \n";
    cout<<"                \n";
    cout<<"\t\t\t2) Go back\n";
    cout<<"\t\t\t  Enter your choice : \n";
    cin>>choice;

    switch (choice)
    {
        case 1:
            receipt();
            break;
        case 2:
            menu();
        default:
            cout<<"Invalid choice";
            break;
    }
    goto m;
}
void shopping::add()
{
    m:
    fstream data;
    int c;
    int token=0;
    float p;
    float d;
    string n;

    cout<<"\n\n\t\t\t Add new product";
    cout<<"\n Enter product code of the product : ";
    cin>>pcode;
    cout<<"\n Enter name of the product : ";
    cin>>pname;
    cout<<"\n Enter price of the product : ";
    cin>>price;
    cout<<"\n Enter discount on product : ";
    cin>>dis;

    data.open("database.txt",ios::in);

    if(!data)
    {
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
    else
    {
        data>>c>>n>>p>>d;
        while( !data.eof() )
        {
            if( pcode == c )
                token++;
            data>>c>>n>>p>>d;
        }
        data.close();
        //check if an item is already inserted with same code;
        if( token == 1)
            goto m;
        else{
            //item is not inserted earlier  
            //insert it;
            data.open("database.txt",ios::app|ios::out);
            data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            data.close();
        }
    }

    cout<<"\n\n\t\t Record inserted!";
    
}
void shopping::edit()
{
    fstream data,data1;
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;

    cout<<"\n\t\t\t Edit/Modify product/record";
    cout<<"\n\t\t__________________________________________";
    cout<<"\n\t\t\t Enter Product code: ";
    cin>>pkey;

    data.open("database.txt",ios::in);
    if( !data )
    {
        cout<<"\n\n\t File doesn't exist";
        cout<<"\n\t Administrator has not added any products";
    }
    else
    {
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if( pkey == pcode )
            {
                cout<<"\n\t\t Enter new Product code: ";
                cin>>c;
                cout<<"\n\t\t Enter name of the Product: ";
                cin>>n;
                cout<<"\n\t\t Enter price: ";
                cin>>p;
                cout<<"\n\t\t Enter Discount: ";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\n\t\t Record edited";
                token++;
            }
            else
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis;
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");

        if( token == 0 )
            cout<<"\n\tRecord not found sorry!";  
    }
}
void shopping::rem() 
{
    fstream data,data1;
    int pkey;
    int token=0;

    cout<<"\n\t\t\t Delete Product";
    cout<<"\n\t\t_______________________________";
    cout<<"\n\t\t\t Enter Product code: ";
    cin>>pkey;

    data.open("database.txt",ios::in);
    if( !data )
    {
        cout<<"\n\n\t File doesn't exist";
        cout<<"\n\t Administrator has not added any products";
    }
    else
    {
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if( pkey == pcode )
            {
                cout<<"\n\n\t Product deleted succesfully";
                token++;
            }
            else
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis;
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");

        if( token == 0 )
            cout<<"\n\tRecord not found sorry!";  
    }

}
void shopping::list(){
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\n|_______________________________________________________________|";
    cout<<"\n Prod.No.\t\tName\t\tprice";
    cout<<"\n\n|_______________________________________________________________|";
    data>>pcode>>pname>>price>>dis;

    while( !data.eof() ){
        cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
        data>>pcode>>pname>>price>>dis;
    }
    data.close();
}
void shopping::receipt(){
    fstream data;

    int arrc[100];
    int arrq[100];
    char choice;
    int c=0;
    float amount = 0;
    float dis = 0;
    float total = 0;

    cout<<"\n\n\t\t\t Receipt";
    data.open("database.txt",ios::in);
    if( !data )
    {
        cout<<"\n\nEmpty database";
        data.close();
    }
    else{
        data.close();

        list();
        cout<<"\n____________________________________________";
        cout<<"\n|                                          |";
        cout<<"\n|          please place the order          | ";
        cout<<"\n|                                          |";
        cout<<"\n____________________________________________";

        do
        {
            m:
            cout<<"\n\nEnter Product code:";
            cin>>arrc[c];
            cout<<"\nEnter Product quantity:";
            cin>>arrq[c];

            for(int i=0; i<c; i++){
                if( arrc[c] == arrc[i] )
                {
                    cout<<"\n\nDuplicate product code. Please try again!";
                    goto m;
                }
            }
            c++;
            cout<<"\nDo you want to buy another product? Press y for yes, n for No:";
            cin>>choice;
        }
        while( choice == 'y' );

        cout<<"\n\n\t\t\t_____________________________RECEIPT__________________________________";
        cout<<"\nProduct No.\t Product Name\t Product Quantity\tPrice\tAmount\nAmount with discount";


        for(int i=0; i<c; i++)
        {
            data.open("database.txt,ios::in");
            data>>pcode>>pname>>price>>dis;
            while( data.eof() )
            {
                if( pcode == arrc[i] )
                {
                    amount = price * arrq[i];
                    dis = amount - (amount*dis/100);
                    total += dis;
                    cout<<"\n"<<pcode<<"\t"<<pname<<"\t"<<arrq[i]<<"\t"<<price<<"\t"<<amount<<"\t"<<dis;
                }
                data>>pcode>>pname>>price>>dis;
            }
        }
        data.close();
    }
    cout<<"\n\n_______________________________________________________";
    cout<<"\n Total Amount:"<<total;
}
int main()
{
    shopping s;
    s.menu();
}
    
