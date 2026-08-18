#include <iostream>
#include <string>
#include <vector>

using namespace std;

const string FLAG = "01111110";
const int MAX_CONSECUTIVE_ONES = 5;


// Check whether a string is a valid FLAG
bool isFlag(const string& bits) {
    return bits == FLAG;
}


// Check whether the frame starts and ends with FLAG
bool isValidFrame(const string& frame) {

    if (frame.size() < 2 * FLAG.size()) {
        return false;
    }

    bool startsWithFlag =
        frame.substr(0, FLAG.size()) == FLAG;

    bool endsWithFlag =
        frame.substr(frame.size() - FLAG.size()) == FLAG;

    return startsWithFlag && endsWithFlag;
}


// Insert a stuffed 0 immediately after the given position
void insertStuffedBit(string& bits, int position) {
    bits.insert(position + 1, "0");
}


// Split the frame into FLAG and DATA blocks
vector<string> splitIntoBlocks(const string& frame) {

    vector<string> blocks;

    int position = 0;
    string dataBlock;

    while (position < frame.size()) {

        // Check whether FLAG starts at current position
        if (frame.substr(position, FLAG.size()) == FLAG) {

            // Store previous DATA block
            if (!dataBlock.empty()) {
                blocks.push_back(dataBlock);
                dataBlock.clear();
            }

            // Store FLAG
            blocks.push_back(FLAG);

            position += FLAG.size();
        }
        else {

            // Store DATA bit
            dataBlock += frame[position];
            position++;
        }
    }

    // Store remaining DATA block
    if (!dataBlock.empty()) {
        blocks.push_back(dataBlock);
    }

    return blocks;
}


// Perform bit stuffing on DATA blocks
vector<vector<int>> stuffBits(vector<string>& blocks) {

    // stuffedPositions[i] stores the positions of
    // stuffed bits in blocks[i].
    vector<vector<int>> stuffedPositions(blocks.size());

    // Even indexes -> FLAG
    // Odd indexes  -> DATA
    for (int blockIndex = 1;
         blockIndex < blocks.size();
         blockIndex += 2) {

        int consecutiveOnes = 0;

        for (int bitIndex = 0;
             bitIndex < blocks[blockIndex].size();
             bitIndex++) {

            if (blocks[blockIndex][bitIndex] == '1') {
                consecutiveOnes++;
            }
            else {
                consecutiveOnes = 0;
            }

            // Five consecutive 1s found
            if (consecutiveOnes == MAX_CONSECUTIVE_ONES) {

                // Insert 0 after the fifth 1
                insertStuffedBit(
                    blocks[blockIndex],
                    bitIndex
                );

                // Store position of inserted 0
                stuffedPositions[blockIndex]
                    .push_back(bitIndex + 1);

                // Reset counter
                consecutiveOnes = 0;

                // Skip the inserted 0
                bitIndex++;
            }
        }
    }

    return stuffedPositions;
}


// Print all blocks
void printBlocks(const vector<string>& blocks) {

    cout << "\nBlocks:\n";

    for (int blockIndex = 0;
         blockIndex < blocks.size();
         blockIndex++) {

        cout << "Block " << blockIndex << ": "
             << blocks[blockIndex] << "\n";
    }
}


// Print the final stuffed frame
void printOutput(const vector<string>& blocks) {

    cout << "\nOutput: ";

    for (const string& block : blocks) {
        cout << block << " ";
    }

    cout << "\n";
}


// Print ^ below stuffed bits
void printStuffedPositions(
    const vector<string>& blocks,
    const vector<vector<int>>& stuffedPositions
) {

    cout << "\nStuffed bits:\n";

    for (int blockIndex = 0;
         blockIndex < blocks.size();
         blockIndex++) {

        // FLAG block
        if (blockIndex % 2 == 0) {

            for (int i = 0;
                 i < blocks[blockIndex].size();
                 i++) {

                cout << " ";
            }
        }

        // DATA block
        else {

            for (int bitIndex = 0;
                 bitIndex < blocks[blockIndex].size();
                 bitIndex++) {

                bool isStuffed = false;

                for (int position :
                     stuffedPositions[blockIndex]) {

                    if (position == bitIndex) {
                        isStuffed = true;
                        break;
                    }
                }

                if (isStuffed) {
                    cout << "^";
                }
                else {
                    cout << " ";
                }
            }
        }

        cout << " ";
    }

    cout << "\n";
}


int main() {

    string inputFrame;

    // ----------------------------------------
    // Input
    // ----------------------------------------

    cout << "Enter bits: ";
    cin >> inputFrame;


    // ----------------------------------------
    // Validate frame
    // ----------------------------------------

    if (!isValidFrame(inputFrame)) {

        cout << "\nInvalid frame!\n";
        cout << "Frame must start and end with "
             << FLAG << ".\n";

        return 0;
    }


    // ----------------------------------------
    // Split frame into FLAG and DATA blocks
    // ----------------------------------------

    vector<string> blocks =
        splitIntoBlocks(inputFrame);


    // ----------------------------------------
    // Display blocks
    // ----------------------------------------

    printBlocks(blocks);


    // ----------------------------------------
    // Perform bit stuffing
    // ----------------------------------------

    vector<vector<int>> stuffedPositions =
        stuffBits(blocks);


    // ----------------------------------------
    // Output
    // ----------------------------------------

    cout << "\nBit Count: "
         << inputFrame.size()
         << "\n";

    cout << "Input: "
         << inputFrame
         << "\n";

    printOutput(blocks);

    printStuffedPositions(
        blocks,
        stuffedPositions
    );


    return 0;
}