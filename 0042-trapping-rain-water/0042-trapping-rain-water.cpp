class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        vector<int> nge(n, -1);
       vector<int> pge(n, -1);
       stack<int> st1;
       stack<int> st2;
       for(int i = n - 1;i >= 0;i--) {
        while(!st1.empty() && h[st1.top()] < h[i]) st1.pop();
        if(st1.empty()) nge[i] = -1;
        else nge[i] = st1.top();
        st1.push(i);
       }
       for(int i = 0;i < n;i++) {
        while(!st2.empty() && h[st2.top()] <= h[i]) st2.pop();
        if(st2.empty()) pge[i] = -1;
        else pge[i] = st2.top();
        st2.push(i);
       }
       int sum = 0;
    for(int i = 0;i < n;i++) {
        if(nge[i] == -1 || pge[i] == -1) continue;
        int p = min(h[nge[i]], h[pge[i]]);
        sum += (p - h[i]) * (nge[i] - pge[i] - 1);
    }
    
    return sum; 

    }
};