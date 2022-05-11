#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

enum copyAvail{IN_LIBRARY, AVAILABLE, LOANED};
enum menu{NEW_BOOK=1, SEARCH, LOAN, RETURN, QUIT};
struct book{
    string isbn;
    string title;
    string authors[5];
    string subjects[5];
    int edition;
    int year;
    int nbrCopies;
    copyAvail* availability;
};

const int MAX_NBR_BOOKS = 1000;

void getBookInfo(book &bkInfo);
void displayBookInfo(const book &bkInfo);
void readBookInfo(ifstream &recFile, book &bkInfo);
void writeBookInfo(ofstream &recFile, const book &bkInfo);
void printInstructions();
string tolower(string str);

int main()
{
    cout << "Welcome to your library!!" << endl;
    cout << "===============================================" << endl;

    map<string, book> library;

    ifstream recFileIn("records.txt");
    if(recFileIn.is_open())
    {
        while( recFileIn.peek() != EOF)
        {
            book bk;
            readBookInfo(recFileIn, bk);
            library[bk.isbn] = bk;
            //library.insert(pair(bk.isbn, bk));
        }
    }
    recFileIn.close();
    int menuSelection = NEW_BOOK;
    while(true)
    {
        printInstructions();
        cin >> menuSelection;
        string subject;
        string isbn;
        string dummy;
        bool bookAvail = false;
        bool bookFound = false;
        ofstream recFileOut;
        book bk;
        map<string, book>:: iterator it;
        switch(menuSelection)
        {
        case NEW_BOOK:
            getline(cin, dummy);
            getBookInfo(bk);
            library[bk.isbn] = bk;
            cout << "------------------- New book added. "<< endl;
            cout << "===============================================" << endl;
            break;
        case SEARCH:
            getline(cin, dummy);
            cout << "subject?  ";
            getline(cin, subject);
            subject=tolower(subject);

            it = library.begin();
            //for(it= library.begin(); it!=library.end(); it++)
            while(it != library.end())
            {
                for(int j = 0; j < 5; j++)
                {
                    //cout << subject << " vs " << library[i].subjects[j] << endl;
                    if (subject == (it->second).subjects[j])
                    {
                        displayBookInfo(it->second);
                        cout << "--------------------------------" << endl;
                    }
                }
                it++;
            }
            cout << "===============================================" << endl;
            break;
        case LOAN:
            getline(cin, dummy);
            cout << "ISBN? ";
            getline(cin, isbn);
            it = library.find(isbn);
            if(it != library.end())
            {
                bookAvail = false;
                for(int j = 0; j < it->second.nbrCopies; j++)
                {
                    if(it->second.availability[j] == AVAILABLE)
                    {
                        bookAvail = true;
                        it->second.availability[j] = LOANED;
                        cout << "----------------- " << it->second.title << " checked out." << endl;
                        break;
                    }
                }
                if(!bookAvail)
                {
                    cout << "------------------Book not available. " << endl;
                }
            }else
            {
                cout << "-----------------Title not found. " << endl;
            }
            cout << "===============================================" << endl;
            break;
        case RETURN:
            getline(cin, dummy);
            cout << "ISBN? ";
            getline(cin, isbn);
            it = library.find(isbn);
            if(it != library.end())
            {
                bookAvail = false;
                for(int j = 0; j < it->second.nbrCopies; j++)
                {
                    if(it->second.availability[j] == LOANED)
                    {
                        bookAvail = true;
                        it->second.availability[j] = AVAILABLE;
                        cout << "----------------- " << it->second.title << " returned." << endl;
                        break;
                    }
                }
                if(!bookAvail)
                {
                    cout << "------------------Cannot return book. " << endl;
                }
            }else
            {
                cout << "-------------------Title not found in records. " << endl;
            }
            cout << "===============================================" << endl;
            break;
        case QUIT:
            if(library.size() > 0)
            {
                recFileOut.open("Records.txt");
                for( it = library.begin(); it != library.end(); it++)
                {
                    writeBookInfo(recFileOut, it->second);
                }
                recFileOut.close();
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
    cout << LOAN << ": loan a book" << endl;
    cout << RETURN << ": return a book " << endl;
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
    cout << "Please list up to 5 subject headings. Leave subject heading blank if less than 5." << endl;
    for(int i = 0; i < 5; i++)
    {
        cout << "topic " << i+1 << ": ";
        getline(cin, bkInfo.subjects[i]);
        bkInfo.subjects[i] = tolower(bkInfo.subjects[i]);
    }
    cout << "Edition: ";
    cin >> bkInfo.edition;
    cout << "Year: ";
    cin >> bkInfo.year;
    cout << "Number of hard copies: ";
    cin >> bkInfo.nbrCopies;
    if(bkInfo.nbrCopies > 0)
        bkInfo.availability = new copyAvail[bkInfo.nbrCopies];
    cout << "Please list the availability status of each copy." << endl;
    cout << "type A if available." << endl;
    cout << "type L if loaned." << endl;
    cout << "type I in-library use only. (default status)" << endl;
    for(int i = 0; i < bkInfo.nbrCopies; i++)
    {
        cout << "copy " << i+1 << ": ";
        char status = 0;
        cin >> status;
        switch(status)
        {
            case 'A': bkInfo.availability[i] = AVAILABLE; break;
            case 'L': bkInfo.availability[i] = LOANED; break;
            default: bkInfo.availability[i] = IN_LIBRARY;
        }
    }
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
    cout << "Subjects: ";
    for(int i = 0 ;i < 5; i++)
    {
        if(bkInfo.subjects[i] != "")
            cout << bkInfo.subjects[i] << ", ";
    }
    cout << endl;
    cout << "Edition: " << bkInfo.edition << endl;
    cout << "Year: " << bkInfo.year << endl;
    cout << "Number of copies: " << bkInfo.nbrCopies << endl;
    for(int i = 0; i < bkInfo.nbrCopies; i++)
    {
        cout << "Copy " << i+1 << ": ";
        //cout << bkInfo.availability[i];
        switch(bkInfo.availability[i])
        {
            case AVAILABLE: cout << "available" << endl; break;
            case LOANED: cout << "loaned" << endl; break;
            default: cout << "in library use only" << endl; break;
        }
    }
}

void readBookInfo(ifstream &recFile, book &bkInfo)
{
    string line, temp;
    int pos1 = -1, pos2 = -1;
    //reading isbn
    getline(recFile, line);
    pos1 = line.find(':', 0);
    bkInfo.isbn = line.substr(pos1+2);
    //reading title
    getline(recFile, line);
    pos1 = line.find(':', 0);
    bkInfo.title = line.substr(pos1+2);
    //reading authors
    getline(recFile, line);
    pos1 = line.find(':', 0);
    pos2 = line.find(',', pos1);
    int i = 0;
    while(pos2 != string::npos)
    {
        bkInfo.authors[i] = line.substr(pos1+2, pos2-pos1-2);
        pos1 = pos2;
        pos2 = line.find(',', pos1+1);
        i++;
    }
    //reading subjects
    getline(recFile, line);
    pos1 = line.find(':', 0);
    pos2 = line.find(',', pos1);
    i = 0;
    while(pos2 != string::npos)
    {
        bkInfo.subjects[i] = line.substr(pos1+2, pos2-pos1-2);
        pos1 = pos2;
        pos2 = line.find(',', pos1+1);
        i++;
    }
    //reading edition
    getline(recFile, line);
    pos1 = line.find(':', 0);
    bkInfo.edition = stoi(line.substr(pos1+2));
    //reading year
    getline(recFile, line);
    pos1 = line.find(':', 0);
    bkInfo.year = stoi(line.substr(pos1+2));
    //reading nbr copies
    getline(recFile, line);
    pos1 = line.find(':', 0);
    bkInfo.nbrCopies = stoi(line.substr(pos1+2));
    //reading copies availability
    bkInfo.availability = new copyAvail[bkInfo.nbrCopies];
    for(int i = 0 ; i < bkInfo.nbrCopies; i++)
    {
        getline(recFile, line);
        pos1 = line.find(':', 0);
        temp = line.substr(pos1+2);
        if(temp == "available")
            bkInfo.availability[i] = AVAILABLE;
        else if(temp == "loaned")
            bkInfo.availability[i] = LOANED;
        else if(temp == "in library use only")
            bkInfo.availability[i] = IN_LIBRARY;
    }
    //reading separator
    getline(recFile, line);

    return;

}

void writeBookInfo(ofstream &recFile, const book &bkInfo)
{
    recFile << "ISBN: " << bkInfo.isbn << endl;
    recFile << "Title: " << bkInfo.title << endl;
    recFile << "Authors: ";
    for(int i = 0 ;i < 5; i++)
    {
        if(bkInfo.authors[i] != "")
            recFile << bkInfo.authors[i] << ", ";
    }
    recFile << endl;
    recFile << "Subjects: ";
    for(int i = 0 ;i < 5; i++)
    {
        if(bkInfo.subjects[i] != "")
            recFile << bkInfo.subjects[i] << ", ";
    }
    recFile << endl;
    recFile << "Edition: " << bkInfo.edition << endl;
    recFile << "Year: " << bkInfo.year << endl;
    recFile << "Number of copies: " << bkInfo.nbrCopies << endl;
    for(int i = 0; i < bkInfo.nbrCopies; i++)
    {
        recFile << "Copy " << i+1 << ": ";
        switch(bkInfo.availability[i])
        {
            case AVAILABLE: recFile << "available" << endl; break;
            case LOANED: recFile << "loaned" << endl; break;
            default: recFile << "in library use only" << endl; break;
        }
    }
    recFile << "==============================================" << endl;
    return;
}

string tolower(string str)
{
    for(auto &c : str)
    {
        c = tolower(c);
    }
    return str;
}
