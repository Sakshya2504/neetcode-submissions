// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         // for(int i=0;i<matrix.size();i++){
//         //     for(int j=0;j<matrix[0].size();j++){
//         //         if(matrix[i][j] == 0){
//         //             for(int k=0;k<matrix.size();k++){
//         //                     matrix[i][k] = 2;
//         //             }
//         //             for(int k=0;k<matrix[0].size();k++){
//         //                     matrix[k][j] = 2;
//         //             }
//         //         }
//         //     }
//         // }
//         // for(int i=0;i<matrix.size();i++){
//         //     for(int j=0;j<matrix[0].size();j++){
//         //         if(matrix[i][j] == 2){
//         //             matrix[i][j] = 0;
//         //         }
//         //     }
//         // }

//         queue<pair<int,int>> ans;
//         for(int i=0;i<matrix.size();i++){
//             for(int j=0;j<matrix[0].size();j++){
//                 if(matrix[i][j] == 0){
//                     ans.push({i,j});
//                 }
//             }
//         }
//         while(!ans.empty()){
//             pair<int,int> temp = ans.front();
//             ans.pop();
//             int first = temp.first;
//             int second = temp.second;
//             for(int k=0;k<matrix.size();k++){
//                 matrix[first][k] = 0;
//             }
//             for(int k=0;k<matrix[0].size();k++){
//                 matrix[k][second] = 0;
//             }
//         }
//     }
// };

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        bool firstRow = false;
        bool firstCol = false;

        // Check first row
        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0)
                firstRow = true;
        }

        // Check first column
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0)
                firstCol = true;
        }

        // Mark rows and columns
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Set marked rows to zero
        for (int i = 1; i < m; i++) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < n; j++)
                    matrix[i][j] = 0;
            }
        }

        // Set marked columns to zero
        for (int j = 1; j < n; j++) {
            if (matrix[0][j] == 0) {
                for (int i = 1; i < m; i++)
                    matrix[i][j] = 0;
            }
        }

        // First row
        if (firstRow) {
            for (int j = 0; j < n; j++)
                matrix[0][j] = 0;
        }

        // First column
        if (firstCol) {
            for (int i = 0; i < m; i++)
                matrix[i][0] = 0;
        }
    }
};
