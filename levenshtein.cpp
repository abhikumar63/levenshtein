#include<iostream>
#include<string.h>
#include<math.h>
#include<algorithm>

int levenshtein(std::string word1, std::string word2){
    size_t size1 = word1.size();
    size_t size2 = word2.size();

    int **lev = new int*[size1+1];
    for(size_t i=0;i<size1+1;i++){
        lev[i] = new int[size2+1];
    }

    if(size1 == 0) 
        return size2;
    if(size2 == 0)
        return size1;

    for(size_t i = 0; i <= size1; i++){
        lev[i][0] = i;
    }
    for(size_t j = 0; j <= size2; j++){
        lev[0][j] = j;
    }

    for(size_t i = 1; i <= size1; i++){
        for(size_t j = 1; j <= size2; j++){
            int cost = (word1[i-1] == word2[j-1]) ? 0 : 1;

            lev[i][j] = std::min(std::min(lev[i - 1][j] + 1, lev[i][j - 1] + 1), lev[i - 1][j - 1] + cost);
        }
    }

    int levVal = lev[size1][size2];
    for(size_t i=0;i<size1+1;i++){
        delete[] lev[i];
    }

    delete[] lev;
    return levVal;
}

int main(){
    std::string s1 = "rat";
    std::string s2 = "bat";

    int ans = levenshtein(s1, s2);

    std::cout << ans <<"\n";
    std::cout << "Program Ran Successfully\n";

    return 0;
}