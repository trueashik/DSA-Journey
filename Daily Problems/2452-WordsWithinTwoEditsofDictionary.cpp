class Solution {
    // Here I have used Brute Force approach with TC O(n*m*k) and SC O(1)
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string>res;

        for(string& q : queries){
            for(string& d: dictionary){
                int k = 0;
                for(int i = 0; i < q.size(); i++){
                    if(q[i] != d[i]) k++;
                    if(k>2)break;
                }
                if(k<=2){
                    res.push_back(q);
                    break;
                }
            }
        }
        return res;
        
    }
};