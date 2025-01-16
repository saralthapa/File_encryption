#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FileManager {
public:
    void createFile(const string& fileName) {
        ofstream outFile(fileName);
        if (!outFile) {
            cerr << "Error: Unable to create file: " << fileName << endl;
            return;
        }

        cout << "Enter the content to write to the file (type `EOF` to finish): " << endl;
        cin.ignore(); // Clear any leftover newline in the buffer

        string line;
        while (getline(cin, line)) {
            if (line == "EOF") break;
            outFile << line << endl;
        }
        outFile.close(); // Ensures file stream is closed after writing
        cout << "File created successfully: " << fileName << endl;
    }

    void updateFile(const string& fileName) {
        ofstream outFile(fileName, ios::app); // Open file in append mode
        if (!outFile) {
            cerr << "Error: Unable to open file: " << fileName << endl;
            return;
        }

        cout << "Enter the content to append to the file (type `EOF` to finish): " << endl;
        cin.ignore(); // Clear any leftover newline in the buffer

        string line;
        while (getline(cin, line)) {
            if (line == "EOF") break;
            outFile << line << endl;
        }
        outFile.close(); // Ensures file stream is closed after writing
        cout << "Content appended successfully to file: " << fileName << endl;
    }
};

class FileCrypt {
public:
    void encryptFile(const string& inputFileName, const string& outputFileName, int key) {
        ifstream inputFile(inputFileName, ios::binary);
        ofstream outputFile(outputFileName, ios::binary);

        if (!inputFile || !outputFile) {
            cerr << "Error: Unable to open input or output file." << endl;
            return;
        }

        char ch;
        while (inputFile.get(ch)) {
            outputFile.put(ch ^ key); // XOR encryption
        }

        inputFile.close();
        outputFile.close();
        cout << "Encryption complete. Encrypted file: " << outputFileName << endl;
    }

    void decryptFile(const string& inputFileName, const string& outputFileName, int key) {
        ifstream inputFile(inputFileName, ios::binary);
        ofstream outputFile(outputFileName, ios::binary);

        if (!inputFile || !outputFile) {
            cerr << "Error: Unable to open input or output file." << endl;
            return;
        }

        char ch;
        while (inputFile.get(ch)) {
            outputFile.put(ch ^ key); // XOR decryption
        }

        inputFile.close();
        outputFile.close();
        cout << "Decryption complete. Decrypted file: " << outputFileName << endl;
    }
};

int main() {
    FileManager fileManager;
    FileCrypt fileCrypt;

    int choice;
    do {
        cout << "\nFile Manager and Crypt Program\n";
        cout << "1. Create a File\n";
        cout << "2. Update an Existing File\n";
        cout << "3. Encrypt a File\n";
        cout << "4. Decrypt a File\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        string fileName, outputFileName;
        int key;

        switch (choice) {
            case 1:
                cout << "Enter the name of the file to create: ";
                cin >> fileName;
                fileManager.createFile(fileName);
                break;

            case 2:
                cout << "Enter the name of the file to update: ";
                cin >> fileName;
                fileManager.updateFile(fileName);
                break;

            case 3:
                cout << "Enter the name of the file to encrypt: ";
                cin >> fileName;
                cout << "Enter the name of the output encrypted file: ";
                cin >> outputFileName;
                cout << "Enter the encryption key (integer): ";
                cin >> key;
                fileCrypt.encryptFile(fileName, outputFileName, key);
                break;

            case 4:
                cout << "Enter the name of the file to decrypt: ";
                cin >> fileName;
                cout << "Enter the name of the output decrypted file: ";
                cin >> outputFileName;
                cout << "Enter the decryption key (integer): ";
                cin >> key;
                fileCrypt.decryptFile(fileName, outputFileName, key);
                break;

            case 5:
                cout << "Exiting the program." << endl;
                break;

            default:
                cerr << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
