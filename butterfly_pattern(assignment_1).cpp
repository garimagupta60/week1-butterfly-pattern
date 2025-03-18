
#include<iostream>
using namespace std;

int isDigit(char inputCharacter){
    
    return (inputCharacter>='0' && inputCharacter<='9');
}

int stringToInteger(string inputRows){
    
    int index = 0;
    int signOfNumber = 1;
    int number = 0;
    
    if(inputRows[index] == '-'){
        
        signOfNumber = -1;
        index++;
        
    }else if(inputRows[index] == '+'){
        
        index++;
    }
    
    while(inputRows[index]!='\0'){
        number = number*10 + (inputRows[index] - '0');
        index++;
    }
    
    return signOfNumber * number;
}

int getRowsFromUser(){
    int rows = 0;
    string inputRows;
    while(true){
        
        cout<<"Enter the number of rows"<<endl;
        getline(cin,inputRows);
        
        if (inputRows.empty()) {
            cout << "Enter a valid positive number.\n";
            continue;
        }
        
        bool validInputString = true;
        
        for(int index = 0; index < inputRows.size(); index++){
            
            if(index == 0 && (inputRows[index] == '-' || inputRows[index] == '+')){
                
                continue;
            }
            
            if(!isDigit(inputRows[index])){
                
                validInputString = false;
                break;
            }
        }
        
        if(validInputString == true){
            rows = stringToInteger(inputRows);
            if(rows > 0){
                
                break;
                
            }else{
                
                cout<<"Enter valid positive number"<<endl;
            }
        }else{
            
            cout<<"Enter valid positive number"<<endl;
            
        }  
    }
    
    return rows;
}

void printPattern(int rows){
    
    int spaces = 2 * rows - 1;
    int stars = 0;
    char printCharacter = '1';
    
    for(int rowIndex=1; rowIndex<=2*rows - 1; rowIndex++){
        
        if(rowIndex <= rows){
            
            spaces = spaces - 2;
            stars++;
            
        }else{
            
            spaces = spaces + 2;
            stars--;
            
        }

        if(rows % 2 == 1){
            
            printCharacter = '1';
            
        }else{
            
            printCharacter = '0';
        }
        
        for(int columnIndex = 1; columnIndex <= stars; columnIndex++){
            
            cout<<printCharacter<<" ";
            if(printCharacter == '1')
                printCharacter = '0';
            else 
                printCharacter = '1';
            
        }
        
        for(int columnIndex = 1; columnIndex <= spaces; columnIndex++){
            cout<<"  ";
        }

        if(rowIndex != rows){
            
            printCharacter = '1';
            
        }else{
            
            printCharacter = '0';
            
        }
        
        for(int columnIndex = 1; columnIndex <= stars; columnIndex++){
            
            if(columnIndex != rows){
                
                cout<<printCharacter<<" ";
                if(printCharacter == '1')
                    printCharacter = '0';
                else 
                    printCharacter = '1';
            
            }
        }

        cout<<endl;
    }
}


int main(){
    
    
    int rows = getRowsFromUser();
    printPattern(rows);
    
    return 0;
}