//
// Created by Karla Angélica Peña Guerra on 3/27/22.
//
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

enum menu{NEW_BOOK=1, SEARCH, QUIT};
struct book{
    string isbn;
    string title;
    string authors[5];
    int edition;
    int year;
};

const int MAX_NBR_BOOKS = 1000;

int loadLibraryRecords(string filename, book lib[]);
void printInstructions();
void getBookInfo(book &bkInfo);
void displayBookInfo(const book &bkInfo);
void saveLibraryRecords(string filename, book lib[], int bookCount);

int main()
{
    cout << "Welcome to your library!!" << endl;
    cout << "===============================================" << endl;
    book library[MAX_NBR_BOOKS];
    int bookCount = loadLibraryRecords("records.txt", library);
    int menuSelection = NEW_BOOK;
    while(true)
    {
        printInstructions();
        cin >> menuSelection;
        string subject;
        string isbn;
        string dummy;
        switch(menuSelection)
        {
            case NEW_BOOK:
                if(bookCount < MAX_NBR_BOOKS)
                {
                    getline(cin, dummy);
                    getBookInfo(library[bookCount]);
                    bookCount++;
                    cout << "------------------- New book added. "<< endl;
                }else
                {
                    cout << "Cannot add a new book." << endl;
                }
                cout << "===============================================" << endl;
                break;
            case SEARCH:
                getline(cin, dummy);
                cout << "ISBN: ";
                getline(cin, isbn);
                for(int i = 0; i < bookCount; i++)
                {
                    if (isbn == library[i].isbn)
                    {
                        displayBookInfo(library[i]);
                        cout << "--------------------------------" << endl;
                    }
                }
                cout << "===============================================" << endl;
                break;
            case QUIT:
                if(bookCount >0)
                {
                    saveLibraryRecords("records.txt", library, bookCount);
                    cout << "-----------------Library records updated." << endl;
                }
                cout << "===============================================" << endl;
                cout << "bye bye." << endl;
                return 0;
            default:
                cout << "Selection not available." <<endl;
                cout << "===============================================" << endl;
        }
    }
}
void printInstructions()
{
    cout << "What would you like to do: "<< endl;
    cout << NEW_BOOK << ": enter a new book information" << endl;
    cout << SEARCH << ": search for book in a certain subject" << endl;
    cout << QUIT << ": quit" << endl;
    cout << "===============================================" << endl;
    cout << "? ";
}

void getBookInfo(book &bkInfo)
{
    cout << "ISBN: ";
    getline(cin, bkInfo.isbn);
    cout << "Title: ";
    getline(cin, bkInfo.title);
    cout << "Please list up to 5 author names. Leave author name blank if less than 5." << endl;
    for(int i = 0; i < 5; i++)
    {
        cout << "author " << i+1 << ": ";
        getline(cin, bkInfo.authors[i]);
    }
    cout << "Edition: ";
    cin >> bkInfo.edition;
    cout << "Year: ";
    cin >> bkInfo.year;
}

void displayBookInfo(const book &bkInfo)
{
    cout << "ISBN: " << bkInfo.isbn << endl;
    cout << "Title: " << bkInfo.title << endl;
    cout << "Authors: ";
    for(int i = 0 ;i < 5; i++)
    {
        if(bkInfo.authors[i] != "")
            cout << bkInfo.authors[i] << ", ";
    }
    cout << endl;

    cout << "Edition: " << bkInfo.edition << endl;
    cout << "Year: " << bkInfo.year << endl;
}

int loadLibraryRecords(string filename, book lib[]) {
    ifstream infile(filename);
    string word = "ISBN";
    string text;
    int count = 0;

    if (infile.fail()) {
        cout << "Input text file does not exist" << endl;
    } else {
        while (!infile.eof()) {
            getline(infile, text);
            if ((text.find(word) != string::npos)) {
                ++count;
            }
        }
        for (int i=0; i<count;i++){
            // getline function not workinf here because already opened before, havent had time to go over this
            for (int num_lines = 0; num_lines < 6 && getline(infile); ++num_lines) // each book has all its information in 6 lines
            {
                lib[i].isbn;
                lib[i].title;
                lib[i].authors;
                lib[i].edition;
                lib[i].year;
            }

        }
    }
    return count;
}

void saveLibraryRecords(string filename, book lib[], int bookCount) {
    ofstream recFile(filename);
    for (int i = 0; i < bookCount; i++) {
        recFile << "ISBN: " << lib[i].isbn << endl;
        recFile << "Title: " << lib[i].title << endl;
        recFile << "Authors: ";
        for (int j = 0; j < 5; j++) {
            if (lib[i].authors[j] != "")
                recFile << lib[i].authors[j] << ", ";
        }
        recFile << endl;
        recFile << "Edition: " << lib[i].edition << endl;
        recFile << "Year: " << lib[i].year << endl;
        recFile << "==============================================" << endl;
    }
    recFile.close();
}


