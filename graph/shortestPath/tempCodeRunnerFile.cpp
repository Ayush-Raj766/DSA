vector<vector<int>> matrix(n, vector<int>(n, 1e9));

        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            matrix[u][v] = w;
            matrix[v][u] = w;
        }
        for(int i = 0 ; i < n; i++){
            matrix[i][i] = 0;
        }

        for(int k = 0; k < n; k++){
            for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < n ; j++){
                    if(matrix[i][k] != 1e9 && matrix[k][j] != 1e9){
                        matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                    }
                }
            }
        }
        int ans = -1;
        int minCount = 1e9;
        for(int i = 0 ; i < n; i++){
            int count = 0;
            for(int j = 0 ; j < n; j++){
                if(matrix[i][j] <= distanceThreshold){
                    count++;
                }
            }
            if(count < minCount){
                minCount = count;
                ans = i;
            }
        }
        return ans;