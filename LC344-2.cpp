class Solution {
public:
    string reverseString(string s) {
        reverse(s.begin(), s.end()); 
        // void reverse(BidirectionalIterator first, BidirectionalIterator last);
        // Complexity: Linear in half the distance between first and last: Swaps elements.
        return s;
    }
};
