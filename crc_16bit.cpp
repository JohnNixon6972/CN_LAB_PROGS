#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>

string CRC_16bit_sender_end(string message,string polynomial){

    cout<<"-------------AT SENDERS SIDE--------------- "<<endl;
    int n, m;
    string encrypted_msg = "";
    n = polynomial.length();
    m = message.length();

    encrypted_msg += message;

    for (int i = 1; i <= n - 1; i++)
    {
        encrypted_msg += '0';
    }
    cout <<"Before division the message string is :: "<<encrypted_msg << endl;

    int i = 0;
    while (i <= encrypted_msg.length() - n)
    {
        if (encrypted_msg[i] == '1')
        {
            for (int j = 0; j < n; j++)
            {
                // if (encrypted_msg[i + j] == polynomial[i + j])
                // {
                //     encrypted_msg[i + j] = '0';
                // }
                // else
                // {
                //     encrypted_msg[i + j] = '1';
                // }
                encrypted_msg[i + j] = encrypted_msg[i + j] == polynomial[j] ? '0' : '1';
            }
        }
        else{
            i++;
        }
    }

    cout <<"After division the message string is :: "<< encrypted_msg << endl;
    string crc_bits;
    crc_bits = encrypted_msg.substr(encrypted_msg.length()-n+1);
    cout<<"The CRC bits are :: "<<crc_bits<<endl;

    string final_encrypted_msg = message + crc_bits;
    cout<<"The Final Encrypted Message is :: "<<final_encrypted_msg<<endl;

    return final_encrypted_msg;
}

void CRC_16bit_receiver_end(string final_encrypted_message,string polynomial){
    cout<<endl<<"-------------AT RECEIVERS SIDE--------------- "<<endl;
    int i = 0;
    int n = polynomial.length();
    while (i <= final_encrypted_message.length() - n)
    {
        if (final_encrypted_message[i] == '1')
        {
            for (int j = 0; j < n; j++)
            {
                final_encrypted_message[i + j] = final_encrypted_message[i + j] == polynomial[j] ? '0' : '1';
            }
        }
        else{
            i++;
        }
    }
    string crc_bits;
    crc_bits = final_encrypted_message.substr(final_encrypted_message.length()-n+1);

    for(int j=0;j<crc_bits.length();j++){
        if(crc_bits[j]=='1'){
            cout<<"Error Detected!!"<<endl;
            return;
        }
    }
    cout<<"Message is error free!!"<<endl;
    
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    string message, polynomial;
    // cout << "Enter the binary message string :: ";
    getline(cin, message);
    // cout << "Enter the polynomial :: ";
    getline(cin, polynomial);

    string encrypted_message = CRC_16bit_sender_end(message,polynomial);
    // encrypted_message[0] = '0'; //->to put an error 
    CRC_16bit_receiver_end(encrypted_message,polynomial);
    
    return 0;
}