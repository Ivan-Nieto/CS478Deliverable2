//
//  project2_encryption.cpp
//  
//
//  Created by Ivan on 4/18/19.
//
// Compile with
//       g++ project2_encryption.cpp -L/usr/local/ssl/lib -lssl -lcrypto
//

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <fstream>


#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>
#include <openssl/ssl.h>
#include <openssl/evp.h>
#include <openssl/bio.h>
#include <openssl/bn.h>


using namespace std;


//Prints the contents of the given file. For debugging
void fileTest(ifstream& in){
    
    in.clear();
    in.seekg(0,in.beg);
    
    
    char temp;
    while(in){
        
        in >> temp;
        printf("%c",temp);
        
    }//end while
    
    printf("\n\n");
    
}//end fileTest

int main(int argc, char *argv[]){
    
    
    //printing parameters
    cout << "The encripted message file is: " << argv[1] << endl;
    cout << "The public key file is:        " << argv[2] << endl;
    cout << "The private key file is:       " << argv[3] << endl;
    cout << "\n" << endl;

    //concatenating parameters with encryption command.
    char cmd[500];
    strcpy(cmd,"openssl rsautl -encrypt -pubin -inkey ");
    strcat(cmd,argv[2]);//adding public key file name.
    strcat(cmd, " -in ");
    strcat(cmd, argv[1]);//adding encrypted message file name.
    strcat(cmd," -raw -hexdump -out symmetric.txt");
    
    
    //calling openssl encryption command with given parameters.
    system(cmd);
    
    
    //msg.txt will hold the plaintext to be encrypted. 
    FILE *f = fopen("msg.txt","w");
    fprintf(f,"Ivan Nieto\n800629123\n");
    fclose(f);
    cout << "Created file msg.txt to hold a message to be encrypted.\n" << endl;
    
    //Repurposing cmd to hold command to encrypted.
    strcpy(cmd,"openssl enc -aes256 -k symmetric.txt -in msg.txt -out sec.enc ");
    
    
    //calling openssl encryption command for aes with symetric key symmetric.txt
    system(cmd);
    cout << "Encrypted msg.txt with aes and created the new file sec.enc\n" << endl;
    
    
    
    //Repurposing cmd to hold command to sign 
    strcpy(cmd,"openssl dgst -sha256 -sign "); 
    strcat(cmd,argv[3]);//adding the private key. 
    strcat(cmd," -out sec.signed.enc sec.enc");
    
    
    
    //Calling openssl command to sign the sec.enc file with the provided private key
    // and saving the new signed file in sec.signed.txt
    system(cmd);
    cout << "Signing sec.enc and storing signed version in new file called sec.signed.enc\n\n";

    
    
    //Calling the command to convert the signed file to base 64 and 
    // storing it in sec.signed.base64.txt
    strcpy(cmd,"openssl base64 -in sec.signed.enc -out sec.signed.base64.enc");
    system(cmd);
    cout << "Converting the signed file sec.signed.enc to base64 and storing new version";
    cout << " in file sec.signed.base64.enc\n" << endl;
    
}//end main



















