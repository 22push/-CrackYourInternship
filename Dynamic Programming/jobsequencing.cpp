bool static comparison(Job a, Job b) {
         return (a.profit > b.profit);
      }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr,arr+n,comparison);
        int max1 = arr[0].dead;
        for(int i=0;i<n;i++){
            max1=max(max1,arr[i].dead);
        }
        int noofslot=0;
        int maxprof = 0;
        int slot[max1+1];
        for(int i=0;i<=max1;i++){
            slot[i]=-1;
        }
        for(int i=0;i<n;i++){
            for(int j=arr[i].dead;j>0;j--){
                if(slot[j]==-1){
                    noofslot++;
                    maxprof+=arr[i].profit;
                    slot[j]=arr[i].id;
                    break;
                }
            }
        }
        vector <int> ans;
        ans.push_back(noofslot);
        ans.push_back(maxprof);
        return ans ;
    }