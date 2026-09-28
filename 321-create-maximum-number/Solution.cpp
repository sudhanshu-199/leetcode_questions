class Solution {
public:
    vector<int> Subs(vector<int>&nums,int k){
        stack<int> st;// 9 1 2 6   2
        int drop=nums.size()-k;//0
        for(int x : nums){
            while(!st.empty() && st.top()<x && drop!=0){
                st.pop();
                drop--;
            }//  
            if(st.size() < k){
                st.push(x);//9 
            }
            else{
                drop--;
            }
        }
        vector<int> v(k);//[9,6]
        int i=k-1;
        while(!st.empty()){
           v[i]=st.top();
           st.pop();
           i--;
        }
     // 5 6     9 8 7
        return v;
    }
    vector<int> merge(vector<int>& A, vector<int>& B){
        vector<int> ans;
        int i = 0,j=0;
        while(i<A.size() && j<B.size()){
            if(A[i]<B[j]){
                ans.push_back(B[j]);
                j++;
            }
            else if(A[i]==B[j]){
             int ti = i, tj = j;
                while(ti<A.size() && tj<B.size() && A[ti]==B[tj]) ti++, tj++;

                if(tj==B.size()) ans.push_back(A[i]), i++;
                else if(ti<A.size() && A[ti]>B[tj]) ans.push_back(A[i]), i++;
                else ans.push_back(B[j]), j++;
            }
            else{
                ans.push_back(A[i]);
                i++;
            }
        }
        while(i<A.size()){
            ans.push_back(A[i]);
            i++;
        }
        while(j<B.size()){
            ans.push_back(B[j]);
            j++;
        }
        return ans;
    }
    bool greater(vector<int> cur,vector<int> ans){
        int i=0,j=0;
        while(i<cur.size() && cur[i]==ans[j]){
            i++;
            j++;
        }
        if(cur==ans)
        return true;

        return cur[i]>ans[j];
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ans(k,0);
        int a = max(0,k-(int)nums2.size());//0
        int b = min(k,(int)nums1.size());//5 4
        for(int i = a;i<=b;i++){
            int j = k - i;
            vector<int> A = Subs(nums1,i);
            vector<int> B = Subs(nums2,j);
            vector<int> cur = merge(A,B);
            for(auto i:cur){
                cout<<i<<" ";
            }
            cout<<endl;
            if(greater(cur,ans))
                ans=cur;
        }
        return ans;
    }
};