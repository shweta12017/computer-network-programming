#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int n;
    srand(time(0));
    cout << "      Stop and Wait ARQ\n";
    cout << "Enter number of frames: ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int frame;

        cout << "\nEnter frame number: ";
        cin >> frame;

        bool received = false;

        while (!received)
        {
            cout << "\nSending Frame " << frame << "...\n";
            cout << "Timer started...\n";

            // Randomly decide whether frame is lost
            int loss = rand() % 2;   // 0 = received, 1 = lost

            if (loss == 1)
            {
                cout << "Frame " << frame << " lost!\n";

                // Wait for timeout
                this_thread::sleep_for(chrono::seconds(3));

                cout << "Timeout occurred after 3 seconds.\n";
                cout << "Retransmitting Frame " << frame << "...\n";
            }
            else
            {
                // Frame successfully received
                this_thread::sleep_for(chrono::seconds(1));

                cout << "Frame " << frame
                     << " received successfully.\n";

                cout << "ACK " << frame << " received.\n";
                cout << "Timer stopped.\n";

                received = true;
            }
        }
    }

    cout << "\nTransmission completed successfully.\n";

    return 0;
}

/*Stop and Wait ARQ
Enter number of frames: 4

Enter frame number: 1

Sending Frame 1...
Timer started...
Frame 1 received successfully.
ACK 1 received.
Timer stopped.

Enter frame number: 2

Sending Frame 2...
Timer started...
Frame 2 lost!
Timeout occurred after 3 seconds.
Retransmitting Frame 2...

Sending Frame 2...
Timer started...
Frame 2 received successfully.
ACK 2 received.
Timer stopped.

Enter frame number: 3

Sending Frame 3...
Timer started...
Frame 3 received successfully.
ACK 3 received.
Timer stopped.

Enter frame number: 4

Sending Frame 4...
Timer started...
Frame 4 received successfully.
ACK 4 received.
Timer stopped.

Transmission completed successfully.*/