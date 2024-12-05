#include "puzzle.h"

// Construct the puzzle, and call both fill() and makeMem()
Puzzle::Puzzle(int size){
    // Checks that the size is zero or greater
    if(size < 0){
        m_size = 0;
    } else{
        m_size = size;
    }
    makeMem();
    fill();
}

// Puzzle Destructor
Puzzle::~Puzzle(){
    clear();
}

// Called in destruction operator
void Puzzle::clear(){
    // For loop to iterate through the array of arrays, and delete the arrays
    for(int i = 0; i < m_size; i++){
        delete []m_table[i];
    }
    delete []m_table;
    // Reset the size to zero
    m_size = 0;
}


// Creates the dynamic memory that will be used for the
void Puzzle::makeMem(){
    //Checks if the size of the array is above zero
    if(m_size < 0){
        cout << "Size is set to less than one and as such the table cannot be created." << endl;
    }else{
        // Creates a table of the m_size in both the number of rows and the number of columns
        m_table = new char*[m_size];
        // Iterates through the array in m_table, and creates arrays that are part of the
        for(int j = 0; j < m_size; j++){
            m_table[j] = new char[m_size];
        }
    }
}

// Puzzle copy constructor
Puzzle::Puzzle(const Puzzle& rhs){
    if(rhs.m_size < 0){
        cout << "Copy Constructor Failure. (size is 0)" << endl;
    } else {
        m_size = rhs.m_size;
        // Creates a new array in memory, so it can be dynamically allocated.
        makeMem();
        // Iterate through the new table and fill it from the old table
        for(int x = 0; x < m_size; x++){
            for(int y = 0; y < m_size; y++){
                // Copy for every position in the 2d array
                m_table[x][y] = rhs.m_table[x][y];
            }
        }
    }
}

// Overloaded assignment operator
const Puzzle& Puzzle::operator=(const Puzzle& rhs){
    this->makeMem();
    for(int x = 0; x < this->m_size; x++){
        for(int y = 0; y < this->m_size; y++){
            // Copy for every position in the 2d array
            this->m_table[x][y] = rhs.m_table[x][y];
        }
    }
    return *this;
}

// Display Function for the Puzzle
void Puzzle::dump(){
    if (m_size > 0){
        int i=0;
        int j=0;
        while(i<m_size){
            while(j<m_size){
                cout << m_table[i][j] << " ";
                j++;
            }
            cout << endl;
            j=0;
            i++;
        }
        cout << endl;
    }
}

// Fills the puzzle with randomized characters
void Puzzle::fill(){
    srand(time(NULL));//create the seed value using the current time
    int i=0;
    int j=0;
    while(i<m_size){
        while(j<m_size){
            m_table[i][j] = ALPHA[rand() % MAX];//find a random char from the chars list
            j++;
        }
        j=0;
        i++;
    }
}