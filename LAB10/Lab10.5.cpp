#include <iostream>
#include <string>
#include <queue>
using namespace std;

class PrintJob {
public:
    string client;
    string document;
    int pages;

    PrintJob(string c, string d, int p) : client(c), document(d), pages(p) {}
};

class PrintShop {
private:
    queue<PrintJob> jobQueue;

public:
    void addJob(const PrintJob& job) {
        jobQueue.push(job);
        cout << "Added: " << job.document << " (" << job.pages << " pages)" << endl;
    }

    void processJobs() {
        while (!jobQueue.empty()) {
            PrintJob current = jobQueue.front();
            jobQueue.pop();
            
            cout << "\nPrinting: " << current.document << endl;
            cout << "Client: " << current.client << endl;
            cout << "Pages: " << current.pages << endl;
            
            for (int i = 0; i < current.pages; i++) {
                cout << ".";
            }
            
            cout << "\nFinished printing " << current.document << "\n" << endl;
        }
        
        cout << "All jobs completed. Printer is idle." << endl;
    }
};

int main() {
	cout << " The code is written by MESUM ABBAS CT-238" << endl;
    PrintShop shop;

    shop.addJob(PrintJob("Alice", "Report.pdf", 5));
    shop.addJob(PrintJob("Bob", "Presentation.pptx", 3));
    shop.addJob(PrintJob("Charlie", "Image.jpg", 1));
    shop.addJob(PrintJob("Diana", "Contract.doc", 4));

    shop.processJobs();

    return 0;
}
