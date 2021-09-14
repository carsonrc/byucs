#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Document.h
class Document{
private:
    string name;
    string extension;
    string contents;
public:
    Document(string nameIn, string extensionIn, string contentsIn);
    string GetName();
    void Rename(string newDocumentName);
    string GetExtension();
    string GetContents();
    void Print();

};

//Document.cpp
Document::Document(string nameIn, string extensionIn, string contentsIn){
    name = nameIn;
    extension = extensionIn;
    contents = contentsIn;
}
string Document::GetName(){
    return name;
}
void Document::Rename(string newDocumentName){
    name = newDocumentName;
}
string Document::GetExtension(){
    return extension;
}
string Document::GetContents(){
    return contents;
}
void Document::Print(){
    cout << "Name: " << name << "." << extension << endl;
    cout << "Contents: " << contents << endl;
}

//main.cpp----------
void DisplayMenu(){
    cout << "Choose an option below: "<< endl;
    cout << "1. Add a document to your list"<< endl;
    cout << "2. Rename one of your documents"<< endl;
    cout << "3. Share one of your documents with your friend"<< endl;
    cout << "4. Display all of the documents"<< endl;
    cout << "5. Quit"<< endl << endl;
}
void AddDocument(vector<Document*>& documentList) {
    string documentNewName;
    string documentNewExtension;
    string documentNewContent;

    cin.ignore();
    cout << "Enter the document name:" << endl;
    getline(cin, documentNewName);

    cout << "Enter the document extension:" << endl;
    getline(cin, documentNewExtension);

    cout << "Enter the document content:" << endl;
    getline(cin, documentNewContent);


    auto docPtr = new Document(documentNewName, documentNewExtension, documentNewContent);
    documentList.push_back(docPtr);
}
void RenameDocument(vector<Document*>& documentList) {
    int userIndex;
    string newName;

    cout << "Enter the index of your document you want to rename:" << endl;
    cin >> userIndex;
    cin.ignore();
    cout << "Enter the updated name of the document:" << endl;
    getline(cin, newName);

    documentList.at(userIndex)->Rename(newName);

}
void ShareDocument(vector<Document*> &documentList, vector<Document*> &sharedDocuments) {
    int index;
    Document* docPtr;

    cout << "Enter the index of your document you want to share: " << endl;
    cin >> index;
    docPtr = documentList.at(index);
    sharedDocuments.push_back(docPtr);

}
void DisplayDocuments(vector<Document*> &documentList, vector<Document*> &friendList) {
    cout << "-------------------Your List------------------" << endl;
    for (int i = 0; i < documentList.size(); i++) {
        cout << "Name: " << documentList.at(i)->GetName() << documentList.at(i)->GetExtension() << endl;
        cout << "Contents: " << documentList.at(i)->GetContents() << endl;
    }
    cout << "--------------Your Friend's List--------------" << endl;
    for (int i = 0; i < friendList.size(); i++) {
        cout << "Name: " << friendList.at(i)->GetName() << friendList.at(i)->GetExtension() << endl;
        cout << "Contents: " << friendList.at(i)->GetContents() << endl;
    }
    cout << "----------------------------------------------" << endl;
}
// Modify the main function to handle each menu option
// Consider creating a new function (above main) per menu option
int main(){
    const int ADD_DOCUMENT_OPTION = 1;
    const int RENAME_DOCUMENT_OPTION = 2;
    const int SHARE_YOUR_DOCUMENT_OPTION = 3;
    const int DISPLAY_ALL_DOCUMENTS_OPTION = 4;
    const int QUIT_OPTION = 5;

    vector<Document*> myDocuments;
    vector<Document*> sharedDocuments;

    int option;
    DisplayMenu();
    cin >> option;

    while(option != QUIT_OPTION){

        if(option == ADD_DOCUMENT_OPTION){
            AddDocument(myDocuments);
        }
        else if(option == RENAME_DOCUMENT_OPTION){
            RenameDocument(myDocuments);
        }
        else if(option == SHARE_YOUR_DOCUMENT_OPTION){
            ShareDocument(myDocuments,sharedDocuments);
        }
        else if(option == DISPLAY_ALL_DOCUMENTS_OPTION){
            DisplayDocuments(myDocuments,sharedDocuments);
        }

        cout << endl << "Enter option: " << endl;
        cin >> option;

    }
    for (int i = 0; i < myDocuments.size(); i++) {
        delete myDocuments.at(i);
    }
    myDocuments.clear();
    sharedDocuments.clear();


    return 0;
}
