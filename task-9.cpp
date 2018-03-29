/*************************************************************
 FCI - programming 1 -2018 - Assignment 2
 program Name:  Rail-fence Cipher
 last Modification Date: 28/2/2018
 Author and ID and Group: aya amr 20170359  G14
 Teaching Assistant: Eng. Ibrahim Zidan & Eng. Mohammed Atta.
 purpose: cipher and decipher a message
**************************************************************/


#include <iostream>

using namespace std;

int main()
{
int q;
cout<<"ahlan ya user ya habibi:)"<<endl;
cout<<"what do you like to do today? \n"<<endl;
while(true){
cout << "1-cipher a message \n2-decipher a message \n3-End" << endl;
cin>>q;
if(q==1){
    string text;
    int key;
    cout<<"enter the text you want to cipher;)";
    cin.ignore();
    getline(cin,text);
    cout<<"enter the key : ";
    cin>>key;
//removing the spaces from text.
    for(int i=0;i<text.size();i++) {
        if(text[i]==' ' ){
            text.erase(i,1);
        }
        if(text[i+1]==' '){
            text.erase(i+1,1);
        }
    }

    string code[key][text.size()];

    for(int k=0;k<key;k++){
        for(int l=0;l<text.size();l++){
            code[k][l]='.';
            }
        }
    int row=0, col=0, counter=0;
    bool dir_down=true;
 //Fill the array with the text
    while(true){
        code[row][col]=text[counter];

        counter++;

        if(row == key-1){
            dir_down=false;
        }

        if(row==0){
            dir_down = true;
        }

        if(dir_down == false){
            row--;
            col++;
        }

        else if(dir_down == true){
            row++;
            col++;
        }

        if( counter == text.size())
            break;
    }
    //print the ciphered text
        for(int p=0;p<key;p++){
            for(int w=0;w<text.size();w++){
                    if(code[p][w]!=".")
                        cout<<code[p][w];
            }
        }
        cout << endl;
}


if(q==2){
    string text,newtext="";
    int key;
    cout<<"enter the text you want to Decipher;)";
    cin.ignore();
    getline(cin,text);
    cout<<"enter the key : ";
    cin>>key;

    for(int i=0;i<text.size();i++) {
        if(text[i]==' ' ){
            text.erase(i,1);
        }
        if(text[i+1]==' '){
            text.erase(i+1,1);
        }
    }

    string code[key][text.size()];

    for(int k=0;k<key;k++){
        for(int l=0;l<text.size();l++){
            code[k][l]='.';
            }
        }


    int y=0, row=0, col=0, counter=0;
    bool dir_down=true;


    for (int i=0; i < text.length(); i++)
    {
        if (row == 0)
            dir_down = true;
        if (row == key-1)
            dir_down = false;

        code[row][col++] = "'*";

        dir_down ? row++ : row--;
    }

    int charIndex = 0;

    //Fill the 2D array with ciphered text
    for(int i=0; i<key; i++){
        for(int j=0; j<text.length(); j++){
            if(code[i][j] == "'*" && charIndex < text.length()){
                code[i][j] = text[charIndex];
                charIndex++;
            }
        }
    }

    //Read the 2D array to get deciphered text
    row = 0, col = 0;
    for (int i=0; i< text.length(); i++)
    {

        if (row == 0)
            dir_down = true;
        if (row == key-1)
            dir_down = false;

        if (code[row][col] != "." && code[row][col] != "*"){
            newtext += code[row][col];
            col++;
        }

        dir_down?row++: row--;
    }

    //print the deciphered text
    cout << newtext << endl;
}

if(q==3){
    return 0;
}
}
}







