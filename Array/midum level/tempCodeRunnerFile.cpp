 for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            swap(arr[i][j],arr[j][i]);
        }
    }

    for(int i = 0 ; i<n;i++){
        reverse(arr[i].begin() , arr[i].end());
    }