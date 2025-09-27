/*
https://leetcode.com/problems/design-movie-rental-system/description/?envType=daily-question&envId=2025-09-21
*/

//TLE

class CustomComparator2 {
public:
    bool operator()(const vector<int>& A, const vector<int>& B) {
        if (A[2] == B[2]) {
            return A[0] < B[0];
        }
        return A[2] < B[2];
    }
};

class CustomComparator {
public:
    bool operator()(const pair<int, int>& A, const pair<int, int>& B) {
        if (A.first == B.first) return A.second < B.second;
        return A.first < B.first;
    }
};

class MovieRentingSystem {
public:
    multimap<int, pair<int, int>> mp;
    map<pair<int, int>, pair<int, int>> mp2;

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto &entr : entries) {
            int currshop = entr[0], currmovie = entr[1], currprice = entr[2];
            mp.insert({currshop, {currmovie, currprice}});
            mp2[{currshop, currmovie}] = {0, currprice};
        }
    }
    
    vector<int> search(int movie) {
        vector<pair<int, int>> tmpres;
        vector<int> fnres;
        for (auto &mpentries : mp) {
            int currshop = mpentries.first;
            int currmovie = mpentries.second.first;
            int currprice = mpentries.second.second;
            if (currmovie == movie && mp2[{currshop, currmovie}].first == 0) {
                tmpres.push_back({currprice, currshop});
            }
        }
        sort(tmpres.begin(), tmpres.end(), CustomComparator());
        for (auto &entries : tmpres) {
            fnres.push_back(entries.second);
            if(fnres.size()==5) break;
        }
        return fnres;
    }
    
    void rent(int shop, int movie) {
        int currprice = mp2[{shop, movie}].second;
        mp2[{shop, movie}] = {1, currprice};
    }
    
    void drop(int shop, int movie) {
        int currprice = mp2[{shop, movie}].second;
        mp2[{shop, movie}] = {0, currprice};
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> tmpres;
        vector<vector<int>> fnres;
        for (auto &mp2entries : mp2) {
            auto currpair = mp2entries.first;
            int currshop = currpair.first, currmovie = currpair.second, currprice = mp2entries.second.second;
            int isRented = mp2entries.second.first;
            if (isRented == 1) {
                tmpres.push_back({currshop, currmovie, currprice});
            }
        }
        sort(tmpres.begin(), tmpres.end(), CustomComparator2());
        for (auto &entries : tmpres) {
            fnres.push_back({entries[0], entries[1]});
            if(fnres.size()==5) break;
        }
        return fnres;
    }
};
