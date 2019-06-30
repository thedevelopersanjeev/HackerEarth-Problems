/**
 * Checks if row has a repetition or not...
 **/
bool checkRow(const vector<string> &board, int row){
    
    set<char> st;
    
    for(int i = 0; i < 9; i++){
        
        // same number is present in this row before
        // return false immediately
        if(st.find(board[row][i]) != st.end())
            return false;
        
        // insert the current number
        if(board[row][i] != '.')
            st.insert(board[row][i]);
        
    }
    
    return true;
    
}

/**
 * Checks if column has a repetition or not...
 **/
bool checkColumn(const vector<string> &board, int col){
    
    set<char> st;
    
    for(int j = 0; j < 9; j++){
        
        if(st.find(board[j][col]) != st.end())
            return false;
        
        if(board[j][col] != '.')
            st.insert(board[j][col]);

    }
    
    return true;
    
}

/**
 * Checks if there is a repetition in given 3x3 box 
 **/
bool checkBox(const vector<string> &board, int startX, int startY){
    
    set<char> st;
    
    for(int i = 0; i < 3; i++){
        
        for(int j = 0; j < 3; j++){
            
            char curr = board[i+startX][j+startY];
            
            if(st.find(curr) != st.end())
                return false;
            
            if(curr != '.')
                st.insert(curr);
        }
        
    }
    
    return true;
    
}

bool checkValidity(const vector<string> &board, int row, int col){
    
    return checkRow(board, row) && checkColumn(board, col) && checkBox(board, row - row%3, col - col%3);
    
}

int Solution::isValidSudoku(const vector<string> &board) {
    
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(!checkValidity(board, i, j))
                return 0;
        }
    }
    
    return 1;
    
}