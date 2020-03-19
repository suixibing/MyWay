class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray)
    {
        if (rotateArray.empty())
            return 0;
        int left = 0, right = rotateArray.size() - 1, mid;
        while (left < right)
        {
            mid = left + (right - left) / 2;
            if (mid - 1 >= 0 && rotateArray[mid] < rotateArray[mid - 1])
                return rotateArray[mid];
            if (mid + 1 < rotateArray.size() && rotateArray[mid] > rotateArray[mid + 1])
                return rotateArray[mid + 1];
            if (rotateArray[left] < rotateArray[mid])
                left = mid;
            else
                right = mid;
        }
        return rotateArray[left];
    }
};