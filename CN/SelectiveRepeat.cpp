
#include <iostream>
#include <vector>
using namespace std;
//CN lab internal
//Selective repeat

void checkACK_vector(vector<int> ack, int n) {
    for(int i=0; i<n; i++) {
            cout << "#" << ack[i+1] << " ";
    } cout << endl;
}

int main() {
    int n, windowSize, lostFrame;

    cout << "Enter total number of frames: ";
    cin >> n;

    cout << "Enter window size: ";
    cin >> windowSize;

    cout << "Enter frame number to simulate loss (0 for none): ";
    cin >> lostFrame;

    if(lostFrame > n) {
        cout << "Invalid frame number!" << endl;
        return 0;
    }

    vector<int>ack(n+1, 0);

    int i = 1;

    while (i <= n) {
        int end = min(i + windowSize - 1, n);

        cout << "\nSending frames " << i << " to " << end << endl;

        for (int j = i; j <= end; j++) {
            if (j == lostFrame && ack[j] == 0) {
                cout << "Frame " << j << " lost!" << endl;
                //checkACK_vector(ack, n);
                //cout << endl;
            } else if (ack[j] == 0) {
                cout << "Frame " << j << " received. ACK " << j << endl;
                ack[j] = 1;
            }
        }

        for (int j = i; j <= end; j++) {
            if (ack[j] == 0) {
                cout << "Retransmitting frame " << j << endl;
                cout << "Frame " << j << " received. ACK " << j << endl;
                ack[j] = 1;
            }
        }

        i = end + 1;

        checkACK_vector(ack, n);
    }

    cout << "\nAll frames transmitted successfully!" << endl;

    return 0;
}
