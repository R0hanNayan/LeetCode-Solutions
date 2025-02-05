class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int left = 0, right = s1.size() - 1;

        if(s1 == s2)    return true;

        while(s1[left] == s2[left])     left++;
        while(s1[right] == s2[right])   right--;

        swap(s1[left], s1[right]);

        return s1 == s2;
    }
};