#include <iostream>
#include <string>
#include <cstring>
using namespace std;

// Function to encrypt the plaintext
string encrypt(string pt) {
    // Arrays to store the mapping between letters and their binary representations
    string key[26] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S",
                      "T", "U", "V", "W", "X", "Y", "Z"};
    string value[26] = {"aaaaa", "aaaab", "aaaba", "aaabb", "aabaa", "aabab", "aabba", "aabbb", "abaaa", "abaab",
                        "ababa", "ababb", "abbaa",
                        "abbab", "abbba", "abbbb", "baaaa", "baaab", "baaba", "baabb", "babaa", "babab", "babba",
                        "babbb", "bbaaa", "bbaab"};

    int i, j;
    string encpt1 ="";
    // Loop through each character of the plaintext
    for (i=0;i<pt.length();i++){
        // Check if the character is an alphabet
        if(isalpha(pt[i])){
            // Loop through the key array to find the corresponding binary representation
            for (j=0;j<26;j++){
                if(pt.substr(i,1)==key[j]){
                    // Concatenate the binary representation to the encrypted text
                    encpt1 =encpt1+value[j]+" ";
                }
            }
        }
        else{
            encpt1+=pt[i];
        }

    }
    return encpt1;
}

// Function to decrypt the encrypted text
string decrypt(string encpt) {
    // Arrays to store the mapping between binary representations and letters
    string key[26] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S",
                      "T", "U", "V", "W", "X", "Y", "Z"};
    string value[26] = {"aaaaa", "aaaab", "aaaba", "aaabb", "aabaa", "aabab", "aabba", "aabbb", "abaaa", "abaab",
                        "ababa", "ababb", "abbaa",
                        "abbab", "abbba", "abbbb", "baaaa", "baaab", "baaba", "baabb", "babaa", "babab", "babba",
                        "babbb", "bbaaa", "bbaab"};

    int i, j;
    string decpt1 ="";
    // Loop through each binary representation in the encrypted text
    for (i=0;i<encpt.length();i++){
        // Loop through the value array to find the corresponding letter
        for (j=0;j<26;j++){
            if(encpt.substr(i,1)==value[j]){
                decpt1 += key[j]+" ";
            }
        }
    }
    return decpt1;
}

int main (){
    string pt,encpt,decpt;
    cout <<"Welcome to Bancian Cipher\n";
    cout <<"Enter plaintext: ";
    getline(cin,pt);
    int i;
    for(i=0;i<pt.size();i++){
        pt[i]=toupper(pt[i]);
    }
    encpt = encrypt(pt);
    cout <<"Encrypted text: "<<encpt<<"\n";
    for(i=0;i<pt.size();i++){
        pt[i]=tolower(pt[i]);
    }
    decpt=pt;
    cout<<"Decrypted text: "<<decpt;
    return 0;
}