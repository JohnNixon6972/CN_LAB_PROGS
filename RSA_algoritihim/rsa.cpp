#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<long long int>

ll power(ll base,ll exponent,ll n){
    ll ans = 1;

    while(exponent--){
        ans = ans * base;
        ans = ans%n;
    }
    return ans;
}

ll RSA_encrypt(int msg,int encryption_key,int n){
    ll encrypted_msg;

    encrypted_msg = power(msg,encryption_key,n);

    return encrypted_msg;
}

ll RSA_decrypt(ll encrypted_msg,int decryption_key,int n){
    ll decrypted_msg;

    decrypted_msg = power(encrypted_msg,decryption_key,n);

    return decrypted_msg;
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    std::ios::sync_with_stdio(false);

    int p, q, msg;

    // cout<<"Enter the values for P and Q (Prime Numbers) :: ";
    cin >> p >> q;
    // cout<<"Enter the Integer Message :: ";
    cin >> msg;
    cout<<"Original Message is :: "<<msg<<endl;

    int z, n;

    n = p * q;
    z = (p - 1) * (q - 1);

    int encryption_key = 2, decryption_key = 1;

    while (z % encryption_key == 0)
    {
        encryption_key++;
    }
    // cout << encryption_key;

    while ((decryption_key * encryption_key) % z != 1)
    {
        decryption_key++;
    }
    // cout << decryption_key;

    cout<<"Encryption key (private key) 'e' is :: "<<encryption_key<<endl;
    cout<<"Decryption key (public key) 'd' is :: "<<decryption_key<<endl;


    ll cipher_text = RSA_encrypt(msg,encryption_key,n);
    cout<<"Encrypted Message is :: "<<cipher_text<<endl;


    ll decrypted_msg = RSA_decrypt(cipher_text,decryption_key,n);
    cout<<"Decrypted Message is :: "<<decrypted_msg;

    return 0;
}