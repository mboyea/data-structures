//
//  CSCI251ProjTwo.cpp
//  ProjectTwoCSCI251
//
//  Created by Hongbiao Zeng on 3/12/19.
//  Copyright © 2019 Hongbiao Zeng. All rights reserved.
//

#include <iostream>
#include <string>
#include <cctype>
// * Because I'm defining Template Methods in a cpp file,
// * I must include the .cpp file instead
#include "MyQueue.cpp"
#include "MyStack.cpp"
using namespace std;

bool isPalindrome(string sentence);

int main(){
    string sentence;
    char choice;
    do {
        cout <<"Enter a sentence: ";
        getline(cin, sentence);
        cout << "\"" << sentence << "\"";
        if(isPalindrome(sentence))
            cout << " is a palindrome" << endl;
        else
            cout << " is NOT a palindrome" << endl;
        cout << "Do you want to make another check? Y/N :";
        cin >> choice; // get input char
        cin.ignore(); // ignore new lines
    } while (choice == 'y' || choice == 'Y');
    cout << "Thanks for choose the ";
    return 0;
}

bool isPalindrome(string sentence){
    MyQueue<char> queue;
    MyStack<char> stack;
    // put sentence into queue and stack
    for (unsigned int i = 0; i < sentence.length(); i++) {
        queue.push(sentence[i]);
        stack.push(sentence[i]);
    }
    // for every character in the queue and stack
    for (unsigned int i = 0; i < sentence.length(); i++) {
        // if they aren't equal, the sentence must not be a palindrome
        if (queue.pop() != stack.pop()) {
            return false;
        }
    }
    // otherwise, they must be a palindrome
    return true;
}
