
// Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

 

// Example 1:

// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2,2]
// Example 2:

// Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// Output: [4,9]
// Explanation: [9,4] is also accepted.
 

// Constraints:

// 1 <= nums1.length, nums2.length <= 1000
// 0 <= nums1[i], nums2[i] <= 1000
// int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    
// }
// This is LeetCode 350: Intersection of Two Arrays II.
// I’ll explain the logic first (viva-friendly) and then give you the correct C function.
// 🧠 Key Idea (Very Important)
// Each element should appear as many times as it appears in BOTH arrays.
// So we need to count frequency.
// Since constraints are small
// 0 <= nums[i] <= 1000
// 👉 Frequency array approach is best.

// 🔹 Step-by-Step Logic
// 1️⃣ Create a frequency array for nums1
// Count how many times each number appears.
// 2️⃣ Traverse nums2
// If frequency of that number in nums1 is > 0:
// Add it to result
// Decrease frequency (to avoid overcounting)
// 3️⃣ Return result array and its size
// ⏱ Time & Space Complexity
// Time: O(n + m)
// Space: O(1001) → constant space
// ✅ Correct C Code (Accepted)
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int freq[1001] = {0};   // frequency array
    int *result = (int*)malloc(sizeof(int) * (nums1Size < nums2Size ? nums1Size : nums2Size));
    
    *returnSize = 0;

    // Count frequency of nums1
    for(int i = 0; i < nums1Size; i++) {
        freq[nums1[i]]++;
    }

    // Find intersection using nums2
    for(int i = 0; i < nums2Size; i++) {
        if(freq[nums2[i]] > 0) {
            result[*returnSize] = nums2[i];
            (*returnSize)++;
            freq[nums2[i]]--;   // reduce count
        }
    }

    return result;
}
🧪 Dry Run (Example 1)
Input:
nums1 = [1,2,2,1]
nums2 = [2,2]
freq after nums1:
freq[1] = 2
freq[2] = 2
nums2 traversal:
2 → freq > 0 → add → freq becomes 1
2 → freq > 0 → add → freq becomes 0
Output:
[2, 2]
🧠 Viva Questions (Expected)
❓ Why frequency array?
Answer:
Because values are limited (0–1000), it gives fast lookup and optimal time.
❓ Why decrease frequency?
Answer:
To ensure each element appears only the minimum number of times present in both arrays.
❓ Can order be different?
Answer:
Yes, problem states result can be in any order.
❓ Alternative approach?
Answer:
Sort both arrays and use two pointers (O(n log n)).
🔥 One-Line Viva Answer
“I used a frequency array to count elements of the first array and then matched elements from the second array while decrementing the count to handle duplicates correctly.”
If you want:
🔹 Two-pointer (sorting) approach
🔹 Hash map approach
🔹 Very short exam version
🔹 Common mistakes in C
Just tell me 👍





int rows = matrixSize;
    int cols = matrixColSize[0];

    // Transposed matrix will have cols rows
    *returnSize = cols;

    // Allocate memory for column sizes array
    *returnColumnSizes = (int*)malloc(cols * sizeof(int));

    // Allocate memory for result matrix
    int** result = (int**)malloc(cols * sizeof(int*));

    for(int i = 0; i < cols; i++) {
        (*returnColumnSizes)[i] = rows;   // each row has 'rows' columns
        result[i] = (int*)malloc(rows * sizeof(int));
    }

    // Fill transpose
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }

    return result;