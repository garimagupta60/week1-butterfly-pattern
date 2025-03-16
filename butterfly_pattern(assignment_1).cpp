
#include<iostream>
using namespace std;

int main(){
    int rows;
    cout<<"Enter the number of rows"<<endl;
    cin>>rows;
    int spaces = 2 * rows - 1;
    int stars = 0;
    char printchar = '1';
    for(int i=1; i<=2*rows - 1; i++){
        if(i<=rows){
            spaces = spaces - 2;
            stars++;
        }else{
            spaces = spaces + 2;
            stars--;
        }

        if(rows%2 == 1){
            printchar = '1';
        }else{
            printchar = '0';
        }
        
        for(int j = 1; j <= stars; j++){
            cout<<printchar<<" ";
            if(printchar == '1')printchar = '0';
            else if(printchar == '0')printchar = '1';
        }
        
        for(int j = 1; j <= spaces; j++){
            cout<<" "<<" ";
        }

        if(i!=rows){
            printchar = '1';
        }else{
            printchar = '0';
        }
        for(int j = 1; j <= stars; j++){
            if(j!=rows){
                cout<<printchar<<" ";
                if(printchar == '1')printchar = '0';
                else if(printchar == '0')printchar = '1';
            }
        }

        cout<<endl;
    }
}