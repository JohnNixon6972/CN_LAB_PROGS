#include <iostream>
#include <windows.h>

#define bucket_size 100

using namespace std;

void leaky_bucket(int pcktsize, int opt_rate)
{
    if (pcktsize > bucket_size)
    {
        cout << "Bucket Overflow!!" << endl;
        cout << pcktsize - bucket_size << " Packet data have been lost!!"<<endl;
        return;
    }
    else
    {

        while (pcktsize >= opt_rate)
        {
            pcktsize -= opt_rate;
            cout << opt_rate << " packet data sent !! Remaining packet data is "<< pcktsize << endl;
            Sleep(500);
        }

        if (pcktsize > 0)
        {
            cout << "last " << pcktsize << " packet data has been sent" << endl;
        }
    }
    cout<<"Packet Sent Sucessfully !!"<<endl;
}

int main()
{
    int output_rate, no_packets;

    cout << "Enter output rate :: ";
    cin >> output_rate;

    cout << "Enter number of packets :: ";
    cin >> no_packets;

    int packet_sizes[no_packets];
    cout << "Enter " << no_packets << " sizes one by one :: ";

    for (int i = 0; i < no_packets; i++)
    {
        cin >> packet_sizes[i];
    }

    for (int i = 0; i < no_packets; i++)
    {
        Sleep(1000);
        cout << "Packet of size " << packet_sizes[i] << " being sent" << endl;

        leaky_bucket(packet_sizes[i], output_rate);
        cout<<endl;
    }

    return 0;
}