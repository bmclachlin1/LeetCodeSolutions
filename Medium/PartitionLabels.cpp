class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> partitionLengths;
        int lastIndexOf[26];
        
        // record last index of character in array
        for (int i = 0; i < S.size(); i++) {
            lastIndexOf[S[i] - 'a'] = i;            
        }
        
        int end;
        
        // loop through string and greedily assign partitions
        for (int i = 0; i < S.size(); i++) {
            end = lastIndexOf[S[i] - 'a'];
            int anchor = i;
            while (i < end) {
                end = max(end, lastIndexOf[S[i] - 'a']);
                i++;
            }
            partitionLengths.push_back(end - anchor + 1);
        }
        
        return partitionLengths;
    }
};