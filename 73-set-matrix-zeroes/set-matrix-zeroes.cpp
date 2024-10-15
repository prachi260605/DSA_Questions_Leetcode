class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        bool firstRowhas0 = 0;
        bool firstColhas0 = 0;
        
        //first row has 0 or not
        for(int i =0; i<row; i++){
            if(matrix[i][0] == 0){
                firstColhas0 = true;
            }
            
        }
        
        //first col has 0 or not
        for(int i =0; i<col; i++){
            if(matrix[0][i] == 0){
                firstRowhas0 = true;
            }
            
        }
        
        for(int i =1; i<row; i++){
            for(int j =1; j<col; j++){
                if(matrix[i][j] == 0){
                    matrix[0][j] =0;
                    matrix[i][0] =0;
                }
            }
        }
        
        for(int i =1; i<row; i++){
            for(int j =1; j<col; j++){
                if(matrix[0][j] == 0 || matrix[i][0] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        
        if(firstColhas0){
            for(int i =0; i<row; i++){
            matrix[i][0] = 0;
        }
        }
        
        if(firstRowhas0){
            for(int i =0; i<col; i++){
            matrix[0][i] = 0;
        }
        }
        
    }
};