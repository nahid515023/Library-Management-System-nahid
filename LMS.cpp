            //---------------------------------***********************--------------------------------------||
            //                                  NAME: MD NAHID HASAN                                        ||
            //                                    ID: B190305020                                            ||
            //--------------------------------************************--------------------------------------||

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

using namespace std;

class lib
{
public:
    string book_id, book_name, book_auth;
    string student_id, student_name;
    string record_issue, return_date;
    void get();
    void student();
    void librarian();
    void add();
    void booklist();
    void search();
    void modify();
    void Delete();
    void issue_book();
    void getstudent();
    void view_issue();
};

void lib ::get()
{
    int i;
    cout << "\n\t*********** LIBRARY MANAGEMENT SYSTEM ***********\n";
    cout << "\n\t\tPlease Choose Any Option To login: \n";
    cout << "\n\t\t1.Student\n\n\t\t2.Librarian\n\n\t\t3.Close Application\n";
    cout << "\n\t\tEnter your choice : ";
    cin >> i;
    if (i == 1)
    {
        student();
    }
    else if (i == 2)
    {
        librarian();
    }
    else if (i == 3)
    {
        exit(0);
    }
    else
    {
        // Please enter correct option.
        system("CLS");
        get();
    }
}
void lib ::student()
{
    system("cls");
    int i;
    cout << "\n\t************ WELCOME STUDENT ************\n";
    cout << "\n\t\t>>Please Choose One Option:\n";
    cout << "\n\t\t1.View BookList\n\n\t\t2.Search for a Book\n\n\t\t3.Go to main menu\n\n\t\t4.Close Application\n";
    cout << "\n\t\tEnter your choice : ";
    cin >> i;
    if (i == 1)
        booklist();
    else if (i == 2)
        search();
    else if (i == 3)
    {
        system("cls");
        get();
    }
    else if (i == 4)
        exit(0);
}
void lib ::librarian()
{
    int i;
    cout << "\n\t************ WELCOME LIBRARIAN ************\n";
    cout << "\n\t\t>>Please Choose One Option:\n";
    cout << "\n\t\t1.View BookList\n\n\t\t2.Issue Book\n\n\t\t3.Views Issue Book's\n\n\t\t4.Add Book\n\n\t\t5.Search for a Book\n\n\t\t6.Delete for a Book\n\n\t\t7.Modify Book\n\n\t\t8.Go to main menu\n\n\t\t9.Close Application\n";
    cout << "\n\t\tEnter your choice : ";
    cin >> i;
    if (i == 1)
    {
        booklist();
    }
    else if (i == 2)
    {
        issue_book();
    }
    else if (i == 3)
    {
        view_issue();
    }
    else if (i == 4)
    {
        add();
    }
    else if (i == 5)
    {
        search();
    }
    else if (i == 6)
    {
        Delete();
    }
    else if (i == 7)
    {
        modify();
    }
    else if (i == 8)
    {
        get();
    }
    else if (i == 9)
    {
        exit(0);
    }
    else
    {
        system("cls");
        librarian();
    }
}
void lib ::booklist()
{
    system("cls");
    ifstream fbin("Books.txt", ios::binary);
    fbin.seekg(0);
    if (!fbin)
    {
        cout << "\n\t\tFile Not Found.";
    }
    else
    {
        cout << "\n\t    ************ Book List ************ \n\n";
        cout << "\n\t\tBook Id\t\tBook Name\t\tBook Auth\n";
        while (fbin.read((char *)this, sizeof(*this)))
        {
            cout << "\t\t" << book_id << "\t\t" << book_name << "\t\t\t" << book_auth << endl;
        }
        fbin.close();
    }
    cout << "\n\t\t1.Back Student\n\n\t\t2.Back Librarian\n\n\t\t3.Close Application\n";
    cout << "\n\t\tPlease Choose One Option:";
    int i;
    cin >> i;
    if (i == 1)
    {
        student();
    }
    else if (i == 2)
    {
        librarian();
    }
    else if (i == 3)
    {
        exit(0);
    }
}
void lib ::add()
{
    system("cls");
    cout << "\n\t************ ADD NEW BOOK ************\n";
    cout << "\n\t\tEnter Book's ID : ";
    cin >> book_id;
    cout << "\n\t\tEnter Book's Name : ";
    cin >> book_name;
    cout << "\n\t\tEnter Author's Name : ";
    cin >> book_auth;
    ofstream fbout("Books.txt", ios::binary | ios::out | ios::app);
    if (!fbout)
    {
        cout << "\t\t\tError in opening file.\n";
    }
    else
    {
        fbout.write((char *)this, sizeof(*this));
        fbout.close();
        cout << "\n\t\tThe book has been successfully add.\n";
    }
    cout << "\n\t\t1.Add More Book\n\n\t\t2.Back Student\n\n\t\t3.Back Librarian\n\n\t\t4.Close Application\n";
    cout << "\n\t\tPlease Choose One Option:";
    int i;
    cin >> i;
    if (i == 2)
    {
        student();
    }
    else if (i == 3)
    {
        librarian();
    }
    else if (i == 4)
    {
        exit(0);
    }
    else if (i == 1)
    {
        add();
    }
}
void lib ::search()
{
    system("cls");
    int sc, c = 0;
    cout << "\n\t\tPlease Choose one option :-\n";
    cout << "\n\t\t1.Search By Name\n\n\t\t2.Search By Book's ID\n";
    cout << "\n\t\tEnter Your Choice : ";
    cin >> sc;
    ifstream fbin("Books.txt", ios::binary);
    fbin.seekg(0);
    if (!fbin)
    {
        cout << "\n\t\tFile Not Found.";
    }
    else
    {

        if (sc == 1)
        {
            string name;
            cout << "\n\t\tEnter Book Name: ";
            cin >> name;
            while (fbin.read((char *)this, sizeof(*this)))
            {
                if (name == book_name)
                {
                    cout << "\n\t    ************ Book List ************ \n\n";
                    cout << "\n\t\tBook Id\t\tBook Name\t\tBook Auth\n";
                    cout << "\t\t" << book_id << "\t\t" << book_name << "\t\t\t" << book_auth << endl;
                    c = 1;
                }
            }
            fbin.close();
        }
        else if (sc == 2)
        {
            string id;
            cout << "\n\t\tEnter Book Id: ";
            cin >> id;
            while (fbin.read((char *)this, sizeof(*this)))
            {
                if (id == book_id)
                {
                    cout << "\n\t\t    ************ Book List ************ \n\n";
                    cout << "\n\t\tBook Id\t\tBook Name\t\tBook Auth\n";
                    cout << "\t\t" << book_id << "\t\t" << book_name << "\t\t\t" << book_auth << endl;
                    c = 1;
                }
            }
            fbin.close();
        }
        if (c != 1)
        {
            cout << "\n\t\t    ************ Book List ************ \n\n";
            cout << "\n\t\tBook Id\t\tBook Name\t\tBook Auth\n";
            cout << "\n\t\tBook's not found!\n\n";
        }
    }
    cout << "\n\t\t1.Back Student\n\n\t\t2.Back Librarian\n\n\t\t3.Close Application\n";
    cout << "\n\t\tPlease Choose One Option:";
    int i;
    cin >> i;
    if (i == 1)
    {
        student();
    }
    else if (i == 2)
    {
        librarian();
    }
    else if (i == 3)
    {
        exit(0);
    }
}
void lib ::modify()
{
    system("cls");
    int sc;
    cout << "\n\t\tPlease Choose one option :-\n";
    cout << "\n\t\t1.Search By Name\n\n\t\t2.Search By Book's ID\n";
    cout << "\n\t\tEnter Your Choice : ";
    cin >> sc;
    fstream fbin("Books.txt", ios::binary | ios::out | ios::in);
    fbin.seekg(0);
    if (!fbin)
    {
        cout << "\n\t\tFile Not Found.";
    }
    else
    {

        if (sc == 1)
        {
            string name;
            cout << "\n\t\tEnter Book Name: ";
            cin >> name;
            while (fbin.read((char *)this, sizeof(*this)))
            {
                if (name == book_name)
                {
                    cout << "\n\t    ************ Book List ************ \n\n";
                    cout << "\n\t\tBook Id\t\tBook Name\t\tBook Auth\n";
                    cout << "\t\t" << book_id << "\t\t" << book_name << "\t\t\t" << book_auth << endl;
                    cout << "\t\t---------------------------------------------------------------------\t\t";
                    cout << "\n\t************ MODIFY BOOK ************\n";
                    cout << "\n\t\tEnter Book's ID : ";
                    cin >> book_id;
                    cout << "\n\t\tEnter Book's Name : ";
                    cin >> book_name;
                    cout << "\n\t\tEnter Author's Name : ";
                    cin >> book_auth;
                    fbin.seekp(-sizeof(*this), ios::cur);
                    fbin.write((char *)this, sizeof(*this));
                    fbin.close();
                    cout << "\n\t\tThe book has been successfully modify.\n";
                }
            }
            fbin.close();
        }
        else if (sc == 2)
        {
            string id;
            cout << "\n\t\tEnter Book Id: ";
            cin >> id;
            while (fbin.read((char *)this, sizeof(*this)))
            {
                if (id == book_id)
                {
                    cout << "\n\t    ************ Book List ************ \n\n";
                    cout << "\n\t\tBook Id\t\tBook Name\t\tBook Auth\n";
                    cout << "\t\t" << book_id << "\t\t" << book_name << "\t\t\t" << book_auth << endl;
                    cout << "\t\t---------------------------------------------------------------------\t\t";
                    cout << "\n\t************ MODIFY BOOK ************\n";
                    cout << "\n\t\tEnter Book's ID : ";
                    cin >> book_id;
                    cout << "\n\t\tEnter Book's Name : ";
                    cin >> book_name;
                    cout << "\n\t\tEnter Author's Name : ";
                    cin >> book_auth;
                    fbin.seekp(-sizeof(*this), ios::cur);
                    fbin.write((char *)this, sizeof(*this));
                    fbin.close();
                    cout << "\n\t\tThe book has been successfully modify.\n";
                }
            }
            fbin.close();
        }
        else
        {
            cout << "\n\t\tBook's not found!";
        }
    }
    cout << "\n\t\t1.Back Student\n\n\t\t2.Back Librarian\n\n\t\t3.Close Application\n";
    cout << "\n\t\tPlease Choose One Option:";
    int i;
    cin >> i;
    if (i == 1)
    {
        student();
    }
    else if (i == 2)
    {
        librarian();
    }
    else if (i == 3)
    {
        exit(0);
    }
}
void lib ::Delete()
{
    system("cls");
    int sc;
    cout << "\n\t\tPlease Choose one option :-\n";
    cout << "\n\t\t1.Delete By Name\n\n\t\t2.Delete By Book's ID\n";
    cout << "\n\t\tEnter Your Choice : ";
    cin >> sc;
    fstream fbin("Books.txt", ios::binary | ios::out | ios::in);
    ofstream fbout("temp.txt", ios::binary);
    fbin.seekg(0);
    if (!fbin || !fbout)
    {
        cout << "\n\t\tFile Not Found.\n";
    }
    else
    {

        if (sc == 1)
        {
            string name;
            cout << "\n\t\tEnter Delete Book Name: ";
            cin >> name;
            while (fbin.read((char *)this, sizeof(*this)))
            {
                if (name != book_name)
                {
                    fbout.write((char *)this, sizeof(*this));
                }
            }
            fbout.close();
            fbin.close();
            cout << "\n\t\tThe book has been successfully delete.\n";
            remove("Books.txt");
            rename("temp.txt", "Books.txt");
        }
        else if (sc == 2)
        {
            string id;
            cout << "\n\t\tEnter Delete Book Id: ";
            cin >> id;
            while (fbin.read((char *)this, sizeof(*this)))
            {
                if (id != book_id)
                {
                    fbout.write((char *)this, sizeof(*this));
                }
            }
            fbout.close();
            fbin.close();
            cout << "\n\t\tThe book has been successfully delete.\n";
            remove("Books.txt");
            rename("temp.txt", "Books.txt");
        }
        else
        {
            cout << "\n\t\tBook's not found!\n";
        }
    }
    cout << "\n\t\t1.Back Student\n\n\t\t2.Back Librarian\n\n\t\t3.Close Application\n";
    cout << "\n\t\tPlease Choose One Option:";
    int i;
    cin >> i;
    if (i == 1)
    {
        student();
    }
    else if (i == 2)
    {
        librarian();
    }
    else if (i == 3)
    {
        exit(0);
    }
}
void lib ::issue_book()
{
    int count = 0;
    system("cls");
    ofstream fbout("issue_book.txt", ios::binary | ios::out | ios::app);
    if (!fbout)
    {
        cout << "\t\t\tError in opening file.\n";
    }
    else
    {
        cout << "\n\t************ Books Issue ************\n";
        cout << "\n\t\tEnter Student's ID : ";
        cin >> student_id;
        cout << "\n\t\tEnter Student's Name : ";
        cin >> student_name;
        cout << "\n\t\tEnter Books's ID : ";
        cin >> book_id;
        cout << "\n\t\tEnter Book's Name : ";
        cin >> book_name;
        cout << "\n\t\tEnter Book's Issue Date : ";
        cin >> record_issue;
        cout << "\n\t\tEnter Book's Return Date : ";
        cin >> return_date;
        fbout.write((char *)this, sizeof(*this));
        fbout.close();
        cout << "\n\t\tThe book has been successfully add.\n";
    }

    cout << "\n\t\t1.Issue Book\n\n\t\t2.Back Student\n\n\t\t3.Back Librarian\n\n\t\t4.Close Application\n";
    cout << "\n\t\tPlease Choose One Option :";
    int i;
    cin >> i;
    if (i == 2)
    {
        student();
    }
    else if (i == 3)
    {
        librarian();
    }
    else if (i == 4)
    {
        exit(0);
    }
    else if (i == 1)
    {
        issue_book();
    }
}
void lib ::getstudent()
{
    system("cls");
    cout << "\n\t************ Create Student Record ************\n";
    cout << "\n\t\tEnter Student's ID : ";
    cin >> student_id;
    cout << "\n\t\tEnter Student's Name : ";
    cin >> student_name;
    ofstream fbout("student_info.txt", ios::binary | ios::out | ios::app);
    if (!fbout)
    {
        cout << "\t\t\tError in opening file.\n";
    }
    else
    {
        fbout.write((char *)this, sizeof(*this));
        fbout.close();
        cout << "\n\t\tThe student has been successfully add.\n";
    }
    cout << "\n\t\t1.Create More Student Id \n\n\t\t2.Back Student\n\n\t\t3.Back Librarian\n\n\t\t4.Close Application\n";
    cout << "\n\t\tPlease Choose One Option:";
    int i;
    cin >> i;
    if (i == 2)
    {
        student();
    }
    else if (i == 3)
    {
        librarian();
    }
    else if (i == 4)
    {
        exit(0);
    }
    else if (i == 1)
    {
        add();
    }
}
void lib ::view_issue()
{
    system("cls");
    ifstream fbin("issue_book.txt", ios::binary);
    fbin.seekg(0);
    if (!fbin)
    {
        cout << "\n\t\tFile Not Found.";
    }
    else
    {
        cout << "\n\t    ************ Issue Book List ************ \n\n";
        cout << "\n\t\tStudent Id\t\tStudent Name\t\tBook Id\t\tBook Name\t\tRecord Issue Date\t\tBook Returen Date\n";
        while (fbin.read((char *)this, sizeof(*this)))
        {
            cout << "\t\t\t" << student_id << "\t\t" << student_name << "\t\t\t" << book_id << "\t\t" << book_name << "\t\t\t" << record_issue << "\t\t\t" << return_date << endl;
        }
        fbin.close();
    }
    cout << "\n\t\t1.Back Student\n\n\t\t2.Back Librarian\n\n\t\t3.Close Application\n";
    cout << "\n\t\tPlease Choose One Option:";
    int i;
    cin >> i;
    if (i == 1)
    {
        student();
    }
    else if (i == 2)
    {
        librarian();
    }
    else if (i == 3)
    {
        exit(0);
    }
}
int main()
{
    lib obj;
    //obj.view_issue();
    //obj.issue_book();
    obj.get();
    //obj.getstudent();
    //obj.add();
    //obj.booklist();
    //obj.search();
    //obj.modify();
    //obj.Delete();
    getch();
    return 0;
}