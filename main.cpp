//Header FILE:
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

class Products
{
private:
    int ID;
    int quant;
    int price;
    string selection;
    string desc;
    
public:
    Products(int i = 0, int q = 0, int p = 0, string s = "", string d = "");
    void setPID(int);
    void setPQuantity(int);
    void setPPrice(int);
    void setPDescription(string);
    void setPSelection(string);
    int getPID();
    int getPQuantity();
    int getPPrice();
    string getPDescription();
    string getPSelection();
};

class VendingMachine
{
protected:
    string selection_ven;
    int quarter;
    int nickel;
    int dime;
    int ID;
    int quant;
    int numItems;
    
public:
    Products Products[10];
    VendingMachine(int q = 0, int d = 0, int n = 0);
    int getQuarter();
    int getDime();
    int getNickel();
    int getQuantity();
    int getVID();
    int getnumItems();
    string getVSelection();
    void setQuarter(int);
    void setnumItems(int);
    void setDime(int);
    void setNickel(int);
    void setVQuantity(int);
    void setVID(int);
    void setVSelection(string);
    int readMoneyInA();
    int readMoneyInB();
    
};

class Machine100A : public VendingMachine
{
private:
    int dollar;
    
public:
    
};

class Machine100B : public VendingMachine
{
private:
    int dollar;
    
public:
    
};

class Machine100C : public VendingMachine
{
private:
    string card;
    
public:
    //Products products[10];
    int total = 0;
    Machine100C(string c = "0000000000000");
    string returnCard();
    void printInfo();
    void lastFour(string card);
    bool purchase(string card, int quantity);
    bool checkCard(string card);
    void print(string card);
};




//FUNCTION FILE:

using namespace std;

const int MAX_PRODUCTS = 30;

void readProducts(ifstream &indata, Products products[])
{
    int total = 0;
    int ID, quant, price;
    string desc;
    while (!indata.eof())
    {
        indata >> ID >> quant >> price;
        getline(indata, desc);
        products[total].setPID(ID);
        products[total].setPQuantity(quant);
        products[total].setPPrice(price);
        products[total].setPDescription(desc);
        total++;
    }
    
}
void readProductC(ifstream &indata, Products products[])
{
    int total = 0;
    int ID, quant, price;
    string desc;
    while (!indata.eof())
    {
        indata >> ID >> quant >> price;
        getline(indata, desc);
        products[total].setPID(ID);
        products[total].setPQuantity(quant);
        products[total].setPPrice(price);
        products[total].setPDescription(desc);
        total++;
    }
    
}

//vending machine superclass functions
VendingMachine::VendingMachine(int q, int d, int n)
{
    quarter = q;
    dime = d;
    nickel = n;
}

int VendingMachine::getQuarter()
{
    return quarter;
}
int VendingMachine::getNickel()
{
    return nickel;
}
int VendingMachine::getQuantity()
{
    return quant;
}
int VendingMachine::getVID()
{
    return ID;
}
int VendingMachine::getnumItems()
{
    return numItems;
}
string VendingMachine::getVSelection()
{
    return selection_ven;
}
int VendingMachine::getDime()
{
    return dime;
}
void VendingMachine::setQuarter(int q)
{
    quarter = q;
}
void VendingMachine::setnumItems(int i)
{
    numItems = i;
}
void VendingMachine::setDime(int d)
{
    dime = d;
}
void VendingMachine::setNickel(int n)
{
    nickel = n;
}
void VendingMachine::setVQuantity(int a)
{
    quant = a;
}
void VendingMachine::setVID(int b)
{
    ID = b;
}
void VendingMachine::setVSelection(string x)
{
    selection_ven = x;
}

int VendingMachine::readMoneyInA()
{
    double total = 0;
    int moneyVal;
    
    cout << "Please insert money --> ";
    cin >> moneyVal;
    
    if (moneyVal == 0)
    {
        return total;
        //aka start over, need to fix this
    }
    
    if (moneyVal != 100)
    {
        ;
    }
    else
    {
        total += moneyVal;
    }
    
    
    while (moneyVal != 0)
    {
        cin >> moneyVal;
        
        if (moneyVal != 100)
        {
            ;
        }
        else
        {
            total += moneyVal;
        }
        
    }
    cin.ignore();
    
    cout << "You entered an amount of " << total << " cents." << endl;
    cout << "Processing your purchase. . . " << endl;
    
    return total;
}

int VendingMachine::readMoneyInB()
{
    double total = 0;
    int moneyVal;
//    int paymentChoice;
//    bool repeat = false;
    
//    do
//    {
//        cout << "Select an option (1 - dollar bill and 2 - coins) --> ";
//        cin >> paymentChoice;
//
//        if (paymentChoice == 1)
//        {
//
//        }
//        else if (paymentChoice == 2)
//        {
//
//        }
//        else
//        {
//            //error
//            repeat = true;
//        }
//    }
//    while (repeat);

    
    cout << "Please insert either dollar bills or coins --> ";
    cin >> moneyVal;
    
    if (moneyVal == 0)
    {
        return total;
        //aka start over, need to fix this
    }
    
    if (moneyVal % 5 != 0)
    {
        ;
    }
    else
    {
        total += moneyVal;
    }
//    if (moneyVal == 100)
//    {
//        cout << "Error: Not accepting dollar bills!" << endl;
//        total = -1;
//        return total;
//    }
    
    while (moneyVal != 0)
    {
        cin >> moneyVal;
        
        if (moneyVal % 5 != 0)
        {
            ;
        }
        else
        {
            total += moneyVal;
        }
        
    }
    //cin.ignore();
    
    cout << "You entered an amount of " << total << " cents." << endl;
    cout << "Processing your purchase. . . " << endl;
    
    return total;
}

//Product class functions
Products::Products(int i, int q, int p, string s, string d)
{
    ID = i;
    quant = q;
    price = p;
    selection = s;
    desc = d;
}
void Products::setPID(int i)
{
    ID = i;
}
void Products::setPQuantity(int q)
{
    quant = q;
}
void Products::setPPrice(int p)
{
    price = p;
}
void Products::setPDescription(string d)
{
    desc = d;
}
void Products::setPSelection(string s)
{
    selection = s;
}
int Products::getPID()
{
    return ID;
}
int Products::getPQuantity()
{
    return quant;
}
int Products::getPPrice()
{
    return price;
}
string Products::getPDescription()
{
    return desc;
}

string Products::getPSelection()
{
    return selection;
}

//machine C class functions
Machine100C::Machine100C(string c)
{
    c = card;
}



//void Machine100C::lastFour(string card)
//{
//    //get last 4 digits for output report
//    //wrong
//    string temp = "    ";
//
//    if (checkCard(card))
//    {
//        for (int i = card.length() - 4; i <= card.length(); i++)
//        {
//            temp = card[i];
//            cout << temp;
//        }
//    }
//    else
//    {
//
//    }
//}

bool Machine100C::purchase(string card, int quantity)
{
    bool repeat = true;
    cout << fixed << setprecision(2);
    int i = 0;
    while (repeat)
    {
        cout << "Enter your credit card number --> ";
        cin >> card;
        i++;
        if (checkCard(card))
        {
            cout << "You credit card was successfully charged for $" << (Products[total].getPPrice() * quantity) / 100.00 << endl;
            // need to get price from the machine and change to dollars;
            
            cout << "Thank you! Please take your item." << endl;
            repeat = false;
            return true;

            break;
        }
        else if (i == 1)
        {
            cout << "Invalid credit card number was entered." << endl;
        }
        //Two invalid attempts will cancel item
        else if (i == 2)
        {
            cout << "Too many invalid attempts! Your selection has been canceled." << endl;
            repeat = false;
            return false;
        }
    }
    return false;
}

bool Machine100C::checkCard(string card)
{
    int num = card.length();
    
    bool isSecond = false;
    
    if (card.length() <= 16 && card.length() >= 13)
    {
        if (card[0] == '4' || card[0] == '5' || card[0] == '6')
        {
            int sum = 0;
            
            for (int i = num - 1; i >= 0; i--)
            {
                int x = card[i] - '0';
                
                if (isSecond == true)
                    x *= 2;
                
                sum += x / 10;
                sum += x % 10;
                isSecond = !isSecond;
            }
            isSecond = (sum % 10 == 0) ? true : false;
            return isSecond;
        }
        else if (card[0] == '3' && card[1] == '7')
        {
            int sum = 0, isSecond = false;
            
            for (int i = num - 1; i >= 0; i--)
            {
                int x = card[i] - '0';
                
                if (isSecond == true)
                    x *= 2;
                
                sum += x / 10;
                sum += x % 10;
                isSecond = !isSecond;
            }
            isSecond = (sum % 10 == 0) ? true : false;
            return isSecond;
        }
        else
            return isSecond;
    }
    else
    {
        return isSecond;
    }
}

void Machine100C::print(string card)
{
    if (checkCard(card))
    {
        cout << "You credit card was successfully charged for $" << endl;
        cout << "Thank you! Please take your item.\n";
    }
    else
    {
        cout << "Invalid credit card number was entered.\n";
    }
}
//Machine100C::Machine100C(string c)
//{
//    card = c;
//}
//
//string Machine100C::returnCard()
//{
//    return card;
//}
/*void Products::subProductAmount(int x)
 {
 if (x <= quant)
 {
 quant -= x;
 }
 }
 */

void readmachineA(ifstream &indata, Machine100A machineA[], Products products[])
{
    int total = 0;
    int quarter, dime, nickel;
    int ID, quant, numofmachines, numofitems;
    string model, selection;
    indata >> model >> numofmachines;
    while (!indata.eof())
    {
        indata >> quarter >> dime >> nickel >> numofitems;
        machineA[total].setQuarter(quarter);
        machineA[total].setDime(dime);
        machineA[total].setNickel(nickel);
        machineA[total].setnumItems(numofitems);
        int temp = numofmachines;
        for (int i = 0; i < numofitems; i++)
        {
            indata >> selection >> ID >> quant;
            for (int k = 0; k < MAX_PRODUCTS; k++)
            {
                if (ID == products[k].getPID())
                {
                    machineA[total].Products[i].setPID(ID);
                    machineA[total].Products[i].setPSelection(selection);
                    machineA[total].Products[i].setPQuantity(quant);
                    products[k].setPQuantity(products[k].getPQuantity() - quant);
                    machineA[total].Products[i].setPPrice(products[k].getPPrice());
                    machineA[total].Products[i].setPDescription(products[k].getPDescription());
                }
            }
        }
        total++;
    }
}

void readmachineB(ifstream &indata, Machine100B machineB[], Products products[])
{
    int total = 0;
    int quarter, dime, nickel;
    int ID, quant, numofmachines, numofitems;
    string model, selection;
    indata >> model >> numofmachines;
    while (!indata.eof())
    {
        indata >> quarter >> dime >> nickel >> numofitems;
        machineB[total].setQuarter(quarter);
        machineB[total].setDime(dime);
        machineB[total].setNickel(nickel);
        machineB[total].setnumItems(numofitems);
        int temp = numofmachines;
        for (int i = 0; i < numofitems; i++)
        {
            indata >> selection >> ID >> quant;
            for (int k = 0; k < MAX_PRODUCTS; k++)
            {
                if (ID == products[k].getPID())
                {
                    machineB[total].Products[i].setPID(ID);
                    machineB[total].Products[i].setPSelection(selection);
                    machineB[total].Products[i].setPQuantity(quant);
                    products[k].setPQuantity(products[k].getPQuantity() - quant);
                    machineB[total].Products[i].setPPrice(products[k].getPPrice());
                    machineB[total].Products[i].setPDescription(products[k].getPDescription());
                }
            }
        }
        total++;
    }
}

void readmachineC(ifstream &indata, Machine100C machineC[], Products products[])
{
    int total = 0;
    int quarter, dime, nickel;
    int ID, quant, numofmachines, numofitems;
    string model, selection;
    indata >> model >> numofmachines;
    while (!indata.eof())
    {
        indata >> quarter >> dime >> nickel >> numofitems;
        machineC[total].setQuarter(quarter);
        machineC[total].setDime(dime);
        machineC[total].setNickel(nickel);
        machineC[total].setnumItems(numofitems);
        int temp = numofmachines;
        for (int i = 0; i < numofitems; i++)
        {
            indata >> selection >> ID >> quant;
            for (int k = 0; k < MAX_PRODUCTS; k++)
            {
                if (ID == products[k].getPID())
                {
                    machineC[total].Products[i].setPID(ID);
                    machineC[total].Products[i].setPSelection(selection);
                    machineC[total].Products[i].setPQuantity(quant);
                    products[k].setPQuantity(products[k].getPQuantity() - quant);
                    machineC[total].Products[i].setPPrice(products[k].getPPrice());
                    machineC[total].Products[i].setPDescription(products[k].getPDescription());
                }
            }
        }
        total++;
    }
}



// MAIN FILE

using namespace std;

//const int MAX_PRODUCTS = 30;
const int MAX_MACHINES = 30;
void readProducts(ifstream&, Products[]);
void readmachineA(ifstream &indata, Machine100A machineA[], Products products[]);
void readmachineB(ifstream &indata, Machine100B machineB[], Products products[]);
void readmachineC(ifstream &indata, Machine100C machineC[], Products products[]);
void readProductC(ifstream&, Products[]);

//void machineChange(Machine100A[], int, int, int);
void makeChangeA (Machine100A[], int, int, int);
void makeChangeB (Machine100B[], int, int, int);

//int machineSize(T machine[], int n)
//{
//    int count = 0;
//    for (int i = 0; i < MAX_PRODUCTS; i++)
//    {
//        if (machine[n].Products[i].getPID() == 0)
//        {
//            count = i;
//            break;
//        }
//    }
//    return count;
//}

int main()
{
    ifstream machine_fileA;
    ifstream machine_fileB;
    ifstream machine_fileC;
    ifstream products_file;
    
    ofstream result;
    string startCode;
    string machineCode;
    string model;
    
    Machine100A machineA[MAX_MACHINES];
    Machine100B machineB[MAX_MACHINES];
    Products products[MAX_PRODUCTS];
    Products productC[MAX_PRODUCTS];
    
    // Machine C stuff
    Machine100C machineC[MAX_MACHINES];
    string cardNum;
    string machine;
    string item;
    Machine100C call;
    machine_fileA.open("/Users/faizaan/Downloads/testMachineA.txt");
    machine_fileB.open("/Users/faizaan/Downloads/testMachineB.txt");
    machine_fileC.open("/Users/faizaan/Downloads/testMachineC.txt");
    
    products_file.open("/Users/faizaan/Downloads/products.txt");
    result.open("/Users/faizaan/Downloads/results.txt");
    
    if (!machine_fileA)
    {
        cout << "Machines.txt not found." << endl;
        system("Pause");
        return 1;
    }
    
    if (!machine_fileB)
    {
        cout << "Machines.txt not found." << endl;
        system("Pause");
        return 1;
    }
    
    if (!machine_fileC)
    {
        cout << "Machines.txt not found." << endl;
        system("Pause");
        return 1;
    }
    
    if (!products_file)
    {
        cout << "products.txt not found." << endl;
        system("Pause");
        return 1;
    }
    
    int total = 0;
    
    cout << "Please enter a startup code --> ";
    cin >> startCode;
    
    while (startCode != "spring19")
    {
        cout << "Machine not found. " << endl;
        cout << "Please enter another startup code --> ";
        cin >> startCode;
    }
    
    readProducts(products_file, products);
    readProductC(products_file, productC);
    readmachineA(machine_fileA, machineA, products);
    readmachineB(machine_fileB, machineB, products);
    readmachineC(machine_fileC, machineC, products);
    
    cout << "Initializing machines. Please wait. . ." << endl;
    cout << "Machines are ready." << endl;
    cout << "Available machines: 100A1, 100A2, 100B1, 100C1, 100C2" << endl << endl;
    cout << "Select a machine --> ";
    cin >> machineCode;
    
    char machineModel = machineCode[3];
    int machineNumber = (machineCode[4] - '0') - 1;
    
    while (machineCode != "spring19")
    {
        int quantity = 0;
        if (machineModel == 'A')
        {
            string input;
            int moneyIn;
            
            cout << "This machine accepts one-dollar bill only." << endl;
            cout << "Available items: " << endl;
            for (int i = 0; i < machineA[machineNumber].getnumItems(); i++)
            {
                if (machineA[machineNumber].Products[i].getPQuantity() != 0)
                {
                    cout << setw(5) << machineA[machineNumber].Products[i].getPSelection() << " " << machineA[machineNumber].Products[i].getPPrice() << machineA[machineNumber].Products[i].getPDescription() << endl;
                }
            }
            cout << "Select an item --> ";
            cin >> item;
            
            cout << "Please enter the quantity you want of that product --> ";
            cin >> quantity;
            
            if (quantity <= 0)
            {
                cout << "Error: Invalid quantity chosen!" << endl;
                break;
            }
            
            for (int i = 0; i < machineA[machineNumber].getnumItems(); i++)
            {
                if (machineA[machineNumber].Products[i].getPSelection() == item && machineA[machineNumber].Products[i].getPQuantity() >= quantity)
                {
                    cout << "You selected : " << machineA[machineNumber].Products[i].getPDescription() << endl;
                    cout << "You selected a quantity of: " << quantity << endl;
                    cout << "The total cost of the item(s) is " << machineA[machineNumber].Products[i].getPPrice() * quantity << " cents" << endl;

                    moneyIn = machineA[machineNumber].readMoneyInA();
                    
                    if (moneyIn == 0)
                    {
                        cout << "You chose to cancel your selection." << endl;
                        break;
                    }
                    
                    makeChangeA(machineA, machineA[machineNumber].Products[i].getPPrice() * quantity, moneyIn, machineNumber);
                    
                    machineA[machineNumber].Products[i].setPQuantity(machineA[machineNumber].Products[i].getPQuantity() - quantity);

                }
                else if (machineA[machineNumber].Products[i].getPSelection() == item && machineA[machineNumber].Products[i].getPQuantity() < quantity)
                {
                    cout << "Error: Selected quantity not available, please try again or check another machine!" << endl;
                }
            }
        }
        if (machineModel == 'B')
        {
            string input;
            int moneyIn;
            int paymentChoice;
            
            cout << "This machine accepts coins and one-dollar bills." << endl;
            cout << "Available items: " << endl;
            for (int i = 0; i < machineB[machineNumber].getnumItems(); i++)
            {
                if (machineB[machineNumber].Products[i].getPQuantity() != 0)
                {
                    cout << setw(5) << machineB[machineNumber].Products[i].getPSelection() << " " << machineB[machineNumber].Products[i].getPPrice() << machineB[machineNumber].Products[i].getPDescription() << endl;
                }
            }
            cout << "Select an item --> ";
            cin >> item;
            
            cout << "Please enter the quantity you want of that product --> ";
            cin >> quantity;
            
            if (quantity <= 0)
            {
                cout << "Error: Invalid quantity chosen!" << endl;
                break;
            }
            
            for (int i = 0; i < machineB[machineNumber].getnumItems(); i++)
            {
                if (machineB[machineNumber].Products[i].getPSelection() == item && machineB[machineNumber].Products[i].getPQuantity() >= quantity)
                {
                    cout << "You selected : " << machineB[machineNumber].Products[i].getPDescription() << endl;
                    cout << "You selected a quantity of: " << quantity << endl;
                    cout << "The total cost of the item(s) is " << machineB[machineNumber].Products[i].getPPrice() * quantity << " cents" << endl;
                    
//                    cout << "Select an option (1 - dollar bill and 2 - cents) --> ";
//                    cin >> paymentChoice;
                    //cin.ignore();
                    
//                    if (paymentChoice == 1)
//                    {
//                        moneyIn = machineB[machineNumber].readMoneyInA();
//                    }
//                    else if (paymentChoice == 2)
//                    {
//                        moneyIn = machineB[machineNumber].readMoneyInB();
//                    }
//                    else
//                    {
//                        cout << "Error: Invalid value entered for payment choice!" << endl;
//                        break;
//                    }
                    
                    moneyIn = machineB[machineNumber].readMoneyInB();

                    
                    if (moneyIn == 0)
                    {
                        cout << "You chose to cancel your selection." << endl;
                        break;
                    }
//                    else if (moneyIn == -1)
//                    {
//                        //cout << "Please try again!" << endl;
//                        break;
//                    }
                    
                    
                    makeChangeB(machineB, machineB[machineNumber].Products[i].getPPrice() * quantity, moneyIn, machineNumber);
                    
                    machineB[machineNumber].Products[i].setPQuantity(machineB[machineNumber].Products[i].getPQuantity() - quantity);
                    
                }
                else if (machineB[machineNumber].Products[i].getPSelection() == item && machineB[machineNumber].Products[i].getPQuantity() < quantity)
                {
                    cout << "Error: Selected quantity not available, please try again or check another machine!" << endl;
                }
            }
        }
        if (machineModel == 'C')
        {
            string input;
            //int price;
            //int sentinel;
            //int moneyIn;
            
            cout << "This machine accepts credit card only. (first one)" << endl;
            cout << "Available items: " << endl;
            for (int i = 0; i < machineC[machineNumber].getnumItems(); i++)
            {
                if (machineC[machineNumber].Products[i].getPQuantity() != 0)
                {
                    cout << setw(5) << machineC[machineNumber].Products[i].getPSelection() << " " << machineC[machineNumber].Products[i].getPPrice() << machineC[machineNumber].Products[i].getPDescription() << endl;
                }
            }
            cout << "Select an item --> ";
            cin >> item;
            
            cout << "Please enter the quantity you want of that product --> ";
            cin >> quantity;
            
            if (quantity <= 0)
            {
                cout << "Error: Invalid quantity chosen!" << endl;
                break;
            }
            
            for (int i = 0; i < machineC[machineNumber].getnumItems(); i++)
            {
                if (machineC[machineNumber].Products[i].getPSelection() == item && machineC[machineNumber].Products[i].getPQuantity() >= quantity)
                {
                    cout << "You selected : " << machineC[machineNumber].Products[i].getPDescription() << endl;
                    cout << "You selected a quantity of: " << quantity << endl;
                    cout << "The total cost of the item(s) is " << machineC[machineNumber].Products[i].getPPrice() * quantity << " cents" << endl;
                    
                    machineC[machineNumber].total = i;
                    //need to add quantity into credit card function
                    if (machineC[machineNumber].purchase(cardNum, quantity))
                    {
                        //subtracts quantity when card is valid and charged
                        machineC[machineNumber].Products[i].setPQuantity(machineC[machineNumber].Products[i].getPQuantity() - quantity);
                    }
                }
                else if (machineC[machineNumber].Products[i].getPSelection() == item && machineC[machineNumber].Products[i].getPQuantity() < quantity)
                {
                    cout << "Error: Selected quantity not available, please try again or check another machine!" << endl;
                }
            }
        }
        
        cout << endl;
        cout << "Select a machine --> ";
        cin >> machineCode;
        machineModel = machineCode[3];
        machineNumber = (machineCode[4] - '0') - 1;
    }
    cout << "Report is generating ...\n";
    cout << "System is shutting down.\n";
    
    system("Pause");
    return 0;
}

//void machineChange(Machine100A machine[], int n, int price, int change)
//{
//    int quarter = machine[0].getQuarter();
//    int dime = machine[0].getDime();
//    int nickel = machine[0].getNickel();
//    int changeQuarter = 0;
//    int changeDime = 0;
//    int changeNickel = 0;
//
//    while (n != 0)
//    {
//
//        if (quarter > 0 && n >= 25)
//        {
//            changeQuarter++;
//            quarter--;
//            machine[0].setQuarter(quarter);
//            n = n - 25;
//        }
//        else if (dime > 0 && n >= 10)
//        {
//            changeDime++;
//            dime--;
//            machine[0].setDime(dime);
//            n = n - 10;
//        }
//        else if (nickel > 0 && n >= 5)
//        {
//            changeNickel++;
//            nickel--;
//            machine[0].setNickel(nickel);
//            n = n - 5;
//        }
//        else if (changeQuarter == 0 || changeDime == 3 || changeNickel == 3)
//        {
//            cout << "insufficient changes! " << endl;
//            cout << "your transaction cannot be processed " << endl;
//            cout << "please take back your dollar bill." << endl;
//            machine[0].setQuarter(changeQuarter + quarter);
//            machine[0].setDime(changeDime + dime);
//            machine[0].setNickel(nickel + changeNickel);
//
//            n = 0;
//        }
//    }
//
//    cout << "Your change of " << change << " is given by " << endl;
//    cout << setw(4) << "Quarter(s) : " << changeQuarter << endl;
//    cout << setw(4) << "Dime(s) : " << changeDime << endl;
//    cout << setw(4) << "Nickel(s) : " << changeNickel << endl;
//
//}

void makeChangeA (Machine100A machine[], int price, int moneyIn, int machineNum)
{
    double change = moneyIn - price;
    double changeTrack = change;
    bool validPurchase = true;
    int quarters = machine[machineNum].getQuarter();
    int dimes = machine[machineNum].getDime();
    int nickels = machine[machineNum].getNickel();
    int changeQ = 0;
    int changeD = 0;
    int changeN = 0;
    int totalMachineChange = (quarters * 25) + (dimes * 10) + (nickels * 5);
    
    cout << fixed << setprecision(2);
    
    if (moneyIn == 0)
    {
        cout << "Item selection cancelled!" << endl;
        validPurchase = false;
    }
    else if (moneyIn % 5 != 0)
    {
        cout << "Error invalid value entered!" << endl;
        validPurchase = false;
    }
    else if (moneyIn < 0)
    {
        cout << "Error invalid value entered!" << endl;
        validPurchase = false;
    }
    else if (moneyIn < price)
    {
        cout << "Sorry insufficient funds!" << endl;
        validPurchase = false;
    }
    else
    {
        validPurchase = true;
    }
    
    if (change > totalMachineChange)
    {
        cout << "Insufficient funds to give back, take back money." << endl;
        validPurchase = false;
        //give back money to customer
    }
    
    if (validPurchase)
    {
        if (change >= 25 && quarters > 0)
        {
//            cout << "evaluates true" << endl;
//            changeQ = change / 25;
//            //quarters = quarters - changeQ;
//            machine[0].setQuarter(quarters - changeQ);
//            change = change - (changeQ * 25);
//
            changeQ = change / 25;
            if (changeQ > quarters)
            {
                changeQ = quarters;
            }
            //quarters -= changeQ;
            machine[machineNum].setQuarter(quarters - changeQ);
            change = change - (changeQ * 25);
        }
        

        if (change >= 10 && dimes > 0)
        {
//            changeD = change / 10;
//            //dimes = dimes - changeD;
//            machine[0].setDime(dimes - changeD);
//            change = change - (changeD * 10);
            
            changeD = change / 10;
            if (changeD > dimes)
            {
                changeD = dimes;
            }
            //dimes -= changeD;
            machine[machineNum].setDime(dimes - changeD);
            change = change - (changeD * 10);
        }
        

        if (change >= 5 && nickels > 0)
        {
//            changeN = change / 5;
//            //nickels = nickels - changeN;
//            machine[0].setNickel(nickels - changeN);
//            change = change - (changeN * 5);
            
            changeN = change / 5;
            if (changeN > nickels)
            {
                changeN = nickels;
            }
            //nickels -= changeN;
            machine[machineNum].setNickel(nickels - changeN);
            change = change - (changeN * 5);
        }
        
        
    
        cout << "Your change of " << changeTrack / 100 << " is given by " << endl;
        cout << setw(4) << "Quarter(s) : " << changeQ << endl;
        cout << setw(4) << "Dime(s) : " << changeD << endl;
        cout << setw(4) << "Nickel(s) : " << changeN << endl;
        cout << "Thank you! Please take your item." << endl;
    }
    
}

void makeChangeB (Machine100B machine[], int price, int moneyIn, int machineNum)
{
    double change = moneyIn - price;
    double changeTrack = change;
    bool validPurchase = true;
    int quarters = machine[machineNum].getQuarter();
    int dimes = machine[machineNum].getDime();
    int nickels = machine[machineNum].getNickel();
    int changeQ = 0;
    int changeD = 0;
    int changeN = 0;
    int totalMachineChange = (quarters * 25) + (dimes * 10) + (nickels * 5);
    
    cout << fixed << setprecision(2);
    
    if (moneyIn == 0)
    {
        cout << "Item selection cancelled!" << endl;
        validPurchase = false;
    }
    else if (moneyIn % 5 != 0)
    {
        cout << "Error invalid value entered!" << endl;
        validPurchase = false;
    }
    else if (moneyIn < 0)
    {
        cout << "Error invalid value entered!" << endl;
        validPurchase = false;
    }
    else if (moneyIn < price)
    {
        cout << "Sorry insufficient funds!" << endl;
        validPurchase = false;
    }
    else
    {
        validPurchase = true;
    }
    
    if (change > totalMachineChange)
    {
        cout << "Insufficient funds to give back, take back money." << endl;
        validPurchase = false;
        //give back money to customer
    }
    
    if (validPurchase)
    {
        if (change >= 25 && quarters > 0)
        {
            //            cout << "evaluates true" << endl;
            //            changeQ = change / 25;
            //            //quarters = quarters - changeQ;
            //            machine[0].setQuarter(quarters - changeQ);
            //            change = change - (changeQ * 25);
            //
            changeQ = change / 25;
            if (changeQ > quarters)
            {
                changeQ = quarters;
            }
            //quarters -= changeQ;
            machine[machineNum].setQuarter(quarters - changeQ);
            change = change - (changeQ * 25);
        }
        
        
        if (change >= 10 && dimes > 0)
        {
            //            changeD = change / 10;
            //            //dimes = dimes - changeD;
            //            machine[0].setDime(dimes - changeD);
            //            change = change - (changeD * 10);
            
            changeD = change / 10;
            if (changeD > dimes)
            {
                changeD = dimes;
            }
            //dimes -= changeD;
            machine[machineNum].setDime(dimes - changeD);
            change = change - (changeD * 10);
        }
        
        
        if (change >= 5 && nickels > 0)
        {
            //            changeN = change / 5;
            //            //nickels = nickels - changeN;
            //            machine[0].setNickel(nickels - changeN);
            //            change = change - (changeN * 5);
            
            changeN = change / 5;
            if (changeN > nickels)
            {
                changeN = nickels;
            }
            //nickels -= changeN;
            machine[machineNum].setNickel(nickels - changeN);
            change = change - (changeN * 5);
        }
        
        
        
        cout << "Your change of " << changeTrack / 100 << " is given by " << endl;
        cout << setw(4) << "Quarter(s) : " << changeQ << endl;
        cout << setw(4) << "Dime(s) : " << changeD << endl;
        cout << setw(4) << "Nickel(s) : " << changeN << endl;
        cout << "Thank you! Please take your item." << endl;
    }
    
}


//if (machineModel == 'F')
//{
//    int i = 19;
//    int numofitems = 3;
//    string input;
//
//    //call.printInfo();
//
//    for (int k = 0; k < numofitems; k++)
//    {
//        cout << setw(5) << machineA[0].Products[k].getPSelection() << " " << products[i].getPPrice() << products[i].getPDescription() << endl;
//        i++;
//        }
//        int num = 0;
//        cout << "Select an item --> ";
//        cin >> item;
//        if (item == machineA[0].Products[0].getPSelection())
//        {
//
//            cout << "You selected " << products[19].getPDescription() << endl;
//            cout << "The cost of this item is " << products[19].getPPrice() << " cents\n";
//        }
//        else if (item == machineA[0].Products[1].getPSelection())
//        {
//            cout << "You selected " << products[20].getPDescription() << endl;
//            cout << "The cost of this item is " << products[20].getPPrice() << " cents\n";
//        }
//        else if (item == machineA[0].Products[2].getPSelection())
//        {
//            cout << "You selected " << products[21].getPDescription() << endl;
//            cout << "The cost of this item is " << products[21].getPPrice() << " cents\n";
//
//        }
//        call.purchase(cardNum);
//        call.checkCard(cardNum);
//        //call.lastFour(cardNum);
//        //call.print(cardNum);
//
//
//        }
