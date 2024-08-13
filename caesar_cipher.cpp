#include <iostream>
#include<vector>
using namespace std;

string decrypt(vector<char>& arr, string str, int key){
 
    string PT = "";
    int index;
    for(int i=0; i<str.length(); i++){
        for(int j=0; j<arr.size(); j++){
            if(str[i] == arr[j]){
                index = (j - key) % 26;
                break;
            }
        }
        PT += arr[index];
    }
    return PT;
}

string encrypt(vector<char>& arr, string str, int key){
 
    string CT = "";
    int index;
    for(int i=0; i<str.length(); i++){
        for(int j=0; j<arr.size(); j++){
            if(str[i] == arr[j]){
                index = (j + key) % 26;
                break;
            }
        }
        CT += arr[index];
    }
    return CT;
}

int main()
{
    vector<char> arr = {'a', 'b', 'c', 'd', 'e','f', 'g', 'h', 'i', 'j','k', 'l', 'm', 'n', 'o','p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    string str;
    cout << "Enter the text : ";
    cin >> str;

    int key;
    cout << "Enter key : ";
    cin >> key;

    string s = encrypt(arr, str, key);

    
    cout << "Cipher text (Encrypted text) : " << s << endl;
    cout << "Plain text (Decrypted text): " << decrypt(arr, s, key) << endl;

    return 0;

}
