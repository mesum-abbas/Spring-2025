#include <iostream>
#include <string>
using namespace std;

class Media {
protected:
    string title;
    bool isBorrowed;
    int borrowDays;

public:
    Media(string t) : title(t), isBorrowed(false), borrowDays(0) {}

    void borrowMedia() {
        if (!isBorrowed) {
            isBorrowed = true;
            cout << title << " has been borrowed." << endl;
        } else {
            cout << title << " is already borrowed." << endl;
        }
    }

    void returnMedia() {
        if (isBorrowed) {
            isBorrowed = false;
            cout << title << " has been returned." << endl;
        } else {
            cout << title << " was not borrowed." << endl;
        }
    }

    virtual void displayInfo() {
        cout << "Title: " << title << endl;
        cout << "Status: " << (isBorrowed ? "Borrowed" : "Available") << endl;
    }
};

class BookAttributes {
protected:
    string author;
    int pages;

public:
    BookAttributes(string a, int p) : author(a), pages(p) {}

    void displayBookAttributes() {
        cout << "Author: " << author << endl;
        cout << "Pages: " << pages << endl;
    }
};

class MagazineAttributes {
protected:
    int issueNumber;
    string publicationDate;

public:
    MagazineAttributes(int issue, string date) : issueNumber(issue), publicationDate(date) {}

    void displayMagazineAttributes() {
        cout << "Issue Number: " << issueNumber << endl;
        cout << "Publication Date: " << publicationDate << endl;
    }
};

class DVDAttributes {
protected:
    string director;
    int duration; 

public:
    DVDAttributes(string dir, int dur) : director(dir), duration(dur) {}

    void displayDVDAttributes() {
        cout << "Director: " << director << endl;
        cout << "Duration: " << duration << " minutes" << endl;
    }
};

class Book : public Media, public BookAttributes {
public:
    Book(string t, string a, int p) 
        : Media(t), BookAttributes(a, p) {}

    void displayInfo() {
        Media::displayInfo();
        BookAttributes::displayBookAttributes();
    }
};

class Magazine : public Media, public MagazineAttributes {
public:
    Magazine(string t, int issue, string date) 
        : Media(t), MagazineAttributes(issue, date) {}

    void displayInfo() {
        Media::displayInfo();
        MagazineAttributes::displayMagazineAttributes();
    }
};

class DVD : public Media, public DVDAttributes {
public:
    DVD(string t, string dir, int dur) 
        : Media(t), DVDAttributes(dir, dur) {}

    void displayInfo() {
        Media::displayInfo();
        DVDAttributes::displayDVDAttributes();
    }
};

int main() {
	cout << "The code is written by MESUM ABBAS CT-238 " << endl;
    Book book("The Great Gatsby", "F. Scott Fitzgerald", 180);
    Magazine magazine("National Geographic", 256, "May 2023");
    DVD dvd("Inception", "Christopher Nolan", 148);

    cout << "=== Library Media Management ===" << endl;
    
    cout << "\nBook Information:" << endl;
    book.displayInfo();
    book.borrowMedia();
    book.borrowMedia(); 
    book.returnMedia();

    cout << "\nMagazine Information:" << endl;
    magazine.displayInfo();
    magazine.borrowMedia();
    magazine.returnMedia();

    cout << "\nDVD Information:" << endl;
    dvd.displayInfo();
    dvd.borrowMedia();
    dvd.returnMedia();

    return 0;
}
