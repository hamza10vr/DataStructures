/*  Hamza Tanveer
    Date 11/16/2021
    HW 7 - Huffman 
*/


#include<unordered_map>
#include<iostream>
#include<string>
#include<queue>
#include<fstream>



using namespace std;

// Struct for Huffman Tree Node
struct Node     
{
    int freq;              // frequency of character -> unsigned int for positive freq values only
    char ch;                // input character
    Node* left, * right;   // pointer to a node
};





Node* getNode(char ch, int freq, Node* left, Node* right)   // Function to allocate a new tree node
{
    Node* node = new Node();

    node->ch = ch;          // character node
    node->freq = freq;      // fequency node
    node->left = left;      // left node
    node->right = right;    // right node

    return node;            // retuns the node
}

// Comparison object to be used to order the heap
struct comp
{
    bool operator()(Node* left, Node* right)
    {
        // highest priority item has lowest frequency
        return left->freq > right->freq;
    }
};

void printCode(struct Node* root, string str, char ch[], string code[], int& position)
{
    if (!root) // if there is no root pointer
    {
        return; // implicitly return & break out of the if branch
    }

    if (root->ch != '$') // if the root pointer that points to input node is not a $ sign
    {
        cout << root->ch << " " << str << "\n"; // output the root->input (e.g. a, b, c, t, ...) with an empty space
        // and display the string contained for each & every root->input

        // get the character and its corresponding code
        ch[position] = root->ch; // assign root->input to the ch array of position parameter
        code[position] = str; // assign str to the code array of position parameter
        position++; // increment the position accordingly
    }

    // recursively call the function accordingly
    printCode(root->left, str + "0", ch, code, position); // 0 for left
    printCode(root->right, str + "1", ch, code, position); // 1 for right

}

// Traverse the Huffman Tree and store Huffman Codes in a map.
void encode(Node* root, string str, unordered_map<char, string>& huffmanCode)
{
    if (root == NULL)
        return;

    // found a leaf node
    if (!root->left && !root->right) {
        huffmanCode[root->ch] = str;
    }

    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}

unordered_map<char, string> printAndReturnEncode(Node* root) {

    // Traverse the Huffman Tree and store Huffman Codes in a map. Also prints them
    unordered_map<char, string> huffmanCode;
    encode(root, "", huffmanCode);

    cout << "\n========= Huffman Codes are ============\n" ;
    for (auto pair : huffmanCode) {
        cout << pair.first << ": " << pair.second << '\n';
    }

    return huffmanCode;

}


// Builds Huffman Tree and decode given input text
Node* buildHuffmanTree(unordered_map<char, int>& freq)
{

    // Create a priority queue to store live nodes of Huffman tree;
    priority_queue<Node*, vector<Node*>, comp> pq;

    // Create a leaf node for each character and add it to the priority queue.
    for (auto pair : freq) {
        pq.push(getNode(pair.first, pair.second, NULL, NULL));
    }

   
    while (pq.size() != 1)           // do till there is more than one node in the queue
    {
        
        Node* left = pq.top(); pq.pop();        // Remove the two nodes of highest priority (lowest frequency) from the queue
        Node* right = pq.top();   pq.pop();

        // Create a new internal node with these two nodes as children and with frequency equal
        // to the sum of the two nodes' frequencies. Add the new node to the priority queue.
        int sum = left->freq + right->freq;
        pq.push(getNode('\0', sum, left, right));
    }

    // root stores pointer to root of Huffman Tree
    Node* root = pq.top();
    return root;
}


void insertionSort(char letter[], int freq[], int size)
{
    for (int i = 1; i < size; i++) // run through for-loop from 1 to the size of the array
    {
        // prevent overwriting values
        int key = freq[i]; // assign freq array of index i to key variable
        char ch = letter[i]; // assign letter array of index i to ch variable
        int j = i - 1; // assign the j varialbe to its predecessor (i - 1)

        // compare and swap values if able to do so
        while (j >= 0 && freq[j] > key) // so long as  j is positionitive & freq array of index i greater than key variable
        {
            freq[j + 1] = freq[j]; // assign freq array of index j to its successor (j + 1)
            letter[j + 1] = letter[j]; // assign letter array of index j to its successor (j + 1)
            j--; // decrement j variable accordingly
        }

        freq[j + 1] = key; // assign key variable into the freq array of index j + 1 (the j's successor)
        letter[j + 1] = ch; // assign ch variable into the letter array of index j + 1 (the j's successor)
    }
}

string readFileReturnText(string inputFileName) {
    ifstream ifs(inputFileName);
    string text;
    getline(ifs, text, (char)ifs.eof());

    ifs.close();

    return text;
}

unordered_map<char, int> readFileAndGenerateFreq(string inputFileName) {

    string text = readFileReturnText(inputFileName);

    
    unordered_map<char, int> freq;      //Count frequency of appearance of each character and store it in a map

    int i = 0;
    while (text[i] != '\0') 
    {
        freq[text[i++]] += 1;
    }

   
    cout << "\n============ Char and Freq  ==========\n";    //print Count of frequency of each character
    for (auto pair : freq) 
    {
        cout << pair.first << ": " << pair.second << endl;
    }

    return freq;
}

void encodeAndSave(unordered_map<char, string>& huffmanCode, string inputFileName) {

    string text = readFileReturnText(inputFileName);

    
    string encodedStr = ""; // print encoded string
    for (char ch : text) {
        encodedStr += huffmanCode[ch];
    }


    //cout << "\nEncoded string is :\n" << encodedStr << '\n'; // out puts tot he console to check

    
    string outputFileName = "pride.huff";   //Save Encoded String
    ofstream out(outputFileName);   
    out << encodedStr;  // output it to the encoded str
    out.close();        // close the file


}

int main() {


    ifstream fin; // declare input file stream of fin object
    ofstream fout; // declare output file stream of fout object

    // declare the variables
    int position = 0;  // position is initialized to zero
    char ch; // character is then declared

    char letter[100] = { '\0' }; // assign letter array of 100 spots to null
    int freq[100] = { 0 }; // assign freq array of 100 spots to zero

    // read input from file
    //fin.open("pride_and_prejudice.txt");

    unordered_map<char, int> frequency = readFileAndGenerateFreq("Pride_and_Prejudice.txt");    // reading fle and generating frequencies
    Node* root = buildHuffmanTree(frequency);   // using the node to build the huffman tree
    unordered_map<char, string> huffmanCode = printAndReturnEncode(root);   // printing huffman code
    encodeAndSave(huffmanCode, "Pride_and_Prejudice.txt"); // encoding and saving into the file

    //fin.close(); // close the input file 

    //insertionSort(letter, freq, position);
    // call the insertionS


    return 0;
}