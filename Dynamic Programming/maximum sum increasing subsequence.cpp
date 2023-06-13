int maxSumIS(int arr[], int n)  
	{  
	    vector<int> ans(n);
	    ans[0] = arr[0];
	    for(int i=0;i<n;i++) {
	    	ans[i] = arr[i];
	        for(int j=0;j<i;j++) {
	            if(arr[i]>arr[j]) {
	                ans[i] = max(ans[i],ans[j] + arr[i]);
	            }
	            else if(arr[i] < arr[j]) {
	                ans[i] = arr[i];
	            }
	        }
	    }
	    int maxi =INT_MIN;
	    for (int i=0;i<n;i++) {
	        maxi = max(maxi, ans[i]);
	    }
	    return maxi;
	}