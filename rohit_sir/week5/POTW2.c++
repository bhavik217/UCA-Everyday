// Perform the following shift operations on a string:

// Right shift: Replace every letter with the successive letter of the English alphabet, where 'z' is replaced by 'a'. For example, "abc" can be right-shifted to "bcd" or "xyz" can be right-shifted to "yza".
// Left shift: Replace every letter with the preceding letter of the English alphabet, where 'a' is replaced by 'z'. For example, "bcd" can be left-shifted to "abc" or "yza" can be left-shifted to "xyz".

// We can keep shifting the string in both directions to form an endless shifting sequence.
// For example, shift "abc" to form the sequence: ... <-> "abc" <-> "bcd" <-> ... <-> "xyz" <-> "yza" <-> .... <-> "zab" <-> "abc" <-> …
// You are given an array of strings strings, group together all strings[i] that belong to the same shifting sequence. You may return the answer in any order.

// Example 1:
// Input: strings = ["abc","bcd","acef","xyz","az","ba","a","z"]
// Output: [["acef"],["a","z"],["abc","bcd","xyz"],["az","ba"]]

// Example 2:
// Input: strings = ["a"] Output: [["a"]]

// Constraints:
// 1 <= strings.length <= 200
// 1 <= strings[i].length <= 50
// strings[i] consists of lowercase English letters.



// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     int n;
//     cin>>n;

//     vector<string> arr(n);
//     for(int i=0; i<n; i++) cin>>arr[i];

//     vector<vector<string>> ans;

//     for(int i=0; i<n; i++){
//         if(arr[i] == "#") continue;

//         int size1 = arr[i].size();
//         int diff1 = 0;
//         for(int k = 1; k < size1; k++) diff1 += ((arr[i][k] - arr[i][k-1] + 26) % 26);

//         vector<string> temp;
//         temp.push_back(arr[i]);

//         for(int j = i+1; j < n; j++){

//             int size2 = arr[j].size();
//             int diff2 = 0;

//             if(size1 == size2){
//                 for(int l = 1; l < size2; l++){
//                     diff2 += ((arr[j][l] - arr[j][l-1] + 26) % 26);
//                 }
//                 if(diff1 == diff2){ 
//                     temp.push_back(arr[j]);
//                     arr[j] = "#";
//                 }
//             }
//         }
//         ans.push_back(temp);
//     }

//     cout<<endl;
//     for(int i = 0; i < ans.size(); i++){
//         for(int j = 0; j < ans[i].size(); j++){
//             for(int k = 0; k < ans[i][j].size(); k++){
//                 cout<<ans[i][j][k];
//             }
//             cout<<" ";
//         }
//         cout<<endl;
//     }
// }






// Also tried to convert above C++ code to C but getting wrong output idk why

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int main(){
//     int n;
//     scanf("%d", &n);

//     char **arr = (char **) malloc(n * sizeof(char *));

//     for(int i=0; i<n; i++){
//         arr[i] = (char *) malloc(51 * sizeof(char));
//         scanf("%s", arr[i]);
//     }

//     char ***ans = (char ***) malloc(n * sizeof(char **));
//     int ans_count = 0;
//     int *group_size = (int *)malloc(n * sizeof(int));


//     for(int i=0; i<n; i++){
//         if (strcmp(arr[i], "#") == 0) continue;

//         int size1 = 0;
//         int diff1 = 0;
//         for(int k = 1; k < size1; k++) diff1 += ((arr[i][k] - arr[i][k-1] + 26) % 26);

//         char **temp = (char **) malloc(50 * sizeof(char *));
//         int temp_count = 0;
//         temp[temp_count++] = arr[i];

//         for(int j = i+1; j < n; j++){
//             if (strcmp(arr[j], "#") == 0) continue;

//             int size2 = strlen(arr[j]);
//             int diff2 = 0;

//             if(size1 == size2){
//                 for(int l = 1; l < size2; l++){
//                     diff2 += ((arr[j][l] - arr[j][l-1] + 26) % 26);
//                 }
//                 if(diff1 == diff2){ 
//                     temp[temp_count++] = arr[j];
//                     strcpy(arr[j], "#");
//                 }
//             }
//         }
//         ans[ans_count] = (char **) malloc(temp_count * sizeof(char *));
//         for(int k = 0; k < temp_count; k++){
//             ans[ans_count][k] = temp[k];
//         }
//         group_size[ans_count] = temp_count;
//         ans_count++;

//         free(temp);
//     }

//     printf("\n");
//     for(int i = 0; i < ans_count; i++){
//         for(int j = 0; j < group_size[i]; j++){
//             printf("%s", ans[i][j]);
//         }
//         printf("\n");
//     }
// }