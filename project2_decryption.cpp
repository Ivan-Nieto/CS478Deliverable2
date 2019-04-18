// Ivan Nieto
// 4-18-19
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




int main(int argc, char *argv[]){

    
    //printing parameters
    cout << "\nThe signed file is:        " << argv[1] << endl;
    cout << "The public key file is:    " << argv[2] << endl;
    cout << "The symmetric key file is: " << argv[3] << endl;
    cout << "\n" << endl;
    
    
    //Concatenating parameters with command for verifying signiture.
    char cmd[500];
    strcpy(cmd,"openssl base64 -d -in ");
    strcat(cmd,argv[1]);
    strcat(cmd," -out sign.sha256");
    
    //Calling command to verify signiture
    system(cmd);
    cout << "Converting the provided signed file back from base 64 ";
    cout << "and storing the output in a new file called sign.sha256.\n" << endl;
    
    
    
    //Repurposing cmd to complete the verification process.
    strcpy(cmd,"openssl dgst -sha256 -verify ");
    strcat(cmd,argv[2]);
    strcat(cmd," -signature sign.sha256 sec.enc ");
    
    
    //Calling openssl command to verify signiture. 
    system(cmd);
    cout << "\nVerifying the signed file with the provided public key ";
    cout << "and saving the output in a new file called sign.sha256.\n" << endl;
    
    
    
    //decrypting the original message in msg.txt from the output of the
    // signiture verification using the symmetric.txt key.
    strcpy(cmd," openssl enc -in sec.enc -out msg.txt.decrypted -d -aes256 -k ");
    strcat(cmd,argv[3]);
    
    //Calling openssl command
    system(cmd);
    cout << "Decrypting the file and storing the decrypted message in msg.txt.decrypted\n" << endl;
    
    
}//end main




