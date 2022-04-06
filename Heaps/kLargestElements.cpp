vector<int> kLargest(int arr[], int n, int k) {
	    vector <int> ans;
	    make_heap(&arr[0], &arr[n-1]);
	    sort_heap(&arr[0], &arr[n-1]);
	    for(int i = n-k; i < n; i++)
	        ans.push_back(arr[i]);
        return ans;
	}