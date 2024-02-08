#include <bits/stdc++.h>
using namespace std;

enum TokenType{
    
   Let,
   Assignment,
   Identifier,
   OpenParenthesis,
   ClosedParenthesis,
   Plus, 
   Miuns,
   Equals,
   
}; 

class Token{

private: 
  string value;
  TokenType type;

public:
    Token(string value, TokenType type){
        this->value = value;
        this->type = type;
    }
    
    void print(){
        cout << type << " " << value << endl;
    }
    
    
};

// need to be tested again
// splits the sentence into tokens depending
// On special charchters like spaces:  ( , + , = , )
// Ddinot handel strings
vector<string> split(string str){
    vector<string> answer;
    
    int idx = 0, len = str.size();
    string tmp;
    
    while(idx < len){
        if(isalpha(str[idx]) || isdigit(str[idx])){
            tmp += str[idx];
        }
        else{
            if(tmp.empty() == false){
                answer.push_back(tmp);
                tmp = "";
            }
            if(str[idx] != ' '){
                string ch = "";
                ch += str[idx];
                answer.push_back(ch);
            }
        }
        idx ++;
        
    }
    if(!tmp.empty()){
        answer.push_back(tmp);
    }
    
    return answer;
    
}

vector<Token>  tokenize(string line){
    vector<Token> tokenizedLine;
    vector<string> splittedLine = split(line);
    
    for(int i = 0;i<(int)splittedLine.size();i++){
        string word = splittedLine[i];
        if(word == "("){
           tokenizedLine.push_back(Token("(", OpenParenthesis));
        }
        else if(word == ")"){
            tokenizedLine.push_back(Token(")", ClosedParenthesis));
        }
        else if(word == "+"){
            tokenizedLine.push_back(Token("+", Plus));
        }
        else if(word == "Let"){
            tokenizedLine.push_back(Token("Let", Let));
        }
        else if(word == "-"){  
            tokenizedLine.push_back(Token("-", Miuns));
        }
        else if(word == "="){
            if(i  + 1 <(int) splittedLine.size() && splittedLine[i + 1] == "="){
                tokenizedLine.push_back(Token("==", Equals));
                i++;
            }
            else{
                tokenizedLine.push_back(Token("=", Assignment));
            }
        }
        else{
            tokenizedLine.push_back(Token(word, Identifier));
        }
    }
    
    return tokenizedLine;
    
}
int main()
{
    
    vector<Token> tmp = tokenize("Let x=6899");
    
    for(auto tok: tmp){
        tok.print();
    }
    
    
    
}
